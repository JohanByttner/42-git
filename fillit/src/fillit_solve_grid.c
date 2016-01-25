/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 23:21:14 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/25 14:39:45 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	fillit_set_pos(int offs[], int pos[], int *shape, int size)
{
	offs[0] = pos[0] + shape[0];
	offs[1] = pos[1] + shape[1];
	ft_putstr("Offs : "); ft_putnbr(offs[0]); ft_putchar('|'); ft_putnbr(offs[1]);
	ft_putstr(" size : "); ft_putnbr(size); ft_putstr("\n");
	if (offs[0] < 0 || size <= offs[0])
		return (0);
	else if (offs[1] < 0 || size <= offs[1])
		return (0);
	else
	{
		ft_putstr("Success!\n");
		return (1);
	}
}

int		fillit_place_shape(int **shapes, char *grid, int pos[], int count)
{
	int		offs[2];
	int		size;
	int		grid_pos;

	ft_putstr("Count :");
	ft_putnbr(count);
	ft_putchar('\n');
	size = (int)grid[0];
	if (!(count % 4))
	{
		pos[0] -= (*shapes)[0];
		pos[1] -= (*shapes)[1];
	}
	if (fillit_set_pos(offs, pos, (*shapes) + (count % 4) * 2, size))
	{
		grid_pos = 1 + offs[0] * size + offs[1];
		if (grid[grid_pos] == '.')
		{
			grid[grid_pos] = 'A' + count / 4;
			count++;
			if (count % 4)
			{
				ft_putstr("I am placing shape\n");
				if (fillit_place_shape(shapes, grid, pos, count))
					return (1);
				ft_putstr("I failed\n");
			}
			else
				if (fillit_find_space(shapes + 1, grid, count))
					return (1);
			grid[grid_pos] = '.';
		}
	}
	return (0);
}

int			fillit_find_space(int **shapes, char *grid, int count)
{
	int		pos[2];
	int		size;
	int		i;

	if (*shapes)
	{
		i = 0;
		size = (int)grid[0];
		while (i < size * size)
		{
			if (grid[i + 1] == '.')
			{
				ft_putstr("Placing");
				pos[0] = i / size;
				pos[1] = i % size;
				ft_putnbr(pos[0]);
				ft_putchar('|');
				ft_putnbr(pos[1]);
				ft_putchar('\n');
				if (fillit_place_shape(shapes, grid, pos, count))
					return (1);
			}
			i++;
		}
		return (0);
	}
	else
		return (1);
}

/*
** We use pascal-style strings with a twist.
** The first char of the string represents the length of one
** size of the square. So the total usable length of the grid
** is size * size
*/

char		*fillit_validate_grid(int **shapes)
{
	char	*grid;
	char	size;
	int		i;

	size = 2;
	grid = ft_memalloc(sizeof(char) * size * size + 1);
	grid[0] = size;
	while (!(fillit_find_space(shapes, grid, 0)))
	{
		size++;
		free(grid);
		grid = ft_memalloc(sizeof(char) * size * size + 1);
		i = 0;
		while (i < size * size)
		{
			grid[i + 1] = '.';
			i++;
		}
		grid[0] = size;
		ft_putnbr(size);
		ft_putstr(" Loop\n");
		//usleep(100000);
	}
	return (grid);
}
