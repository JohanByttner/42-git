/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:24:36 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/22 18:46:26 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#if defined LINUX || defined __linux__
# include <X11/X.h>
#endif
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "libmlxutil.h"
#include "fdf.h"

int		main(int ac, char **av)
{
	int				fd;
	t_list			*list;
	t_mlx_handler	*handler;

	if (ac < 2)
		return (0);
	if (!((fd = open(av[1], O_RDONLY)) > 0))
		return (0);
	//if (!(list = fdf_read_file(fd)))
	//	return (0);
	//fdf_get_config(ac, av);
	ft_putstr("Opened file\n");
	//fdf_add_vertical_lines(list);
	//fdf_load_frame(list);
	fdf_read_files(ac, av);
	//mlx_key_hook(mlx_get_window(0)->window, fdf_key_hook, 0);
	if ((handler = mlx_get_handler()))
		mlx_loop(handler->init);
	return (0);
}
