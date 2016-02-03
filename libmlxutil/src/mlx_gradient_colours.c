/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_gradient_colours.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 20:09:55 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 20:13:55 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

inline t_colour	*mlx_gradient_colours(t_colour *res, t_colour *a, t_colour *b,
				double grade)
{
	res->red = (unsigned char)(a->red * (1 - grade) + b->red * grade);
	res->green = (unsigned char)(a->green * (1 - grade) + b->green * grade);
	res->blue = (unsigned char)(a->blue * (1 - grade) + b->blue * grade);
	return (res);
}
