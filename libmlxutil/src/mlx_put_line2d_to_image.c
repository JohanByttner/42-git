/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_line2d_to_image.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 00:35:18 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:50:47 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libmlxutil.h"

void	mlx_put_line2d_to_image(t_line *line, t_mlx_image *im,
			t_colour *colour)
{
	double		distance;
	double		sinv;
	double		cosv;
	t_point		p;

	distance = mlx_distance_points2d(line->start, line->end);
	mlx_copy_point2d(&p, line->start);
	cosv = (line->end->i - line->start->i) / distance;
	sinv = (line->end->j - line->start->j) / distance;
	while (distance-- >= 0)
	{
		p.j += sinv;
		p.i += cosv;
		mlx_put_point2d_to_image(&p, im, colour);
	}
	mlx_put_point2d_to_image(line->end, im, colour);
}
