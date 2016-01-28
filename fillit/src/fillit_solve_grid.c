/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 23:21:14 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/28 13:26:16 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit_check_grid_density(char *grid)
;/*{
	int		size;
	int		space;
	int		i;
	int		acc;

	size = (int)grid[0];
	space = (int)grid[1 + size * size];
	acc = 0;
	i = 0;
	while (i++ < size * size)
	{
		if (grid[i] != '.')
		{
			space -= acc;
			acc = 0;
		}
		else
			acc++;
		if (space < 0)
		{
			ft_putnbr(space);
			ft_putstr("size\n");
			return (0);
	}
	}
	return (1);
}*/

static inline int	fillit_set_pos(int offs[], int pos[], int *shape, int size)
{
	offs[0] = pos[0] + shape[0];
	offs[1] = pos[1] + shape[1];
	//ft_putstr("Offs : "); ft_putnbr(offs[0]); ft_putchar('|'); ft_putnbr(offs[1]);
	//ft_putstr(" size : "); ft_putnbr(size); ft_putstr("\n");
	if (offs[0] < 0 || size <= offs[0])
		return (0);
	else if (offs[1] < 0 || size <= offs[1])
		return (0);
	else
	{
		//ft_putstr("Success!\n");
		return (1);
	}
}

int		fillit_place_shape(int **shapes, char *grid, int pos[], int count)
{
	int		offs[2];
	int		size;
	int		grid_pos;
	int		r;

	//ft_putstr("Count :");
	//ft_putnbr(count);
	//ft_putchar('\n');
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
				//ft_putstr("I am placing shape\n");
				if ((r = fillit_place_shape(shapes, grid, pos, count)) == 1)
					return (1);
				//else if (r == -1)
				//	return (-1);
				//ft_putstr("I failed\n");
			}
			else
			{
				if ((r = fillit_find_space(shapes + 1, grid, count)) == 1)
					return (1);
				//else if (r == -1)
				//	return (-1);
			}
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
	int		r;

	if (*shapes)
	{
		if (!(fillit_check_grid_density(grid)))
			return (-1);
		i = 0;
		size = (int)grid[0];
		while (i < size * size)
		{
		/*ft_putstr("I ");
		ft_putnbr(i);
		ft_putchar('|');
		ft_putnbr(size);
		ft_putstr("\n");*/
			if (grid[i + 1] == '.')
			{
				pos[0] = i / size;
				pos[1] = i % size;
				if ((r = fillit_place_shape(shapes, grid, pos, count) == 1))
					return (1);
				else if (r == -1)
					return (0);
				else if (count == ('T' - 'A') * 4)
				{
					ft_putstr("\nMain printing grid\n");
					fillit_print_grid(grid);
					ft_putchar('\n');
				}
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
	int		num_figures;

	num_figures = 0;
	size = 0;
	while(shapes[num_figures])
		num_figures++;
	//num_figures--;
	num_figures *= 4;
	while (size * size < num_figures)
		size++;
	grid = ft_memalloc(sizeof(char) * (size * size + 2));
	grid[0] = size;
	i = 0;
	while (i++ < size * size)
		grid[i] = '.';
	grid[size * size + 1] = size * size - num_figures;
	ft_putnbr(size);
	while (!(fillit_find_space(shapes, grid, 0)))
	{
		ft_putstr("\nIncreasing size\n");
		size++;
		free(grid);
		grid = ft_memalloc(sizeof(char) * size * size + 2);
		i = 0;
		while (i++ < size * size)
			grid[i] = '.';
		grid[0] = size;
		grid[size * size + 1] = size * size - num_figures;
	}
	return (grid);
}
