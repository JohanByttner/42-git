/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:27:10 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/25 14:36:39 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		**ptr;
	int		i;

	if (argc == 2)
		if ((fd = open(argv[1], O_RDONLY)) >= 0)
		{
			ptr = fillit_read_file(fd);
			ft_putstr("\nNew String\n");
			fillit_print_grid(fillit_validate_grid(ptr));
			while (*ptr)
			{
				ft_putstr("\nptr\n");
				i = 0;
				while (i < 8)
				{
					ft_putnbr((*ptr)[i]);
					ft_putstr(" | ");
					i++;
				}
				ptr++;
				ft_putchar('\n');
			}
		}
	return (argc);
}
