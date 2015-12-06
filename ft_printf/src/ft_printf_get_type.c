/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 20:50:17 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/05 21:14:45 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_detail.h"

static int	ft_printf_get_type_one(char **format, t_ft_printf_info *info)
{
	int		updated;

	updated = 1;
	if (**format == 'd')
		info->type = d;
	else if (**format == 'i')
		info->type = i;
	else if (**format == 'u')
		info->type = u;
	else if (**format == 'o')
		info->type = o;
	else if (**format == 'x')
		info->type = x;
	else if (**format == 'X')
		info->type = X;
	else if (**format == 'f')
		info->type = f;
	else if (**format == 'F')
		info->type = F;
	else if (**format == 'e')
		info->type = e;
	else if (**format == 'E')
		info->type = E;
	else
		updated = 0;
	return (updated);
	
}

static int	ft_printf_get_type_two(char **format, t_ft_printf_info *info)
{
	int		updated;

	updated = 1;
	if (**format == 'g')
		info->type = g;
	else if (**format == 'G')
		info->type = G;
	else if (**format == 'a')
		info->type = a;
	else if (**format == 'A')
		info->type = A;
	else if (**format == 'c')
		info->type = c;
	else if (**format == 's')
		info->type = s;
	else if (**format == 'p')
		info->type = p;
	else if (**format == 'n')
		info->type = n;
	else
		updated = 0;
	return (updated);
}

int		ft_printf_get_type(char **format, t_ft_printf_info *info)
{
	int		updated;

	updated = 1;
	if (**format == '%')
		info->type = percent;
	else if (ft_printf_get_type_one(format, info));
	else if (ft_printf_get_type_two(format, info));
	else
		updated = 0;
	if (updated)
		(*format)++;
	return (updated);
}
