/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_find_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:25:58 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 20:22:14 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit_find_space(int **shapes, char *grid, int count)
{
	int		pos[2];
	int		size;
	int		i;
	int		r;

	if (*shapes)
	{
		if (!(fillit_check_grid_density(grid)))
			return (-1);
		i = -1;
		size = (int)grid[0];
		while (++i < size * size)
			if (grid[i + 1] == '.')
			{
				pos[0] = i / size;
				pos[1] = i % size;
				if ((r = fillit_place_shape(shapes, grid, pos, count) == 1))
					return (1);
				else if (r == -1)
					return (0);
			}
		return (0);
	}
	return (1);
}
