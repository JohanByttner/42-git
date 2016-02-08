/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 23:21:14 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 19:56:20 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** We use pascal-style strings with a twist.
** The first char of the string represents the length of one
** size of the square. So the total usable length of the grid
** is size * size
*/

static inline char	*fillit_setup_grid(char *grid, char size, int num_figures)
{
	int		i;

	if (grid)
		free(grid);
	if (!(grid = ft_memalloc(sizeof(char) * (size * size + 2))))
		fillit_exit(-1);
	grid[0] = size;
	i = 0;
	while (i++ < size * size)
		grid[i] = '.';
	grid[size * size + 1] = size * size - num_figures;
	return (grid);
}

char				*fillit_solve_grid(int **shapes)
{
	char	*grid;
	char	size;
	int		num_figures;

	grid = 0;
	num_figures = 0;
	size = 0;
	while (shapes[num_figures])
		num_figures++;
	num_figures *= 4;
	while (size * size < num_figures)
		size++;
	grid = fillit_setup_grid(grid, size, num_figures);
	while (!(fillit_find_space(shapes, grid, 0)))
		grid = fillit_setup_grid(grid, ++size, num_figures);
	return (grid);
}
