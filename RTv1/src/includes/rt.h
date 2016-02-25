/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:41:01 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/25 21:15:18 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include "libmlxutil.h"

typedef struct		s_3dplane
{
	t_3dpoint			p1;
	t_3dpoint			p2;
	t_3dpoint			p3;
}					t_plane;

typedef struct		s_3dsphere
{
	double				radius;
	t_3dpoint			centre;
}					t_3dsphere;

typedef union		u_3drtp
{
	t_3dplane			*plane;
	t_3dsphere			*sphere;
}					t_rtp;



/*
**   ~~ RT Ray ~~
*/

typedef struct		s_rttay
{
	t_3dpoint			start;
	t_3dpoint			end;
}					t_rtray;

/*
**   ~~ RT Object ~~
*/

typedef struct		s_rtobj
{
	double				opacity;
	double				smoothness;
	t_rtp				obj;
	t_3dpoint			*(*intersect)(t_3dpoint, t_3dray, struct s_rtobj);
	t_3dray				*(*reflect)(t_3dray, struct s_rtobj);
	t_3dray				*(*refract)(t_3dray, double, struct s_rtobj);
	t_3dray				*(*normal)(t_3dray, struct s_rtobj);
//	t_3dray				*(*shadow)(t_3d
	struct s_rtobj		*next;
	t_colour			colour;
}					t_rtobj;

// TODO:  Finish this prototype
t_rtobj				*rt_get_nearest_intersect(t_rtobj 

/*
**   ~~ RT Light ~~
*/

typedef struct		s_rtlight
{
	double				lumen;
	t_3dpoint			*centre;
	struct s_rtlight	*next;
}					t_rtlight;

typedef struct		s_rtworld
{
	t_rtobj			*obj;
	t_rtlight		*lights;
}					t_rtworld;

/*
**   ~~ RT Pixel ~~
**/

typedef struct		s_rtpixel
{
	double				depth_red;
	double				depth_green;
	double				depth_blue;
	double				lumen;
}					t_rtpixel;

t_rtpixel			*rt_rtlight_eqacc(t_rtpixel *deep, t_rtray *ray, t_rtworld *world);

t_rtpixel			*rt_rtlight_eqadd_fraction(t_rtpixel *res, t_rtpixel *deep,
		double fraction);

#endif
