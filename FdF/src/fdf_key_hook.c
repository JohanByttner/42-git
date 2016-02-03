/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:44:18 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 20:59:47 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define XK_MISCELLANY 0
#define XK_LATIN1 0
#include "fdf.h"

int	fdf_key_hook_two(int keycode, t_mlx_camera *camera)
{
	double		angle;

	angle = 0;
	if (keycode == XK_Z || keycode == XK_C)
	{
		angle = (keycode == XK_Z ? -FDF_ANGLE_STEP : FDF_ANGLE_STEP);
		mlx_rotatek_camera(camera, angle);
	}
	else if (keycode == XK_Q || keycode == XK_E)
	{
		angle = (keycode == XK_Q ? -FDF_ANGLE_STEP : FDF_ANGLE_STEP);
		mlx_rotatei_camera(camera, angle);
	}
	else
		return (0);
	return (1);
}

int	fdf_key_hook_one(int keycode, t_mlx_camera *camera)
{
	t_3dpoint		p;

	p = (t_3dpoint){ 0, 0, 0 };
	if (keycode == XK_A || keycode == XK_D)
	{
		p.i = (keycode == XK_A ? -FDF_MOVE_STEP : FDF_MOVE_STEP);
		mlx_translate_camera(camera, &p);
	}
	else if (keycode == XK_W || keycode == XK_S)
	{
		p.j = (keycode == XK_W ? -FDF_MOVE_STEP : FDF_MOVE_STEP);
		mlx_translate_camera(camera, &p);
	}
	else if (keycode == XK_PLUS || keycode == XK_MINUS)
	{
		p.k = (keycode == XK_PLUS ? FDF_MOVE_STEP : -FDF_MOVE_STEP);
		mlx_translate_camera(camera, &p);
	}
	else
		return fdf_key_hook_two(keycode, camera);
	return (1);
}

int	fdf_key_hook(int keycode, void *param)
{
	t_mlx_camera	*camera;

	if (!(camera = mlx_get_image(0)->world->camera))
		return (0);
	else if (keycode == XK_ESCAPE)
		fdf_exit(0 && param);
	else if (fdf_key_hook_one(keycode, camera))
	{
		ft_putstr("Rendering\n");
		fdf_render_frame();
	}
	return (0);
}
