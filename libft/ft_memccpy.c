#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	UCHAR		*result;
	UCHAR		*dest_c;
	const UCHAR	*src_c;

	i = 0;
	dest_c = (UCHAR *)dest;
	src_c = (const UCHAR *)src;
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
