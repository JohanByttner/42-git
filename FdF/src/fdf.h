/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:28:07 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/03 20:06:30 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define FDF_SCALING 10
# include "libft.h"
# include "libmlxutil.h"
# include <stdlib.h>
# include <unistd.h>
# define FDF_SCREEN_WIDTH 1000
# define FDF_SCREEN_HEIGHT 1000
# define FDF_CAMERA_FOCUS 1
# define FDF_MOVE_STEP 30
# define PI 3.14159265
# define FDF_ANGLE_STEP PI / 20.0

void	fdf_exit(int status);

//void	fdf_key_handler(int keycode, t_env env);

t_list	*fdf_read_file(int fd);

void	fdf_load_frame(t_list *llist);

void	fdf_render_frame(void);

int		fdf_key_hook(int keycode, void *param);

void	fdf_add_vertical_lines(t_list *llist);

#endif
