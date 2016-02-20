/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_lline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:51:36 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:44:25 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

void	mlx_render_lline(t_list *lline, t_mlx_camera *camera,
			t_mlx_image *img)
{
	while (lline)
	{
		mlx_put_line_to_image((t_3dline *)(lline->content),
				camera, img);
		lline = lline->next;
	}
}
