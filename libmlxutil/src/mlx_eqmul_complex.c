/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqmul_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 21:14:41 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 13:20:24 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

inline t_complex	*mlx_eqmul_complex(t_complex *restrict res,
		t_complex *restrict c1, t_complex *restrict c2)
{
	res->i = c1->i * c2->i - c1->j * c2->j;
	res->j = c1->i * c2->j + c2->i * c1->j;
	return (res);
}
