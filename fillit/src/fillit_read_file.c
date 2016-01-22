/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:57:54 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/21 23:31:50 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fillit.h"

static int	fillit_parse_line(int i, int index, char *line, int *ptr)
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

static int	*fillit_read_figure(int fd, int **ptr)
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
		else if (r == 0 && i % 4 == 0)
		{
			ft_memdel((void **)ptr);
			return (0);
		}
		else if (r == 0)
			fillit_exit(-1);
		else if (ft_strlen(line) != 4)
			fillit_exit(-4);
		r = i + 4;
		while (i < r)
			index = fillit_parse_line(i++, index, line, *ptr);
		free(line);
	}
	if ((r = get_next_line(fd, &line) == -1) || ft_strlen(line) > 0)
		fillit_exit(-1);
	return (*ptr);
}

/*
** TODO: Fix edge case with last line
*/

int		**fillit_read_file(int fd)
{
	int		**ptr;
	size_t	ctr;

	if (!(ptr = ft_memalloc(sizeof(int *) * 27)))
		fillit_exit(-7);
	ctr = 0;
	while (ctr < 27)
	{
		if (!(fillit_read_figure(fd, ptr + ctr)))
			break ;
		ctr++;
	}
	if (fillit_read_figure(fd, ptr + ctr))
		fillit_exit(-1);
	return (ptr);
}
