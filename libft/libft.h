#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define UCHAR unsigned char

/*
** All library includes should happen in the respective files.
** size_t is included from here
*/

/*
** The functions here follow the order in libft.pdf
*/

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strncpy(char *dest, const char *src, size_t n);

char	*ft_strcat(char *dest, const char *src);

char	*ft_strncat(char *dest, const char *src, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif
