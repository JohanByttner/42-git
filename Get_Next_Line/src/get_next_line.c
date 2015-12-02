/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:18:45 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/02 15:19:46 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

static size_t	join_to_heap(t_list *heap, char buff[BUFF_SIZE], size_t r)
{
	char			*tmp;

	if (!(tmp = ft_memalloc(heap->content_size + r)))
		return (0);
	ft_memcpy(tmp + heap->content_size, buff, r);
	ft_memcpy(tmp, ((t_mem *)heap->content)->array, heap->content_size);
	free(((t_mem *)heap->content)->array);
	((t_mem *)heap->content)->array = tmp;
	heap->content_size += r;
	return (heap->content_size);
}

/*
** 0 = continue searching
** 1 = Found newline, copied.
** -1 = Error.
*/

static int		get_line_from_buffer(char **line, t_list *heap)
{
	char			*str;
	size_t			len;

	if (!(str = ft_memchr(((t_mem *)heap->content)->array, '\n',
			heap->content_size)))
		return (0);
	len = (str - (char *)((t_mem *)heap->content)->array) * sizeof(char);
	if (!(*line = ft_memalloc(len + sizeof(char))))
		return (-1);
	ft_memcpy(*line, ((t_mem *)heap->content)->array, len);
	heap->content_size -= (len + 1);
	if (!(ft_memmove(((t_mem *)heap->content)->array, str + 1,
			heap->content_size)))
		return (-1);
	return (1);
}

static int		read_data_from_fd(int fd, t_list *heap, char **line)
{
	char			buff[BUFF_SIZE];
	int				r;

	if ((r = get_line_from_buffer(line, heap)))
		return (r);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(join_to_heap(heap, buff, r)))
			return (-1);
		if ((r = get_line_from_buffer(line, heap)))
			return (r);
	}
	if (r == -1)
		return (-1);
	if (heap->content_size)
	{
		*line = ft_memalloc(heap->content_size + 1);
		ft_memcpy(*line, ((t_mem *)heap->content)->array, heap->content_size);
		return (1);
	}
	return (0);
}

/*
** Once we get a call, we want to find the heap where the current
** file descriptor's calls are stored.
** The first sizeof (int) bytes of the char pointer
** in the heap is a file descriptor integer
** The first three calls (null ptrs) signify heap errors.
** These should force an error exit condition.
** If the function does not find a file pointer, it returns
** a new item after appending it to the list.
*/

static t_list	*get_fd_ptr_from_heap(int fd, char **line, t_list **heap)
{
	t_list			*ptr;
	t_mem			mem;

	mem.fd = fd;
	mem.array = 0;
	if (!line)
		return (0);
	if (!(*heap))
	{
		if (!(*heap = ft_lstnew(&mem, sizeof(t_mem))))
			return (0);
		(*heap)->content_size = 0;
		return (*heap);
	}
	ptr = *heap;
	while (ptr && ptr->next)
	{
		if (((t_mem *)ptr->content)->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	if (!(ptr->next = ft_lstnew(&mem, sizeof(t_mem))))
		return (0);
	ptr->next->content_size = 0;
	return (ptr->next);
}

/*
** heap is cleaned up on EOF
*/

int				get_next_line(int fd, char **line)
{
	int				r;
	t_list			*ptr;
	static t_list	**heap = 0;
	t_list			*cleanup;

	if (!heap)
		heap = ft_memalloc(sizeof(t_list *));
	if (!(ptr = get_fd_ptr_from_heap(fd, line, heap)))
		return (-1);
	if ((r = read_data_from_fd(fd, ptr, line)))
		return (r);
	if (ptr == *heap)
		*heap = ptr->next;
	else
	{
		cleanup = *heap;
		while (cleanup && cleanup->next && cleanup->next != ptr)
			cleanup = cleanup->next;
		cleanup->next = ptr->next;
	}
	free(((t_mem *)ptr->content)->array);
	free(ptr->content);
	free(ptr);
	return (0);
}
