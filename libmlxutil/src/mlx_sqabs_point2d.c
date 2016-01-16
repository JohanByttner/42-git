/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_sqabs_point2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 22:43:15 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/15 22:58:39 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

double	mlx_sqabs_point2d(t_point *p)
{
	double	value;

	value = p->i * p->i;
	value += p->j * p->j;
	return (value);
}
