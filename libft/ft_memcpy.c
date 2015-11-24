#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	UCHAR	*dest_c;
	UCHAR	*src_c;

	dest_c = (UCHAR *)dest;
	src_c = (UCHAR *)src;
	i = 0;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}
