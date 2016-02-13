/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_place_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:24:15 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/13 15:00:13 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void	fillit_set_offset(int count, int pos[], int **shapes)
{
	if (!(count % 4))
	{
		pos[0] -= (*shapes)[0];
		pos[1] -= (*shapes)[1];
	}
}

static inline int	fillit_set_pos(int offs[], int pos[], int *shape, int size)
{
	offs[0] = pos[0] + shape[0];
	offs[1] = pos[1] + shape[1];
	if (offs[0] < 0 || size <= offs[0])
		return (0);
	else if (offs[1] < 0 || size <= offs[1])
		return (0);
	else
	{
		return (1);
	}
}

int					fillit_place_shape(int **shapes, char *grid, int pos[],
		int count)
{
	int		offs[2];
	int		grid_pos;
	int		r;

	fillit_set_offset(count, pos, shapes);
	if (fillit_set_pos(offs, pos, (*shapes) + (count % 4) * 2, (int)grid[0]))
	{
		grid_pos = 1 + offs[0] * (int)grid[0] + offs[1];
		if (grid[grid_pos] == '.')
		{
			grid[grid_pos] = 'A' + (count++ / 4);
			if (count % 4)
			{
				if ((r = fillit_place_shape(shapes, grid, pos, count)) == 1)
					return (1);
			}
			else if ((r = fillit_find_space(shapes + 1, grid, count)) == 1)
				return (1);
			grid[grid_pos] = '.';
		}
	}
	return (0);
}
