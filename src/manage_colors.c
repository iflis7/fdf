/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:28:08 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/17 15:37:00 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* percent(z_min, z_max, z)
get the distance from the begening in % of each point */
double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

/* Get the a color depending on the placement of the point 0 */
int	get_def_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.3)
		return (COLOR_BLUE);
	else if (percentage < 0.6)
		return (COLOR_AZWAW);
	else
		return (COLOR_BLOOD);
}

/*
** Get light for color. Result depends on point position.
** This function is needed to create linear gradient.
*/
int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

/*
** Get color. Result depends on point position.
** This function is needed to create linear gradient.
*/
int	get_color(t_pnt current, t_pnt start, t_pnt end, t_pnt range)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (range.x > range.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, \
	(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, \
	(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
