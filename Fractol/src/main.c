/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 23:53:02 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:15:49 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libmlxutil.h"
#include "fractol.h"

int		main(int ac, char **av)
{
	if (fractol_read_options(ac, av))
	{
		fractol_load_windows();
		if (mlx_get_handler())
			mlx_loop_hook(mlx_get_handler()->init, fractol_render_all, 0);
	}
	mlx_loop(mlx_get_handler()->init);
	return (0);
}
