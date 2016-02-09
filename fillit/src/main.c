/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:27:10 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/09 17:23:43 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		**ptr;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) >= 0)
		{
			ptr = fillit_read_file(fd);
			close(fd);
			fillit_validate_figures(ptr);
			fillit_print_grid(fillit_solve_grid(ptr));
		}
		else
			fillit_exit(-1);
	}
	else
		fillit_exit(-1);
	return (0);
}
