/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 16:53:02 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/04 00:18:47 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmlxutil.h"

t_colour	*mlx_new_colour(unsigned char red, unsigned char green,
				unsigned char blue, char endian)
{
	t_colour	*colour;

	if (!(colour = malloc(sizeof(t_colour))))
		return (0);
	colour->red = red;
	colour->green = green;
	colour->blue = blue;
	colour->endian = endian;
	return (colour);
}
