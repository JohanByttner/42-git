/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:50:15 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/25 21:15:24 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** From the beginning out:
**     reflect
**     refract
**     accumulate lights
** There is of course a more advanced method to do this
** http://www.cs.virginia.edu/~gfx/Courses/2003/ImageSynthesis/
** papers/General%20Rendering%20Stuff/Bidirectional%20Path%20Tracing.pdf
** Would in that case ask for help.
*/

t_rtpixel	*rt_ray_trace(t_rtpixel *res, t_3dray *ray, t_rtworld *world,
		int depth)
{
	t_rtobj		*current;
	t_rtpixel	deep;
	t_rtray		out;

	if (depth > RT_MAX_DEPTH || !(current
				= rt_get_nearest_intersect(world->obj, ray)))
		return (0);
	rt_rtpixel_reset(&deep);
//	rt_rtpixel_add_fraction(res, rt_ray_trace(&deep, current->reflect(&out,
//					current), depth + 1), current->smoothness);
	rt_rtpixel_reset(&deep);
//	rt_rtpixel_add_fraction(res, rt_ray_trace(&deep, current->refract(&out,
//					current), depth + 1), 1 - current->opacity);
	rt_rtpixel_reset(&deep);
	rt_rtpixel_eqadd_fraction(res,
		rt_rtlight_eqacc(&deep, rt_ray_trace(&deep, current->normal(&out,
			current, depth + 1)), world), current->opacity);
}
