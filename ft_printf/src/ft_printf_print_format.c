/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 21:14:56 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/05 21:28:00 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "ft_printf_detail.h"
#include "ft_putbuff.h"

/*
** This function supplies a malloc'd char string with the correct formatting.
** It is up to the implementation of ft_printf (ft_vfprintf, ft_snprintf etc)
** to decide how to use this information.
*/

char	*ft_printf_get_format(t_ft_printf_info &info, va_list ap)
{
	if (info->type == i || info->type == d)
		return (ft_printf_format_i(info, ap));
	else if (info->type == o)
		return (ft_printf_format_o(info, ap));
	else if (info->type == x || info->type == X)
		return (ft_printf_format_x(info, ap));
	else if (info->type == f || info->type == F)
		return (ft_printf_format_f(info, ap));
	else if (info->type == e || info->type == E)
		return (ft_printf_format_e(info, ap));
	else if (info->type == g || info->type == G)
		return (ft_printf_format_g(info, ap));
	else if (info->type == a || info->type == A)
		return (ft_printf_format_a(info, ap));
	else if (info->type == c)
		return (ft_printf_format_c(info, ap));
	else if (info->type == s)
		return (ft_printf_format_s(info, ap));
	else if (info->type == n)
		return (ft_printf_format_n(info, ap));
	else if (info->type == percent)
		return (ft_printf_format_percent(info, ap));
	else
		return 0;
}
