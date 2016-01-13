/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:20:06 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/13 22:35:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sysexits.h>
#define XK_MISCELLANY 0
#include <X11/keysymdef.h>
#include "fractol.h"

void	fractol_key_hook(int keycode, void *param)
{
	if (keycode == XK_Escape && (param || 1))
		fractol_exit(0);
}
