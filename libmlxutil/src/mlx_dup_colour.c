/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_dup_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 20:24:57 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 20:28:21 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "libft.h"

t_colour	*mlx_dup_colour(t_colour *colour)
{
	t_colour	*res;

	if (!(res = ft_memalloc(sizeof(t_colour))))
		return (0);
	return (mlx_copy_colour(res, colour));
}
