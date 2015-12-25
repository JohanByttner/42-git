/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:27:06 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/23 19:33:21 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libmlxutil.h"
#include "libft.h"

t_mlx_window	*mlx_set_window(int wd, int size_x, int size_y, char *title)
{
	t_mlx_handler	*handler;
	t_mlx_window	*window;

	if (wd < 0 || MLX_MAX_WINDOW_COUNT <= wd || !(handler = mlx_get_handler()))
		return (0);
	if (!(window = (handler->windows + wd)))
		if (!(window = ft_memalloc(sizeof(t_mlx_window))))
			return (0);
	if (!(window->window)
			|| (size_x != window->size_x || size_y != window->size_y)
			|| (title && !(ft_strcmp(title, window->title))))
	{
		window->size_x = size_x;
		window->size_y = size_y;
		free(window->title);
		window->title = ft_strdup(title);
		if (window->window)
			mlx_destroy_window(handler->init, window);
		window->window = mlx_new_window(handler->init, size_x, size_y, title);
		handler->windows[wd] = *window;
	}
	return (window);
}
