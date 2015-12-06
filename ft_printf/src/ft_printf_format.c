/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:25:51 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/05 20:52:16 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_detail.h"

/*
** Flags seem to be permutable and non-exclusive. Flags can repeat.
** Flags can be alternating, "#+# +# +#+#" is a valid flag string.
*/

static void	ft_printf_get_flags(char **format, t_ft_printf_info *info)
{
	char			*flags;
	char			*it;

	flags = "-+ #0";
	it = *format;
	while ((it = ft_strchr(flags, *it)))
	{
		if (*it == '-')
			info->flags.minus = 1;
		else if (*it == '+')
			info->flags.plus = 1;
		else if (*it == '#')
			info->flags.hash = 1;
		else if (*it == ' ')
			info->flags.space = 1;
		else if (*it == '0')
			info->flags.zero = 1;
		it = ++(*format);
	}
}

/*
** This function can load up to one integer from ap.
** A negative entry indicates that the value hasn't been set.
*/

static int	ft_printf_get_widths(char **format, va_list ap)
{
	int				result;

	if (**format == '*')
	{
		result = va_arg(ap, int);
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		result = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else
		result = -1;
	return (result);
}

/*
** This function can load up to one integer from ap.
** A negative entry indicates that this value hasn't been set.
*/

static int	ft_printf_get_precision(char **format, va_list ap)
{
	int		result;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			result = va_arg(ap, int);
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			result = ft_atoi(++(*format));
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			result = 0;
	}
	else
		result = -1;
	return (result);
}

static void	ft_printf_get_length(char **format, t_ft_printf_info *info)
{
	info->length = ft_printf_length_none;
	if (**format == 'h')
	{
		info->length = h;
		if (*(++(*format)) == 'h')
			info->length = hh;
	}
	else if (**format == 'l')
	{
		info->length = l;
		if (*(++(*format)) == 'l')
			info->length = ll;
	}
	else if (**format == 'j')
		info->length = j;
	else if (**format == 'z')
		info->length = z;
	else if (**format == 't')
		info->length = t;
	else if (**format == 'L')
		info->length = L;
	if (info->length == ll || info->length == hh || info->length == j
			|| info->length == z || info->length == t || info->length == L)
		(*format)++;
}

char		*ft_printf_format(char **format, va_list ap)
{
	t_ft_printf_info	info;

	info = (t_ft_printf_info){ {0, 0, 0, 0, 0}, 0, 0, 0, 0 };
	ft_printf_get_flags(format, &info);
	info.width = ft_printf_get_widths(format, ap);
	info.precision = ft_printf_get_precision(format, ap);
	ft_printf_get_length(format, &info);
	ft_printf_get_type(format, &info);
	return (0);
}
