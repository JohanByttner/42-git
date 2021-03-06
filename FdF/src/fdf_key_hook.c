/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:44:18 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/23 15:08:49 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define XK_MISCELLANY 0
#define XK_LATIN1 0
#include "fdf.h"

int	fdf_key_hook_two(int keycode, t_mlx_camera *camera)
{
	double		angle;

	angle = 0;
	if (keycode == XKC_Z || keycode == XKC_C)
	{
		angle = (keycode == XKC_Z ? -FDF_ANGLE_STEP : FDF_ANGLE_STEP);
		mlx_rotatek_camera(camera, angle);
	}
	else if (keycode == XKC_Q || keycode == XKC_E)
	{
		angle = (keycode == XKC_Q ? -FDF_ANGLE_STEP : FDF_ANGLE_STEP);
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
	if (keycode == XKC_A || keycode == XKC_D)
	{
		p.i = (keycode == XKC_A ? -FDF_MOVE_STEP : FDF_MOVE_STEP);
		mlx_translate_camera(camera, &p);
	}
	else if (keycode == XKC_W || keycode == XKC_S)
	{
		p.j = (keycode == XKC_W ? -FDF_MOVE_STEP : FDF_MOVE_STEP);
		mlx_translate_camera(camera, &p);
	}
	else if (keycode == XKC_KP_ADD || keycode == XKC_KP_SUBTRACT)
	{
		p.k = (keycode == XKC_KP_ADD ? FDF_MOVE_STEP : -FDF_MOVE_STEP);
		mlx_translate_camera(camera, &p);
	}
	else
		return (fdf_key_hook_two(keycode, camera));
	return (1);
}

int	fdf_key_hook_camera(int keycode, t_fdf_window *window)
{
	t_mlx_camera	*camera;

	if (keycode == XKC_B)
		window->current_cam = 0;
	else if (keycode == XKC_N)
		window->current_cam = 1;
	else if (keycode == XKC_M)
		window->current_cam = 2;
	else
	{
		camera = window->cameras[window->current_cam];
		return (fdf_key_hook_one(keycode, camera));
	}
	return (1);
}

int	fdf_key_hook(int keycode, void *param)
{
	t_fdf_window	*window;

	window = (t_fdf_window *)param;
	if (keycode == XKC_ESCAPE)
		fdf_exit(0);
	else if (fdf_key_hook_camera(keycode, window))
	{
		mlx_get_image(window->wd)->world->camera = window->
			cameras[window->current_cam];
		ft_putstr("Rendering\n");
		fdf_render_frame(window->wd);
	}
	return (0);
}
