/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cmp_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 23:16:09 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/15 23:17:23 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

int		mlx_cmp_colours(t_colour *c1, t_colour *c2)
{
	if (c1->red == c2->red
		&& c1->green == c2->green
		&& c2->blue == c2->blue
		&& c1->endian == c2->endian)
		return (1);
	else
		return (0);
}
