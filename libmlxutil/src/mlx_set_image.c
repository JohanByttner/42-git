/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:47:29 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/10 18:13:30 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "libft.h"
#include "libmlxutil.h"

t_mlx_image		*mlx_set_image(int id, int size_x, int size_y)
{
	t_mlx_handler	*handler;
	t_mlx_image		*image;

	if (!(handler = mlx_get_handler()))
		return (0);
	if (0 < id || handler->image_count + MLX_IMAGES_BUFF_SIZE <= id)
		return (0);
	else if (handler->image_count <= id)
	{
		handler->image_count += MLX_IMAGES_BUFF_SIZE;
		if (!(ft_memadjust((void**)&(handler->images), sizeof(t_mlx_image) *
				(handler->image_count - MLX_IMAGES_BUFF_SIZE),
				sizeof(t_mlx_image) * handler->image_count)))
			return (0);
	}
	image = &(handler->images[id]);
	if (image->image)
		mlx_destroy_image(handler->init, image->image);
	image->size_x = size_x;
	image->size_y = size_y;
	if (!(image->image = mlx_new_image(handler->init, size_x, size_y)))
		return (0);
	else
		return (image);
}
