/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_line_colours.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 20:28:29 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 20:35:22 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmlxutil.h"

t_3dline	*mlx_set_line_colours(t_3dline *line, t_colour *c1, t_colour *c2)
{
	if (!(line->colour = mlx_dup_colour(c1)))
		return (0);
	else if (!(line->colour2 = mlx_dup_colour(c2)))
	{
		free(c1);
		return (0);
	}
	else
		return (line);
}
