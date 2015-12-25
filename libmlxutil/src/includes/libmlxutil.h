/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlxutil.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:21 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/25 17:49:53 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBMLXUTIL_H
# define FT_LIBMLXUTIL_H
# include <X11/keysymdef.h>
# include "libft.h"
# define MLX_MAX_WINDOW_COUNT 2
# define MLX_IMAGES_BUFF_SIZE 2
# define MLX_DEFAULT_CAMERA_MODE 2

typedef struct		s_fmatrix
{
	size_t			width;
	size_t			height;
	double			*value;
}					t_fmatrix;

typedef enum		e_camera_mode
{
	UNINITIALIZED = 0,
	MLX_CAMERA_CENTRIC = 1,
	MLX_WORLD_CENTRIC = 2,
}					t_camera_mode;

typedef struct		s_mlx_camera
{
	t_fmatrix		*ext_matrix;
	t_fmatrix		*int_matrix;
	t_camera_mode	mode;
	double			view_frustrum_start;
	double			view_frustrum_end;
	int				size_x;
	int				size_y;
	double			*pixel_render_depth;
	int				overwriting_render;
}					t_mlx_camera;

typedef struct		s_mlx_world
{
	t_list			*polygons;
	size_t			polygon_count;
	t_mlx_camera	*camera;
}					t_mlx_world;

typedef struct		s_mlx_image
{
	void			*image;
	int				size_x;
	int				size_y;
	int				size_line;
	int				endian;
	int				bits_per_pixel;
	char			*data;
	t_mlx_world		*world;
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

typedef struct		s_3dline
{
	t_3dpoint		*start;
	t_3dpoint		*end;
}					t_3dline;

typedef struct		s_line
{
	t_point			*start;
	t_point			*end;
}					t_line;

typedef struct		s_3dbasis
{
	t_3dpoint		n;
	t_3dpoint		l;
	t_3dpoint		m;
}					t_3dbasis;

typedef struct		s_colour
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	char			endian;
}					t_colour;

typedef t_colour	t_color;

/*
** Points can be freed directly with free
*/

t_3dpoint			*mlx_get_point(int i, int j, int k);

int					mlx_cmp_points(t_3dpoint *p1, t_3dpoint *p2);

t_point				*mlx_copy_point2d(t_point *copy, t_point *point);

double				mlx_distance_points2d(t_point *p1, t_point *p2);

t_mlx_handler		*mlx_get_handler(void);

t_mlx_window		*mlx_get_window(int wd);

t_mlx_window		*mlx_set_window(int wd, int size_x,
						int size_y, char *title);

t_mlx_image			*mlx_set_image(int id, int size_x, int size_y);

//int					mlx_draw_line(t_point *p1, t_point *p2, int id, int color);

t_mlx_camera		*mlx_new_camera(int focus, int size_x, int size_y);

int					mlx_camera_record_pixel_depth(t_fmatrix *pos,
						t_mlx_camera *camera);

t_fmatrix			*mlx_new_fmatrix(size_t width, size_t height);

t_fmatrix			*mlx_eqmul_fmatrix(t_fmatrix *res, t_fmatrix *a,
						t_fmatrix *b);

t_point				*mlx_eqfmatrix_to_point2d(t_point *p, t_fmatrix *m);

t_fmatrix			*mlx_eqpoint_to_fmatrix(t_fmatrix *m, t_3dpoint *p);

t_point				*mlx_eqget_point2d(t_point *res, t_3dpoint *input,
						t_mlx_camera *camera);

void				mlx_put_point_to_image(t_3dpoint *p, t_mlx_camera *c,
						t_mlx_image *im, t_colour *colour);

void				mlx_put_point2d_to_image(t_point *pt, t_mlx_image *im,
						t_colour *colour);

void				mlx_put_line_to_image(t_3dline *line, t_mlx_camera *c,
						t_mlx_image *im, t_colour *colour);

void				mlx_put_line2d_to_image(t_line *line, t_mlx_image *im,
						t_colour *colour);

void				mlx_set_image_pixel(t_mlx_image *im, t_colour *colour,
						size_t pixel);

int					mlx_get_colour_int(t_colour *colour, t_mlx_image *im);

#endif
