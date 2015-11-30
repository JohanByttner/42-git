/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:18:45 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/29 21:18:23 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

static size_t	join_strings(char **s_mem, char *buff, size_t r)
{
	char	*tmp;

	buff[r] = '\0';
	if (!(*s_mem))
		*s_mem = ft_memalloc(sizeof(char));
	if (!(tmp = ft_strjoin(*s_mem, buff)))
		return (0);
	free(*s_mem);
	*s_mem = tmp;
	return (ft_strlen(*s_mem));
}

static size_t	get_line_from_buffer(char **line, char **s_mem)
{
	char	*r;

	r = ft_strchr(*s_mem, '\n');
	if (!(r))
		return (0);
	*line = ft_strsub(*s_mem, 0, (size_t)(r - *s_mem));
		if (!(line))
			return (0);
	ft_memmove(*s_mem, r + 1, (size_t)(ft_strlen(*s_mem) - (size_t)(r - *s_mem)));
	return ((size_t)(r - *s_mem + 1));
}

int		get_next_line(int fd, char **line)
{
	long		r;
	char		buff[BUFF_SIZE + 1];
	static char	*s_mem = 0;

	if (!line)
		return (-1);
	if (s_mem && (r = get_line_from_buffer(line, &s_mem)))
		return (1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(join_strings(&s_mem, buff, r)))
			return (0);
		if (get_line_from_buffer(line, &s_mem))
			return (1);
	}
	if (r == -1)
		return (-1);
	if (s_mem && *s_mem)
	{
		*line = ft_strdup(s_mem);
		ft_strdel(&s_mem);
		return (1);
	}
	if (s_mem)
		ft_strdel(&s_mem);
	ft_strdel(line);
	return (0);
}
