/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 22:41:59 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/01 23:00:33 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "libft.h"

t_3dline	*mlx_new_line(t_3dpoint *p1, t_3dpoint *p2)
{
	t_3dline	*line;

	line = malloc(sizeof(t_3dline));
	line->start = ft_memdup(p1, sizeof(*p1));
	line->end = ft_memdup(p2, sizeof(*p2));
	return (line);
}
