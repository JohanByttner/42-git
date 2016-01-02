/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_linec_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 16:31:33 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 16:36:39 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

void	mlx_put_linec_to_image(t_3dline *line, t_mlx_camera *camera,
			t_mlx_image *im)
{
	mlx_put_line_to_image(line, camera, im, line->colour);
}
