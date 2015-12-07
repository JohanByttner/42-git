/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_signs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 20:33:58 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/07 21:34:48 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.n"
#include "ft_printf_detail.h"

/*
** Handle string to num conversion,
** # (flag hash), upper/lowercase and precision before
** calling this function.
** This function works for d, i, u, o, x, X, f, F, e, E, g, G, a, A
*/

static void	ft_printf_format_precision_d(t_ft_printf_info &info, char **str)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(*str);
	if (info->flags.hash && (info->type == o))
		len++;
	else if (info->flags.hash && (info->type == x || info->type == X))
		len += 2;
	//if (info->width > len && info->width >= info->precision)
	//	tmp = ft_memalloc(sizeof(char) * (info->width + 1));
	//else if (info->precision > len)
	//	tmp = ft_memalloc(sizeof(char) * (info->precision + 1));

}

void	ft_printf_format_signs(t_ft_printf_info &info, char **str)
{
	char	sign;
	char	*tmp;
	size_t	len;
	size_t	offset;

	sign = 0;
	len = ft_strlen(*str);
	if (**str != '-')
	{
		if (info->flags.plus)
			sign = '+';
		else if (info->flags.space)
			sign = ' ';
	}
	if (len + (sign && 1) < info->width)
	{
		if (!(tmp = ft_memalloc(sizeof(char) * (info->width + 1))))
			return ;
		ft_strset(tmp, (info->flags.zero && !(info->flags.minus)) ? '0' : ' ',
				sizeof(char) * info->width);
		offset = (info->flags.minus) ? info->width - len - (sign && 1) : 0;
		ft_strcpy(tmp + offset, sign, sizeof(char) * (sign && 1));
		ft_strcpy(tmp + (sign && 1) + offset, str, len);
	}
}
