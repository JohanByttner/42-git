/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:26:30 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:49:10 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libmlxutil.h"

/*
** Get Promise: will never return null if successfully called once
** Only need to check null value for first call
*/

t_mlx_handler	*mlx_get_handler(void)
{
	static t_mlx_handler	handler = { 0, {{ 0, 0, 0, 0 }}, 0, 0 };

	if (!(handler.init))
	{
		if (!(handler.init = mlx_init()))
			return (0);
	}
	return (&handler);
}
