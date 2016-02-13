/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:57:54 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/13 14:56:42 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fillit.h"

static inline int	fillit_parse_line(int i, int index, char *line, int *ptr)
{
	if (line[i % 4] == '#')
	{
		if (index >= 8)
			fillit_exit(-6);
		ptr[index++] = i / 4;
		ptr[index++] = i % 4;
	}
	else if (line[i % 4] != '.')
		fillit_exit(-11);
	return (index);
}

static inline int	*fillit_read_figure(int fd, int **ptr)
{
	char	*line;
	int		i;
	int		r;
	int		index;

	if (!(*ptr = malloc(sizeof(int) * 8)))
		fillit_exit(-2);
	i = 0;
	index = 0;
	while (i < 16)
	{
		if ((r = get_next_line(fd, &line)) == -1)
			fillit_exit(-3);
		else if (r == 0 || ft_strlen(line) != 4)
			fillit_exit(101);
		r = i + 4;
		while (i < r)
			index = fillit_parse_line(i++, index, line, *ptr);
		ft_memdel((void **)&line);
	}
	if ((r = get_next_line(fd, &line) == 0))
		return (0);
	else if (r == -1 || ft_strlen(line) != 0)
		fillit_exit(-12);
	return (*ptr);
}

int					**fillit_read_file(int fd)
{
	int		**ptr;
	size_t	ctr;

	if (!(ptr = ft_memalloc(sizeof(int *) * 28)))
		fillit_exit(-7);
	ctr = 0;
	while (ctr < 26)
	{
		if ((fillit_read_figure(fd, ptr + ctr)) == 0)
			break ;
		ctr++;
	}
	if (ctr == 26)
		fillit_exit(-80);
	return (ptr);
}
