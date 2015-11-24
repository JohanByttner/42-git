#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	UCHAR	ch;
	UCHAR	*smem;

	i = 0;
	ch = (unsigned char)c;
	smem = (unsigned char*)s;
	while (i < n)
	{
		smem[i] = ch;
	}
	return (s);
}
