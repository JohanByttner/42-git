/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 17:18:59 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/23 18:10:47 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "libft.h"
#include <math.h>
#include <mlx.h>

void	fdf_key_hook(int k, void *p);

void	test_render(t_mlx_camera *camera)
{
	t_3dtrigon	trigon;
	t_3dpoint	centre = { -100, -100, 10 };
	t_3dpoint	left = { 10, 100, 10 };
	t_3dpoint	right = { 100, 10, 10 };
	trigon.centre = &centre;
	trigon.left = &left;
	trigon.right = &right;

	t_colour	colour = { 0, 255, 0, 0 };
	t_3dline	line = { 0 };
	t_3dpoint	start = { 0 };
	t_3dpoint	end = { 0 };
	t_3dpoint	point = { 0 };

	line.start = &start;
	line.end = &end;
	mlx_clear_image(mlx_get_image(0));
	t_point p;
	for (int i = 0; i < 1000; i++)
	{
		end.i = i - 500;
		p.i = i - 500;
		for (int j = 0; j < 1000; j++)
		{
			end.j = j - 500;
			end.k = 1;//= sqrt(end.j * end.j + end.i * end.i);
			p.j = j - 500;
			mlx_copy_point(&point, &end);
			if (mlx_eqget_ray_trigon_intersect(&point, &line, &trigon))
				mlx_put_point_to_image(&point, camera, mlx_get_image(0), &colour);
			//mlx_put_point2d_to_image(&p, mlx_get_image(0), &colour);
		}
	}
	mlx_put_image_to_window(mlx_get_handler()->init, mlx_get_window(0)->window,
		mlx_get_image(0)->image, 0, 0);
}

int		main(void)
{
	mlx_set_window(0, 1000, 1000, "Test");
	mlx_set_image(0, 1000, 1000);
	t_mlx_camera *camera = mlx_new_camera(1, 1000, 1000);
	mlx_new_world(camera, mlx_get_image(0));
	test_render(camera);
	mlx_key_hook(mlx_get_window(0)->window, fdf_key_hook, 0);
	mlx_loop(mlx_get_handler()->init);
	usleep(10000000);

}
