/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqmul_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 21:14:41 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/07 21:42:55 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_complex	*mlx_eqmul_complex(t_complex *res, t_complex *c1, t_complex *c2)
{
	res->i = c1->i * c2->i + c1->j * c2->j;
	res->j = c1->i * c2->j + c2->i * c1->j;
	return (res);
}
