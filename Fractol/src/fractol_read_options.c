/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_read_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:57:26 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/11 20:24:40 by jbyttner         ###   ########.fr       */
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
	config->depth_julia = (t_colour){ 5, 9, 14, 0 };
	config->depth_mandelbrot = (t_colour) { 15, 0, 0, 0 };
}

int			fractol_read_options(int ac, char **av)
{
	t_fractol_config	*config;
	int					i;

	if (ac == 1)
		fractol_exit(EX_USAGE);
	i = 0;
	config = fractol_get_config();
	fractol_set_default_options(config);
	while (++i < ac)
	{
		if (!(ft_strcmp(av[i], "mandelbrot")))
			config->render_mandelbrot = 1;
		else if (!(ft_strcmp(av[i], "julia")))
			config->render_julia = 1;
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
