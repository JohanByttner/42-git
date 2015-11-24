#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	i;

	dst_length = ft_strlen(dst);
	if (dst_length < size)
	{
		i = 0;
		while (dst_length + i < size && src[i] != '\0')
		{
			dst[dst_length + i] = src[i];
			i++;
		}
		dst[dst_length + i] = '\0';
	}
	return (dst_length + ft_strlen(src));
}
