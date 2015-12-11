/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringtests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:43:14 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/27 23:34:41 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
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

void	stringtests(char *s1, char *s2, size_t len1, size_t len2)
{
	char	*s1t, *s2t;
	char	*s1f, *s2f;
	char	*pf = "\n---Test %s, result %s";

	s1t = strdup(s1);
	printf(pf, "isalnum", ok(isalnum(*s1t) == ft_isalnum(*s1t)));
	printf(pf, "isalpha", ok(isalpha(*s1t) == ft_isalpha(*s1t)));
	printf(pf, "isascii", ok(isascii(*s1t) == ft_isascii(*s1t)));
	printf(pf, "isdigit", ok(isdigit(*s1t) == ft_isdigit(*s1t)));
	printf(pf, "islower", ok(islower(*s1t) == ft_islower(*s1t)));
	printf(pf, "isprint", ok(isprint(*s1t) == ft_isprint(*s1t)));
	printf(pf, "islower", ok(isupper(*s1t) == ft_isupper(*s1t)));

	printf(pf, "atoi", ok(atoi(s1t) == ft_atoi(s1t)));

	s2t = strdup(s2);
	s1f = strdup(s1);
	s2f = strdup(s2);
	printf(pf, "strcat", ok(strcmp(ft_strcat(s1t, s2t), strcat(s1f, s2f))));

	s1t = strdup(s1);
	s2t = strdup(s2);
	s1f = strdup(s1);
	s2f = strdup(s2);
	printf(pf, "strchr", ok(ft_strchr(s1t, 'c') == strchr(s1t, 'c')));
	printf(pf, "strchr", ok(ft_strchr(s1t, '\0') == strchr(s1t, '\0')));
	printf(pf, "strchr", ok(ft_strchr(s1t, 354) == strchr(s1t, 354)));

	s1t = strdup(s1);
	s2t = strdup(s2);
	s1f = strdup(s1);
	s2f = strdup(s2);
	ft_strclr(s1t);
	printf(pf, "strclr", ok(memcmp(s1t, ft_memalloc(len1 + 1), len1 + 1)));

	s1t = strdup(s1);
	s2t = strdup(s2);
	s1f = strdup(s1);
	s2f = strdup(s2);
	printf(pf, "strcmp", ok(ft_strcmp(s1, s1)));
	printf(pf, "strcmp", ok(ft_strcmp(s1, s2) == strcmp(s1, s2)));

	s1t = strdup(s1);
	s2t = strdup(s2);
	s1f = strdup(s1);
	s2f = strdup(s2);
	printf(pf, "strcpy", ok(strcmp(ft_strcpy(s1t, s2t), strcpy(s1f, s2f))));

	s1t = strdup(s1);
	s2t = strdup(s2);
	s1f = strdup(s1);
	s2f = strdup(s2);
	ft_strdel(&s1t);
	ft_strdel(0);

	s1t = strdup(s1);
	s2t = strdup(s2);
	s1f = strdup(s1);
	s2f = strdup(s2);
	printf(pf, "strdup", ok(strcmp(ft_strdup(s1t), strdup(s1t))));

//	s1t = strdup(s1);
//	s2t = strdup(s2);
//	s1f = strdup(s1);
//	s2f = strdup(s2);
//	printf(pf, "strcpy", ok(strcmp(ft_strcpy(s1t, s2t), strcpy(s1f, s2f))));

	printf(pf, "strlen", ok(ft_strlen(s1) == len1));
	printf(pf, "strlen", ok(ft_strlen(s2) == len2));





}
