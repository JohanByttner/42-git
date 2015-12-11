/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringtests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:43:14 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/29 01:04:37 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <bsd/string.h>
#include "libft.h"
#include "test.h"

/*
** All string functions are to be tested here. In alphabetical order
*/

char	*ok(int c)
{
	if (c)
		return "OK";
	else
		return "ERROR";
}


void	is_tests(char c)
{
	char	*pf;

	pf = "\n--- Test %s, result %s ---";
	printf(pf, "isalnum", ok(isalnum(c) == ft_isalnum(c)));
	printf(pf, "isalpha", ok(isalpha(c) == ft_isalpha(c)));
	printf(pf, "isascii", ok(isascii(c) == ft_isascii(c)));
	printf(pf, "isdigit", ok(isdigit(c) == ft_isdigit(c)));
	printf(pf, "islower", ok(islower(c) == ft_islower(c)));
	printf(pf, "isprint", ok(isprint(c) == ft_isprint(c)));
	printf(pf, "isupper", ok(isupper(c) == ft_isupper(c)));
	printf("\nIsUpper, %d|%d", ft_isupper(c), isupper(c));
}

void	destructive_string_tests(char *s1, char *s2, size_t len1)
{
	char	*s1t;
	char	*s2t;
	char	*s1f;
	char	*s2f;
	char	*pf;

	pf = "\n--- Test %s, result %s ---";
	s1t = ft_memalloc(len1);
	s2t = strdup(s2);
	s1f = ft_memalloc(len1);
	s2f = strdup(s2);
	printf(pf, "strcat", ok(!strcmp(ft_strcat(s1t, s2t), strcat(s1f, s2f))));
	printf("\n--- Results |%s| == |%s|, |%d|", s1t, s1f, strcmp(s1t, s1f));
	s1t = strdup(s1);
	ft_strclr(s1t);
	printf(pf, "strclr", ok(!memcmp(s1t, ft_memalloc(len1 + 1), len1 + 1)));
	printf("\n--- Results |%s| == ||", s1t);
	printf(pf, "strcpy", ok(!strcmp(ft_strcpy(s1t, s2t), strcpy(s1f, s2f))));
	printf("\n--- Results |%s| == |%s|", s1t, s1f);
	s1t = strdup(s1);
	printf(pf, "strdup", ok(!strcmp(ft_strdup(s1), strdup(s1))));
	ft_strdel(&s1t);
}

void	destructive_string_n_tests(char *s1, char *s2, size_t n)
{
	char	*s1t;
	char	*s2t;
	char	*s1f;
	char	*s2f;
	char	*pf;

	pf = "\n--- Test %s, result %s ---";
	s1t = strdup(s1);
	s2t = strdup(s2);
	s1f = strdup(s1);
	s2f = strdup(s2);
	printf(pf, "strncat", ok(!strcmp(ft_strncat(s1t, s2t, n),
			strncat(s1f, s2f, n))));
	printf("\n--- Results |%s| == |%s|, |%d|", s1t, s1f, strcmp(s1t, s1f));
	s1t = strdup(s1);
	s1f = strdup(s1);
	printf(pf, "strlcat", ok(ft_strlcat(s1t, s2t, n) == strlcat(s1f, s2f, n)));
	printf("\n--- Results |%s| == |%s|, |%d|", s1t, s1f, strcmp(s1t, s1f));
	s1t = strdup(s1);
	s2t = strdup(s2);
	printf(pf, "strncpy", ok(!strcmp(ft_strncpy(s1t, s2t, n), strncpy(s1f, s2f, n))));
	printf("\n--- Results |%s| == |%s|", s1t, s1f);
	s1t = strdup(s1);
	s2t = strdup(s2);
	printf(pf, "strlcpy", ok(ft_strlcpy(s1t, s2t, n) == strlcpy(s1f, s2f, n)));
	printf("\n--- Results |%s| == |%s|", s1t, s1f);
}

void	nondestructive_string_tests(char *s1, char *s2)
{
	char	*pf;

	pf = "\n--- Test %s, result %s ---";
	printf(pf, "atoi", ok(atoi(s1) == ft_atoi(s1)));
	printf(pf, "strchr", ok(ft_strchr(s1, 'c') == strchr(s1, 'c')));
	printf(pf, "strchr", ok(ft_strchr(s1, '\0') == strchr(s1, '\0')));
	printf(pf, "strchr", ok(ft_strchr(s1, 353) == strchr(s1, 353)));
	printf(pf, "strcmp", ok(!ft_strcmp(s1, s1)));
	printf(pf, "strcmp", ok(ft_strcmp(s1, s2) == strcmp(s1, s2)));
	printf(pf, "strlen", ok(ft_strlen(s1) == strlen(s1)));
	printf(pf, "strlen", ok(ft_strlen(s2) == strlen(s2)));
}

void	string_tests(char *s1, char *s2, size_t len1, size_t n)
{
	if (s1)
		is_tests(*s1);
	destructive_string_tests(s1, s2, len1);
	destructive_string_n_tests(s1, s2, n);
	nondestructive_string_tests(s1, s2);
}
