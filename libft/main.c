#include "libft.h"
#include "test.h"
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int		main(void)
{
/*	char	*s;
	char	*p1;
	char	*p2;
	int		psize;

	char	**split;

	s = "abcdefghijklmnop";
	split = ft_strsplit(s, ' ');
	psize = 100;
	p1 = ft_memalloc(psize);
	p2 = ft_memalloc(psize);
	ft_strlcpy(p1, s, psize);
	strlcpy(p2, s, psize);
	printf("Strlcpy of s, |%s| == |%s| is %d", p1, p2, 0); //strcmp(p1, p2));
	//printf("Sub of s, |%s|", ft_strsub(s, 0, 10));
	while (*split)
		printf("[%s]", *split++);
	//ft_strsplit("I a a s", ' ');
	printf("|%s|", ft_strtrim(s));
	return (0);
	s = ft_memalloc(15);
	ft_strcat(s, "Hello World");
	printf("%s\n", s);
	char	*s1, *s2;
	s1 = ft_memalloc(sizeof(char) * 21);
	s2 = ft_memalloc(sizeof(char) * 21);
	strcpy(s1, "Hello ");
	strcpy(s2, "World");
	string_tests(s1, s2, 20, 20);*/
	char *ptr;
	ptr = ft_itoa(0);
	ft_putstr(ptr);
	return (0);
}
