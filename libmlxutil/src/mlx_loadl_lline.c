/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loadl_lline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 14:36:17 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 16:22:53 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

int		mlx_loadl_lline(t_mlx_image *img, t_list *llist)
{
	if (img->world)
	{
		if (img->world->llline)
		{
			img->world->llline = llist;
			return (1);
		}
		img->world->llline = llist;
		return (0);
	}
	else
		return (-1);
}
