/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:20:02 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/22 19:43:50 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	fdf_read_files(int ac, char **av)
{
	t_fdf_config	*config;
	int				i;
	t_list			*list;
	t_fdf_window	*window;

	config = fdf_get_config(ac, av);
	ft_putendl("Exited config");
	ft_putnbr(config->window_count);
	i = 0;
	while (i < config->window_count)
	{
		config->current = i;
		window = config->windows[i];
		if (!(list = fdf_read_file(window->fd)))
			fdf_exit(-50);
		fdf_add_vertical_lines(list);
		fdf_load_frame(list, window);
		mlx_key_hook(mlx_get_window(i)->window, fdf_key_hook,
				window);
		i++;
	}
}
