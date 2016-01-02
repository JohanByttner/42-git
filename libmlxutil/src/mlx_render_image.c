/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:02:54 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 17:18:03 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** This function requires the world parameter of the image
** to be set and ready to use
*/

void	mlx_render_image(t_mlx_image *img)
{
	if (!(img) || !(img->world))
		return ;
	if (img->world->lline)
		mlx_render_lline(img->world->lline, img->world->camera, img);
	if (img->world->llline)
		mlx_renderl_lline(img->world->llline, img->world->camera, img);
}
