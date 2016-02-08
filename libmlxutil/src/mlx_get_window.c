/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:26:48 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 13:19:32 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** Get promise: Will always return a valid window ptr if mlx_set_window
** has returned successfully (in the most recent call)
*/

t_mlx_window	*mlx_get_window(int wd)
{
	t_mlx_handler	*handler;

	if (wd < 0 || MLX_MAX_WINDOW_COUNT <= wd)
		return (0);
	else if (!(handler = mlx_get_handler()))
		return (0);
	return (&(handler->windows[wd]));
}
