/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 16:56:45 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 18:10:28 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libmlxutil.h"
#include "fdf.h"

/*
** This simply calls on frame one
*/

void	fdf_render_frame(void)
{
	t_mlx_image		*img;
	t_mlx_window	*window;

	if (!(window = mlx_get_window(0))
			|| !(img = mlx_get_image(0)))
		return ;
	mlx_clear_image(img);
	mlx_render_image(img);
	mlx_put_image_to_window(mlx_get_handler()->init, window->window,
			img->image, 0, 0);
}
