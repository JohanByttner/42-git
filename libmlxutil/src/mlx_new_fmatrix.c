/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_fmatrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:43:41 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/23 23:57:58 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libmlxutil.h"

t_fmatrix	*mlx_new_fmatrix(size_t width, size_t height)
{
	t_fmatrix	*matrix;

	matrix = malloc(sizeof(t_fmatrix));
	matrix->width = width;
	matrix->height = height;
	matrix->value = ft_memalloc(sizeof(double) * width * height);
	return (matrix);
}
