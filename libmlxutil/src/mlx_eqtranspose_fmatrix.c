/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqtranspose_fmatrix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 18:32:27 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:55:27 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

inline t_fmatrix	*mlx_eqtranspose_fmatrix(t_fmatrix *res,
		t_fmatrix *input)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < input->height)
	{
		j = 0;
		while (j < input->width)
		{
			res->value[j * input->width + i] = input->value[i
				* input->width + j];
			j++;
		}
		i++;
	}
	res->width = input->height;
	res->height = input->width;
	return (res);
}
