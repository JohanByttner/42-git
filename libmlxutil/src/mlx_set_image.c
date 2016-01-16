/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:47:29 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/10 12:57:33 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "libft.h"
#include "libmlxutil.h"

static int		mlx_static_load_image(t_mlx_image *image, int sx, int sy)
{
	t_mlx_handler	*handler;

	if (!(handler = mlx_get_handler()))
		return (0);
	if ((image) == 0)
		if (!(image = ft_memalloc(sizeof(t_mlx_image))))
			return (0);
	if (image->image)
		mlx_destroy_image(handler->init, image->image);
	image->size_x = sx;
	image->size_y = sy;
	if (!(image->image = mlx_new_image(handler->init, sx, sy)))
		return (0);
	image->data = mlx_get_data_addr(image->image, &(image->bits_per_pixel),
			&(image->size_line), &(image->endian));
	return (1);
}

t_mlx_image		*mlx_set_image(int id, int size_x, int size_y)
{
	t_mlx_handler	*handler;
	t_mlx_image		*image;

	if (!(handler = mlx_get_handler()))
		return (0);
	if (0 > id || handler->image_count + MLX_IMAGES_BUFF_SIZE <= id)
		return (0);
	else if (handler->image_count <= id)
	{
		handler->image_count += MLX_IMAGES_BUFF_SIZE;
		if (!(ft_memadjust((void**)&(handler->images), sizeof(t_mlx_image) *
				(handler->image_count - MLX_IMAGES_BUFF_SIZE),
				sizeof(t_mlx_image) * handler->image_count)))
			return (0);
	}
	image = handler->images + id;
	if (mlx_static_load_image(image, size_x, size_y))
		return (image);
	else
		return (0);
}
