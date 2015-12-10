/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlxutil.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:21 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/10 18:06:07 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBMLXUTIL_H
# define FT_LIBMLXUTIL_H
# include <X11/keysymdef.h>
# define MLX_MAX_WINDOW_COUNT 1
# define MLX_IMAGES_BUFF_SIZE 2

typedef struct		s_mlx_image
{
	void			*image;
	int				size_x;
	int				size_y;
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

t_mlx_handler		*mlx_get_handler(void);

t_mlx_window		*mlx_get_window(int wd);

t_mlx_window		*mlx_set_window(int wd, int size_x,
						int size_y, char *title);

#endif
