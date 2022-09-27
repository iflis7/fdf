/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:30:50 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/17 17:16:30 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* Add new coordinate to the front of the stack */
void	push(t_val **values, t_val *new)
{
	if (values)
	{
		if (new)
			new->next = values[0];
		values[0] = new;
	}
}

t_val	*pop(t_val **buff)
{
	t_val	*top;

	top = NULL;
	if (buff && *buff)
	{
		top = *buff;
		*buff = (*buff)->next;
	}
	return (top);
}

static void	check_min_max(int z, t_map *map)
{
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
}

void	stack_to_arrays(t_val **val_stack, t_map *map)
{
	size_t	i;
	t_val	*coord;

	map->val_arr = (int *)malloc(map->width * map->height * sizeof(int));
	if (!map->val_arr)
		msg_exit("Failed allocating memory ☠☠️☠️☠️☠️☠️\n");
	map->color_arr = (int *)malloc(map->width * map->height * sizeof(int));
	if (!map->color_arr)
		msg_exit("Failed allocating memory ☠☠️☠️☠️☠️☠️\n");
	i = map->width * map->height;
	coord = pop(val_stack);
	while (coord != NULL && i-- >= 0)
	{
		map->val_arr[i] = coord->z;
		map->color_arr[i] = coord->color;
		check_min_max(coord->z, map);
		free(coord);
		coord = pop(val_stack);
	}
	free(coord);
	map->z_range = map->z_max - map->z_min;
}
