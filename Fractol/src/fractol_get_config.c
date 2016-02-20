/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_get_config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 23:36:37 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 20:52:06 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "fractol.h"

t_fractol_config	*fractol_get_config(void)
{
	static t_fractol_config	config = { 0, {{ 0, 0, 0, 0 }} };

	return (&config);
}
