/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:17:17 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/19 13:49:35 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_val	*new_val(char *str)
{
	t_val	*value;
	char	**sides;

	value = (t_val *)malloc(sizeof(t_val));
	if (!value)
		msg_exit("Failed while trying to malloc <value>!");
	sides = ft_split(str, ',');
	printf("sides[0] |%s|\n", sides[0]);
	if (!sides)
		msg_exit("Failed while trying to malloc <sides>!");
	if (!ft_isnumber(sides[0], 10))
		msg_exit("Failed while trying to read the <map>1!");
	if (sides[1] && !ft_isnumber(sides[1], 16))
		msg_exit("Failed while trying to read the <map>2!");
	if (sides[1])
		value->color = ft_atoi_base(sides[1], 16);
	else
		value->color = -1;
	value->z = ft_atoi(sides[0]);
	value->next = NULL;
	fru_arr(sides);
	return (value);
}

static void	parse_line(char **splitted, t_val **buff, t_map *map)
{
	int	width;

	width = 0;
	while (*splitted)
	{
		push(buff, new_val(*(splitted++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		msg_exit("The width is not equal for all the map's lines!");
}

void	read_map(const int fd, t_val **buff, t_map *map)
{
	char	*line;
	char	**splitted;

	line = get_next_line(fd);
	if (!line)
		msg_exit("Faild while trying to read map! <No line> ");
	while (line)
	{
		splitted = ft_split(line, ' ');
		if (!splitted)
			msg_exit("Faild while trying to read map! <split line> ");
		parse_line(splitted, buff, map);
		fru_arr(splitted);
		ft_strdel(&line);
		line = get_next_line(fd);
		map->height++;
	}
	ft_strdel(&line);
	if (!(*buff))
		msg_exit("Faild while trying to read map! <No buff> ");
}
