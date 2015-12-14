/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:53:40 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/10 23:34:16 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_mlx_image		*mlx_get_image(int id)
{
	t_mlx_handler	*handler;

	if (id < 0)
		return (0);
	handler = mlx_get_handler();
	if (!(handler) || handler->image_count <= id)
		return (0);
	if (!(handler->images[id].image))
		return (0);
	return (&(handler->images[id]));
}
