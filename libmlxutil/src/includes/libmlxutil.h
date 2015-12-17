/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlxutil.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:21 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/17 22:18:16 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBMLXUTIL_H
# define FT_LIBMLXUTIL_H
# include <X11/keysymdef.h>
# define MLX_MAX_WINDOW_COUNT 2
# define MLX_IMAGES_BUFF_SIZE 2

typedef struct		s_mlx_image
{
	void			*image;
	int				size_x;
	int				size_y;
	int				size_line;
	int				endian;
	int				bits_per_pixel;
}					t_mlx_image;

typedef struct		s_mlx_window
{
	void			*window;
	int				size_x;
	int				size_y;
	char			*title;
}					t_mlx_window;

typedef struct		s_mlx_handler
{
	void			*init;
	t_mlx_window	windows[MLX_MAX_WINDOW_COUNT];
	t_mlx_image		*images;
	int				image_count;
}					t_mlx_handler;

typedef struct		s_3dpoint
{
	double			i;
	double			j;
	double			k;
}					t_3dpoint;

typedef struct		s_point
{
	double			i;
	double			j;
}					t_point;

typedef double[16]	t_matrix_4x4;

typedef struct		s_3dbasis
{
	t_3dpoint		n;
	t_3dpoint		l;
	t_3dpoint		m;
}					t_3dbasis;

/*
** Points can be freed directly with free
*/

t_3dpoint			*mlx_get_3dpoint(int i, int j, int k);

int					mlx_cmp_3dpoints(t_3dpoint *p1, t_3dpoint *p2);

t_mlx_handler		*mlx_get_handler(void);

t_mlx_window		*mlx_get_window(int wd);

t_mlx_window		*mlx_set_window(int wd, int size_x,
						int size_y, char *title);

t_mlx_image			*mlx_set_image(int id, int size_x, int size_y);

int					mlx_draw_line(t_point *p1, t_point *p2, int id, int color);

#endif
