#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = *src;
	return (start);
}
