/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_point_eye_view_transform.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:37:27 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/14 23:53:50 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_3dpoint	*mlx_point_eye_view_transform(t_3dpoint *p, t_3dpoint *eye,
				t_3dpoint *up)
{
	t_3dpoint	*out;
	t_3dpoint	*w;
	t_3dpoint	*u;

	if (!(out = ft_memalloc(sizeof(t_3dpoint))))
		return (0);
	if (!(w = ft_memalloc
	
}
