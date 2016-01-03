/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 18:36:12 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/03 18:41:39 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libmlxutil.h"
void	print_matrix(t_fmatrix *m)
{
	printf("\n");
	for (unsigned int i = 0; i < m->height; i++)
	{
		printf("[");
		for (unsigned int j = 0; j < m->width; j++)
		{
			printf("%10.3lf", m->value[i * m->width + j]);
		}
		printf("]\n");
	}
}
