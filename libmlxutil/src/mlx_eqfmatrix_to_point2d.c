/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqfmatrix_to_point2d.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 01:31:23 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/16 18:32:30 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_point		*mlx_eqfmatrix_to_point2d(t_point *restrict p,
				t_fmatrix *restrict m)
{
	p->i = m->value[0];
	p->j = m->value[1];
	return (p);
}
