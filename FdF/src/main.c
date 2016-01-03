/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:24:36 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/03 20:07:00 by jbyttner         ###   ########.fr       */
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
	//t_list			*lines;
	/*t_mlx_window	*win;
	t_mlx_image		*img;
	t_mlx_camera	*cam;
	t_colour		col = {0, 255, 0, 0};
	t_3dpoint		p;*/

	if (ac != 2)
		return (0);
	if (!((fd = open(av[1], O_RDONLY)) > 0))
		return (0);
	if (!(list = fdf_read_file(fd)))
		return (0);
	ft_putstr("Opened file\n");
	fdf_add_vertical_lines(list);
	fdf_load_frame(list);
	mlx_key_hook(mlx_get_window(0)->window, fdf_key_hook, 0);
	mlx_loop(mlx_get_handler()->init);
	/*win = mlx_set_window(0, 1000, 1000, "title");
	img = mlx_set_image(0, 1000, 1000);
	cam = mlx_new_camera(10, 1000, 1000);
	p.i = -250; p.j = -250; p.k = 0;
	mlx_translate_camera(cam, &p);
	while (list)
	{
		lines = (t_list *)(list->content);
		while (lines)
		{
			mlx_put_line_to_image((t_3dline *)(lines->content),
			cam, img, &col);
			lines = lines->next;
		}
		list = list->next;
	}
	mlx_put_image_to_window(mlx_get_handler()->init, win->window, img->image,
		0, 0);
	usleep(10000000);
	//ft_strdup("Foo");
	//t_mlx_window *w = mlx_set_window(0, 1000, 1000, "New Window");
	*/
	//usleep(10000000);
	return (0);
}
