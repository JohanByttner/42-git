/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 14:24:02 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 14:34:10 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "libft.h"

/*
** The world is a bit of invisible "glue", to make rendering more
** straightforward. You can render a frame without even referring directly
** to the world, as it automatically inserts itself between the
** image and the camera.
*/

t_mlx_world		*mlx_new_world(t_mlx_camera *camera, t_mlx_image *img)
{
	t_mlx_world	*world;

	world = ft_memalloc(sizeof(t_mlx_world));
	world->camera = camera;
	if (img)
		img->world = world;
	return (world);
}
