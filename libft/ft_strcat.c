#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	dest_length;
	size_t	i;

	dest_length = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest);
}
