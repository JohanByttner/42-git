/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_dup_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:08:03 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 11:40:55 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_3dpoint	*mlx_dup_point(t_3dpoint *point)
{
	t_3dpoint *dup;

	if (!(dup = ft_memalloc(sizeof(t_3dpoint))))
		return (0);
	return (mlx_copy_point(dup, point));
}
