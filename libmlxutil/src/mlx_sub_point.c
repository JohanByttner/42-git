/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_sub_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 00:36:15 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/17 12:20:40 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_3dpoint	*mlx_sub_point(t_3dpoint *a, t_3dpoint *b)
{
	t_3dpoint	*out;

	if (!(out = mlx_dup_point(a)))
		return (0);
	return (mlx_equsub_point(out, b));
}
