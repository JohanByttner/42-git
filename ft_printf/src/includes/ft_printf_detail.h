/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_detail.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 23:15:10 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/05 21:12:37 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DETAIL_H
# define FT_PRINTF_DETAIL_H
# include <stdarg.h>

/*
** This header is part of the internal representation of ft_printf.
** Include it anywhere else at your own risk.
*/

typedef struct	s_ft_printf_flags
{
	unsigned char			minus;
	unsigned char			plus;
	unsigned char			hash;
	unsigned char			space;
	unsigned char			zero;
}				t_ft_printf_flags;

typedef enum	e_ft_printf_lengths
{
	ft_printf_length_none,
	hh,
	h,
	l,
	ll,
	j,
	z,
	t,
	L
}				t_ft_printf_lengths;

typedef enum	e_ft_printf_types
{
	percent,
	d,
	i,
	u,
	o,
	x,
	X,
	f,
	F,
	e,
	E,
	g,
	G,
	a,
	A,
	c,
	s,
	p,
	n,
}				t_ft_printf_types;

typedef struct	s_ft_printf_info
{
	t_ft_printf_flags	flags;
	int					width;
	int					precision;
	t_ft_printf_lengths	length;
	t_ft_printf_types	type;
}				t_ft_printf_info;

char	*ft_printf_format(char **format, va_list ap);

int		ft_printf_get_type(char **format, t_ft_printf_info *info);

#endif
