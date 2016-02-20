/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 18:25:59 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 18:34:15 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** Copies points over to line. Does not assign line.
*/

t_3dline	*mlx_init_line(t_3dline *line, t_3dpoint *p1, t_3dpoint *p2)
{
	if (!(line->start = mlx_dup_point(p1)))
		return (0);
	if (!(line->end = mlx_dup_point(p2)))
	{
		free(line->start);
		line->start = 0;
		return (0);
	}
	return (line);
}
