#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		length;
	char	*res;
	int		i;

	length = ft_strlen(str);
	res = malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i <= length)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
