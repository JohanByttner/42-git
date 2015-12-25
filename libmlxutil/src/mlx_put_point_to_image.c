/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_point_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 17:14:20 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/23 23:22:13 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

void		mlx_put_point_to_image(t_3dpoint *p, t_mlx_camera *c,
				t_mlx_image *im, t_colour *colour)
{
	t_point		pt;

	if (mlx_eqget_point2d(&pt, p, c))
		mlx_put_point2d_to_image(&pt, im, colour);
}
