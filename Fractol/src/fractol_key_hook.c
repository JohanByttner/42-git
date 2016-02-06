/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:20:06 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 13:22:18 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sysexits.h>
#include "fractol.h"

void	fractol_key_hook(int keycode, void *param)
{
	if (keycode == XKC_ESCAPE && (param || 1))
		fractol_exit(0);
}
