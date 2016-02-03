/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:19:52 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 20:54:04 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

/*
** This function is intentionally made "nice"
** to account for the powerful rendering tools in
** libmlxutil. It will try to render any file with partially valid
** content, allowing for configuration mistakes
** (mistakes that are easier to find in the visual rendering anyway).
*/

static t_list	*fdf_read_row_line(char *s1, char *s2, int row, int index)
{
	t_3dpoint	p1;
	t_3dpoint	p2;
	t_3dline	*line;
	t_colour	*colour;

	p1.k = -ft_atoi(s1);
	p1.i = (index == -1 ? 0 : index * FDF_SCALING);
	p1.j = row * FDF_SCALING;
	p2.k = -ft_atoi(s2);
	p2.i = (index + 1) * FDF_SCALING;
	p2.j = row * FDF_SCALING;
	if (!(line = mlx_new_line(&p1, &p2)))
		return (0);
	if (!(line->colour = mlx_new_colour(0, (unsigned char)(-p1.k * 15 + 100), 0, -1))
		|| !(line->colour2 = mlx_new_colour(0, (unsigned char)(-p2.k * 15 + 100), 0, -1)))
		{
			free(line);
			return (0);
		}
	return (ft_lstnew(line, sizeof(*line)));
}

static void		fdf_read_row(char *line, int row, t_list **alst)
{
	char		*s1;
	char		*s2;
	char		**strp;
	int			index;

	strp = ft_strsplit(line, ' ');
	index = -1;
	if (!(strp) || !(s2 = *strp))
        ;
	else if (!(*(strp + 1)))
	{
		s1 = s2;
		ft_lstadd(alst, fdf_read_row_line(s1, s2, row, index));
		//free(s1);
	}
	else
		while (*(++strp))
		{
			s1 = s2;
			s2 = *strp;
			ft_lstadd(alst, fdf_read_row_line(s1, s2, row, ++index));
			//free(s1);
		}
	//free(s2);
	//free(strp);
}

/*
** Returns a list of lists
*/

t_list	*fdf_read_file(int fd)
{
	t_list	*tmp;
	t_list	*out;
	char	*line;
	int		row;

	row = 0;
	out = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		tmp = 0;
		fdf_read_row(line, row++, &tmp);
		if (tmp)
		{
			ft_lstadd(&out, ft_lstnew(tmp, sizeof(t_list)));
			////free(tmp);
		}
	}
	return (out);
}
