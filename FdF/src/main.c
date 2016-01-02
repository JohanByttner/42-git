/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:24:36 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 02:13:10 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
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
	t_list			*lines;
	t_mlx_window	*win;
	t_mlx_image		*img;
	t_mlx_camera	*cam;
	t_colour		col = {0, 255, 0, 0};

	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) > 0)
		list = fdf_read_file(fd);
	ft_putstr("Opened file\n");
	win = mlx_set_window(0, 1000, 1000, "title");
	img = mlx_set_image(0, 1000, 1000);
	cam = mlx_new_camera(10, 1000, 1000);
	while (list)
	{
		lines = (t_list *)(list->content);
		while (lines)
		{
			mlx_put_line_to_image((t_3dline *)(lines->content),
			cam, img, &col);
		ft_putnbr((int)(((t_3dpoint *)(((t_3dline *)(lines->content))->start))->k));
		//	->k);
		ft_putchar('\n');
			lines = lines->next;
		}
		list = list->next;
	}
	mlx_put_image_to_window(mlx_get_handler()->init, win->window, img->image,
		0, 0);
	usleep(10000000);
	//ft_strdup("Foo");
	//t_mlx_window *w = mlx_set_window(0, 1000, 1000, "New Window");

	return (0);
}
