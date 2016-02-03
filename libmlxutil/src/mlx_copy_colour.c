/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_copy_colour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 20:15:02 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 20:20:18 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_colour	*mlx_copy_colour(t_colour *res, t_colour *colour)
{
	res->red = colour->red;
	res->green = colour->green;
	res->blue = colour->blue;
	return (res);
}
