/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_renderl_lline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 14:11:29 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 17:27:39 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

void	mlx_renderl_lline(t_list *llist, t_mlx_camera *camera,
			t_mlx_image *img)
{
	while (llist)
	{
		mlx_render_lline((t_list *)llist->content, camera, img);
		llist = llist->next;
	}
}
