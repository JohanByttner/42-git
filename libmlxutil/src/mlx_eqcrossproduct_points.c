#include "libft.h"
#include "libmlxutil.h"

/*
** a x b
** =
** | i  j  k |
** | a1 a2 a3|
** | b1 b2 b3|
*/

t_3dpoint	*mlx_eqcrossproduct_points(t_3dpoint *res, t_3dpoint *a,
				t_3dpoint *b)
{
	res->i = (a->j * b->k - a->k * b->j);
	res->j = (a->i * b->k - a->k * b->i);
	res->k = (a->i * b->j - a->j * b->i);
	return (res);
}
