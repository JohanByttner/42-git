/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:33:42 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/28 20:00:22 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*result;
	unsigned char		*dest_c;
	const unsigned char	*src_c;

	i = 0;
	dest_c = (unsigned char *)dest;
	src_c = (const unsigned char *)src;
	while (i < n && src_c[i] != c)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	if (i == n)
		result = 0;
	else
		result = dest_c + i + 1;
	return (result);
}
