/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqsub_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:50:42 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/17 12:17:32 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** Returns pointer to 
*/

t_3dpoint	*mlx_eqsub_point(t_3dpoint *a, t_3dpoint *b)
{
	a->i -= b->i;
	a->j -= b->j;
	a->k -= b->k;
	return (a);
}
