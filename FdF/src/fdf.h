/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:28:07 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 01:16:50 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define FDF_SCALING 10
# include "libft.h"
# include "libmlxutil.h"
# include <stdlib.h>
# include <unistd.h>

//void	fdf_exit(int status);

//void	fdf_key_handler(int keycode, t_env env);

t_list	*fdf_read_file(int fd);

#endif
