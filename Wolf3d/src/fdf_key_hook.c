/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:44:18 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/23 18:09:09 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define XK_MISCELLANY 0
#define XK_LATIN1 0
#include <X11/keysymdef.h>
#include "libmlxutil.h"
#include "libft.h"
#define FDF_MOVE_STEP 30
#define FDF_ANGLE_STEP 0.15

/*
** Rotate camera
*/

static int	fdf_key_hook_three(int keycode, t_mlx_camera *camera)
{
	double			angle;

	if (keycode == XK_q || keycode == XK_e)
		angle = (keycode == XK_q ? -FDF_ANGLE_STEP : FDF_ANGLE_STEP);
	else
		angle = 0;
	mlx_rotatej_camera(camera, angle);
	ft_putstr("Rotating\n");
	return (0);
}

/*
** Translate camera
*/

static int	fdf_key_hook_two(int keycode, t_mlx_camera *camera)
{
	t_3dpoint		p = { 0, 0, 0 };

	ft_putstr("t2o");
	if (keycode == XK_a || keycode == XK_d)
		p.i = (keycode == XK_a ? -FDF_MOVE_STEP : FDF_MOVE_STEP);
	else if (keycode == XK_w || keycode == XK_s)
		p.j = (keycode == XK_w ? -FDF_MOVE_STEP : FDF_MOVE_STEP);
	else if (keycode == XK_KP_Add || keycode == XK_KP_Subtract)
		p.k = (keycode == XK_KP_Add ? FDF_MOVE_STEP : -FDF_MOVE_STEP);
	else
		return (fdf_key_hook_three(keycode, camera));
	ft_putnbr(XK_KP_Add);
	mlx_translate_camera(camera, &p);
	ft_putchar('c');
	return (0);
}

int			fdf_key_hook(int keycode, void *param)
{
	t_mlx_camera	*camera;

	ft_putstr("Registered key ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (!(camera = mlx_get_image(0)->world->camera))
		return (0);
	else if (keycode == XK_Escape)
		exit(0 && param);
	else
		fdf_key_hook_two(keycode, camera);
	test_render(camera);
	return (0);
}
