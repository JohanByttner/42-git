/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 18:24:48 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 18:31:44 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

void	mlx_clear_image(t_mlx_image *image)
{
	size_t			len;
	t_mlx_camera	*camera;

	len = image->size_line * image->size_y;
	ft_bzero(image->data, len);
	camera = image->world->camera;
	if (camera && camera->pixel_render_depth)
		ft_bzero(camera->pixel_render_depth, camera->size_x * camera->size_y
				* sizeof(double));
}
