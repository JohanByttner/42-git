#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char	*s;

	s = ft_memalloc(15);
	ft_strcat(s, "Hello World");
	printf("%s\n", s);
	return (0);
}
