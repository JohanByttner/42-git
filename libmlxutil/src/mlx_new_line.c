/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 22:41:59 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 13:09:20 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "libft.h"

t_3dline	*mlx_new_line(t_3dpoint *p1, t_3dpoint *p2)
{
	t_3dline	*line;

	line = ft_memalloc(sizeof(t_3dline));
	line->start = mlx_dup_point(p1);
	line->end = mlx_dup_point(p2);
	return (line);
}
