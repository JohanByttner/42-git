/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_line_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 00:29:35 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/25 23:07:08 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** The current implementation will refuse to render a line
** if either of the two points are illegal
*/

void	mlx_put_line_to_image(t_3dline *line, t_mlx_camera *c,
			t_mlx_image *im, t_colour *colour)
{
	t_line	l2;
	t_point	p1;
	t_point	p2;

	if ((l2.start = mlx_eqget_point2d(&p1, line->start, c))
			&& (l2.end = mlx_eqget_point2d(&p2, line->end, c)))
		mlx_put_line2d_to_image(&l2, im, colour);
}
