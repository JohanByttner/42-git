/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_point_to_matrix_4x4.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:05:34 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/17 22:18:19 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_matrix_4x4	*mlx_put_point_to_matrix_4x4(t_matrix_4x4 m, t_3dpoint *p,
					int offset, int increment)
{
	m[offset] = p->i;
	m[offset + increment] = p->j;
	m[offset + 2 * increment] = p->k;
	return (m);
}
