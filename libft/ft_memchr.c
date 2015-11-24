#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	UCHAR	*result;

	i = 0;
	result = (UCHAR *)s;
	while (i < n && result[i] != c)
		i++;
	if (i == n)
		result = 0;
	return (result);
}
