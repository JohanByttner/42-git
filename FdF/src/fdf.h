/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:28:07 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:28:42 by jbyttner         ###   ########.fr       */
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
# include "libmlxutil.h"
# include "libft.h"
# define FDF_SCREEN_WIDTH 1000
# define FDF_SCREEN_HEIGHT 1000
# define FDF_CAMERA_FOCUS 1
# define FDF_MOVE_STEP 30
# define FDF_ANGLE_STEP M_PI / 20.0

void		fdf_exit(int status);

t_list		*fdf_read_file(int fd);

void		fdf_load_frame(t_list *llist);

void		fdf_render_frame(void);

int			fdf_key_hook(int keycode, void *param);

void		fdf_add_vertical_lines(t_list *llist);

t_colour	*fdf_new_colour(t_3dpoint *point);

#endif
