/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_validate_figures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:04:21 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 15:52:38 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static inline int		fillit_validate_figure(int *ptr,
		int x, int y)
{
	int		count;
	int		i;

	if (x < 0 || 3 < x || y < 0 || 3 < y)
		return (0);
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (ptr[i * 2] == x && ptr[i * 2 + 1] == y)
		{
			ptr[i * 2] = -1;
			ptr[i * 2 + 1] = -1;
			count = 1 + (fillit_validate_figure(ptr, x + 1, y)
					+ fillit_validate_figure(ptr, x - 1, y)
					+ fillit_validate_figure(ptr, x, y + 1)
					+ fillit_validate_figure(ptr, x, y - 1));
		}
		i++;
	}
	return (count);
}

int						fillit_validate_figures(int **ptr)
{
	int		figure[8];

	while (*ptr)
	{
		ft_memcpy(figure, *ptr, sizeof(int) * 8);
		if (fillit_validate_figure(figure, figure[0], figure[1]) != 4)
			fillit_exit(-9);
		ptr++;
	}
	return (1);
}
