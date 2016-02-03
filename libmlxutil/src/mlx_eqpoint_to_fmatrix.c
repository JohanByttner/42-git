/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqpoint_to_fmatrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 01:29:15 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 18:48:20 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_fmatrix	*mlx_eqpoint_to_fmatrix(t_fmatrix *m, t_3dpoint *p)
{
	m->value[0] = p->i;
	m->value[1] = p->j;
	m->value[2] = p->k;
	m->value[3] = 1;
	m->width = 1;
	m->height = 3;
	return (m);
}
