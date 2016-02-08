/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_check_grid_density.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:28:55 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 20:06:23 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void		fillit_reset_grid(char *grid, int size)
{
	int		i;

	i = 0;
	while (i++ < size * size)
		if (grid[i] == '%')
			grid[i] = '.';
}

static int				fillit_expand_grid(char *grid, int start, int size)
{
	int		acc;
	int		tmp;

	acc = 0;
	if (!(start > size * size) && grid[start] == '.')
	{
		acc = 1;
		grid[start] = '%';
		tmp = 0;
		if ((start) % size)
		{
			tmp = fillit_expand_grid(grid, start + 1, size);
			acc += tmp;
		}
		tmp = fillit_expand_grid(grid, start + size, size);
		acc += tmp;
		if ((start - 1) % size)
		{
			tmp = fillit_expand_grid(grid, start - 1, size);
			acc += tmp;
		}
	}
	return (acc);
}

int						fillit_check_grid_density(char *grid)
{
	int		size[2];
	int		i;
	int		acc;

	size[0] = (int)grid[0];
	size[1] = (int)grid[1 + size[0] * size[0]];
	i = 0;
	while (i++ < size[0] * size[0])
	{
		if (grid[i] == '.')
		{
			if ((acc = fillit_expand_grid(grid, i, size[0])) == -1)
				continue ;
			if (acc >= 4)
				acc = 0;
			if ((size[1] -= acc) < 0)
			{
				fillit_reset_grid(grid, size[0]);
				return (0);
			}
		}
	}
	fillit_reset_grid(grid, size[0]);
	return (1);
}
