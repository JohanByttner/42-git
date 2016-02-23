/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_load_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:13:46 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/22 20:40:43 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "fdf.h"

void	fdf_load_frame(t_list *llist, t_fdf_window *wptr)
{
	t_mlx_image		*img;
	t_mlx_window	*window;
	t_mlx_camera	*camera;

	if (!(img = mlx_set_image(wptr->wd, wptr->size_x, wptr->size_y)))
		fdf_exit(-1);
	else if (!(window = mlx_set_window(wptr->wd, wptr->size_x, wptr->size_y,
			(char *)wptr->name)))
		fdf_exit(-2);
	else if (!(mlx_new_world(*wptr->cameras, img)))
		fdf_exit(-4);
	mlx_loadl_lline(img, llist);
	fdf_render_frame(wptr->wd);
}
