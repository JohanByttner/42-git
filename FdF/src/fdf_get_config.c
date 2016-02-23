/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:27:47 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/23 15:31:29 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx_camera		**fdf_init_cameras(t_fdf_window *wptr)
{
	t_mlx_camera		**cameras;
	int					i;
	t_3dpoint			p;

	p = (t_3dpoint){ 80, 80, -150 };
	if (!(cameras = malloc(sizeof(t_mlx_camera *) * FDF_NUM_CAMERAS)))
		fdf_exit(0);
	i = 0;
	while (i < FDF_NUM_CAMERAS)
	{
		if (!(cameras[i] = mlx_new_camera(FDF_CAMERA_FOCUS,
				wptr->size_x, wptr->size_y)))
			exit(-50);
		mlx_translate_camera(cameras[i], &p);
		i++;
	}
	wptr->current_cam = 0;
	return (cameras);
}

static void				fdf_get_screen_size(int argc, int *args,
		char **argv, t_fdf_window *wptr)
{
	int					size[2];

	size[0] = FDF_SCREEN_WIDTH;
	size[1] = FDF_SCREEN_HEIGHT;
	if (*args + 2 < argc
			&& !ft_strcmp(argv[*args], "--Screen")
			&& ft_strisdigit(argv[*args + 1])
			&& ft_strisdigit(argv[*args + 2]))
	{
		ft_putendl("Importing size arguments");
		size[0] = ft_atoi(argv[*args + 1]);
		size[1] = ft_atoi(argv[*args + 2]);
		*args += 3;
	}
	else if (*args + 2 < argc && !ft_strcmp(argv[*args], "--Screen"))
		ft_putendl("Error: incorrect size arguments. Using defaults");
	else
		ft_putendl("No size arguments. Using defaults");
	wptr->size_x = (FDF_SCREEN_MAX >= size[0]
			&& size[0] > 0 ? size[0] : FDF_SCREEN_WIDTH);
	wptr->size_y = (FDF_SCREEN_MAX >= size[1]
			&& size[1] > 0 ? size[1] : FDF_SCREEN_HEIGHT);
}

/*
** This is a bonus part (setting gradients), so we can use atof.
*/

static void				fdf_set_gradients(int argc, int *args, char **argv,
		t_fdf_window *wptr)
{
	wptr->red = (t_fdf_gradient){ 1.0, 0.0 };
	wptr->green = (t_fdf_gradient){ 15.0, 100.0 };
	wptr->blue = (t_fdf_gradient){ 1.0, 0.0 };
	while (*args + 2 < argc)
	{
		if (!(ft_strcmp(argv[*args], "--Red")))
		{
			wptr->red.mul = atof(argv[*args + 1]);
			wptr->red.cnst = atof(argv[*args + 2]);
		}
		else if (!(ft_strcmp(argv[*args], "--Green")))
		{
			wptr->green.mul = atof(argv[*args + 1]);
			wptr->green.cnst = atof(argv[*args + 2]);
		}
		else if (!(ft_strcmp(argv[*args], "--Blue")))
		{
			wptr->blue.mul = atof(argv[*args + 1]);
			wptr->blue.cnst = atof(argv[*args + 2]);
		}
		else
			break ;
		*args += 3;
	}
}

static t_fdf_window		*fdf_get_window(int argc, int *args,
		char **argv, int cnt)
{
	t_fdf_window		*wptr;
	char				*name;
	int					fd;

	if (!(fd = open(argv[*args], O_RDONLY)) > 0)
	{
		ft_putstr("Error: Invalid file name. File: ");
		ft_putendl(argv[*args]);
		return (0);
	}
	name = argv[(*args)++];
	if (!(wptr = malloc(sizeof(t_fdf_window))))
		fdf_exit(-50);
	fdf_get_screen_size(argc, args, argv, wptr);
	wptr->cameras = fdf_init_cameras(wptr);
	wptr->fd = fd;
	wptr->wd = cnt;
	wptr->num_cameras = 3;
	wptr->name = name;
	fdf_set_gradients(argc, args, argv, wptr);
	return (wptr);
}

t_fdf_config			*fdf_get_config(int argc, char **argv)
{
	static t_fdf_config	config;
	int					args;
	int					cnt;

	if ((args = 1) && argc == 0 && argv == 0)
		return (&config);
	config.current = 0;
	if (!(config.windows = malloc(sizeof(t_fdf_window *)
					* MLX_MAX_WINDOW_COUNT)))
		fdf_exit(-50);
	cnt = 0;
	while (args < argc && cnt < MLX_MAX_WINDOW_COUNT)
	{
		if (!(config.windows[cnt] = fdf_get_window(argc, &args, argv, cnt)))
			args++;
		else
			cnt++;
	}
	if ((config.window_count = cnt) == MLX_MAX_WINDOW_COUNT)
	{
		ft_putstr("Error: Too many windows, opening ");
		ft_putnbr(MLX_MAX_WINDOW_COUNT);
		ft_putchar('\n');
	}
	return (&config);
}
