/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 23:24:17 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/10 23:31:54 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libmlxutil.h"

int		mlx_draw_line(t_point *p1, t_point *p2, int id, int color)
{
	t_mlx_image	*image;

	if (!(image = mlx_get_image(id)))
		return (0);
	
}
