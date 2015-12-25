/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:26:30 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/23 19:25:18 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libmlxutil.h"

t_mlx_handler	*mlx_get_handler(void)
{
	static t_mlx_handler	handler = { 0 };

	if (!(handler.init))
	{
		if (!(handler.init = mlx_init()))
			return (0);
		handler.images = 0;
		handler.image_count = 0;
		ft_bzero(handler.windows,
			sizeof(t_mlx_window *) * MLX_MAX_WINDOW_COUNT);
	}
	return (&handler);
}
