/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:06:08 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:41:09 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sysexits.h>
#include <stdlib.h>
#include "libft.h"

static void	fractol_print_usage(void)
{
	ft_putstr("Usage :\n");
	ft_putstr("  (One of each)\n");
	ft_putstr("  mandelbrot      :  display Mandelbrot fractal on screen\n");
	ft_putstr("  julia           :  display Julia fractal on screen\n");
	ft_putstr("  ship            :  display Burning Ship fractal on screen\n");
	ft_putstr("--Resolution x y  :  change resolution ");
	ft_putstr("(default: 1000 X 1000). Affects all screens.\n");
	ft_putstr("fractol can be called with multiple arguments\n");
}

void		fractol_exit(int exit_code)
{
	if (exit_code == EX_USAGE)
		fractol_print_usage();
	exit(exit_code);
}
