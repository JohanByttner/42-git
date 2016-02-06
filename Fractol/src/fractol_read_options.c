/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_read_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:57:26 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 17:49:52 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reads the command line options from av[1]
** to av[ac - 1] and parses them.
** If a parameter is invalid, the program exits.
** If a valid option is specified multiple times,
** the program executes the option once only.
*/

/*
** <sysexits.h> is for exit code macros
*/

#include <sysexits.h>
#include "fractol.h"
#include "libmlxutil.h"

static void	fractol_set_default_options(t_fractol_config *config)
{
	config->screen_width = 1000;
	config->screen_height = 1000;
	config->depth_julia = (t_colour){ 2, 3, 5, 0 };
	config->depth_mandelbrot = (t_colour) { 15, 0, 0, 0 };
	config->centre_julia.radius = 2;
	config->centre_mandelbrot.radius = 2;
	config->complex_julia = (t_complex){ -0.70176, -0.3842 };
	config->depth_burning_ship = (t_colour){ 10, 9, 2, 0 };
	config->centre_burning_ship.radius = 2;
	config->complex_burning_ship = (t_complex) { 0.45, 0.5 };
}

int			fractol_read_options(int ac, char **av)
{
	t_fractol_config	*config;
	int					i;
	int					screen_count;

	if (ac == 1)
		fractol_exit(EX_USAGE);
	i = 0;
	screen_count = 1;
	config = fractol_get_config();
	fractol_set_default_options(config);
	while (++i < ac)
	{
		if (!(ft_strcmp(av[i], "mandelbrot")))
			config->render_mandelbrot = screen_count++;
		else if (!(ft_strcmp(av[i], "julia")))
			config->render_julia = screen_count++;
		else if (!(ft_strcmp(av[i], "ship")))
			config->render_burning_ship = screen_count++;
		else if (!(ft_strcmp(av[i], "--Resolution")))
		{
			if (i + 2 < ac && ft_strisdigit(av[i + 1])
				&& ft_strisdigit(av[i + 2]))
			{
				config->screen_width = ft_atoi(av[++i]);
				config->screen_height = ft_atoi(av[++i]);
			}
			else
				fractol_exit(EX_USAGE);
		}
		else
			fractol_exit(EX_USAGE);
	}
	return (ac);
}
