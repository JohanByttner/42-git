/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqfmatrix_to_point.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 23:32:58 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/25 23:35:33 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_3dpoint	*mlx_eqfmatrix_to_point(t_3dpoint *p, t_fmatrix *m)
{
	p->i = m->value[0];
	p->j = m->value[1];
	p->k = m->value[2];
	return (p);
}
