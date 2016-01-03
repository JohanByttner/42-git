/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_add_vertical_lines.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 19:47:05 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/03 20:31:46 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "fdf.h"
#include "libft.h"

static t_list	*fdf_add_vertical_line_pair(t_list *l1, t_list *l2)
{
	t_list		*lline;
	t_3dline	*line1;
	t_3dline	*line2;
	t_3dline	*line3;

	line1 = 0;
	line2 = 0;
	lline = 0;
	while (l1 && l2)
	{
		line1 = (t_3dline *)l1->content;
		line2 = (t_3dline *)l2->content;
		if ((line3 = mlx_new_line(line1->start, line2->start)))
		{
			if ((line3->colour = mlx_new_colour(0, 255, 0, 0)))
				ft_lstadd(&lline, ft_lstnew(line3, sizeof(*line3)));
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	if (line1 && line2)
		if ((line3 = mlx_new_line(line1->end, line2->end)))
			if ((line3->colour = mlx_new_colour(0, 255, 0, 0)))
				ft_lstadd(&lline, ft_lstnew(line3, sizeof(*line3)));
	return (lline);
}

void			fdf_add_vertical_lines(t_list *llist)
{
	t_list	*lline;
	t_list	*llist2;

	llist2 = 0;
	while (llist && llist->next)
	{
		lline = fdf_add_vertical_line_pair(
			(t_list *)llist->content, (t_list *)llist->next->content);
		llist = llist->next;
		ft_lstadd(&llist2, ft_lstnew(lline, sizeof(*lline)));
	}
	ft_lstmerge(llist, llist2);
}
