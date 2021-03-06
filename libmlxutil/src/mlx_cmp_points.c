/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cmp_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 23:19:41 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/23 17:12:56 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

int		mlx_cmp_points(t_3dpoint *p1, t_3dpoint *p2)
{
	if ((p1->i == p2->i
			&& p1->j == p1->j
			&& p1->k == p1->k))
		return (1);
	else
		return (0);
}
