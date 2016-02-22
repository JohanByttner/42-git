/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:28:07 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/22 19:33:47 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define FDF_SCALING 10
# include "libft.h"
# include "libmlxutil.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "libmlxutil.h"
# include "libft.h"
# define FDF_SCREEN_WIDTH 500
# define FDF_SCREEN_HEIGHT 1000
# define FDF_CAMERA_FOCUS 1
# define FDF_MOVE_STEP 30
# define FDF_ANGLE_STEP M_PI / 20.0
# define FDF_NUM_CAMERAS 3
# define FDF_SCREEN_MAX 2000

typedef struct		s_fdf_gradient
{
	double			mul;
	double			cnst;
}					t_fdf_gradient;

typedef struct		s_fdf_window
{
	int				fd;
	int				wd;
	int				size_x;
	int				size_y;
	int				num_cameras;
	t_mlx_camera	**cameras;
	const char		*name;
	t_fdf_gradient	red;
	t_fdf_gradient	green;
	t_fdf_gradient	blue;
}					t_fdf_window;

typedef struct		s_fdf_config
{
	int				window_count;
	int				current;
	t_fdf_window	**windows;
}					t_fdf_config;

void				fdf_exit(int status);

t_list				*fdf_read_file(int fd);

void				fdf_load_frame(t_list *llist, t_fdf_window *wptr);

void				fdf_render_frame(int wd);

int					fdf_key_hook(int keycode, void *param);

void				fdf_add_vertical_lines(t_list *llist);

t_colour			*fdf_new_colour(t_3dpoint *point);

t_fdf_config		*fdf_get_config(int argc, char **argv);

void				fdf_read_files(int argc, char **argv);

#endif
