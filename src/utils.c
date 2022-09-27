/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:31:06 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/17 15:37:36 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fru_arr(char **arr)
{
	while (*arr++)
		free(*arr);
}

void	msg_exit(char *error)
{
	write(2, "Exit: ", 7);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_strdel(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

/* Make a new point to draw */
t_pnt	new_pnt(int x, int y, t_map *map)
{
	t_pnt	pnt;
	int		index;

	index = (y * map->width + x);
	pnt.x = x;
	pnt.y = y;
	pnt.z = map->val_arr[index];
	if (map->color_arr[index] == -1)
		pnt.color = get_def_color(pnt.z, map);
	else
		pnt.color = map->color_arr[index];
	return (pnt);
}

/* Define the derction of drawing for pixeling */
void	make_sign(t_pnt *f, t_pnt *s, t_pnt *sign, t_pnt *range)
{
	range->x = ft_abs(s->x - f->x);
	range->y = ft_abs(s->y - f->y);
	if (f->x < s->x)
		sign->x = 1;
	else
		sign->x = -1;
	if (f->y < s->y)
		sign->y = 1;
	else
		sign->y = -1;
}
