/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:17:09 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/17 15:35:05 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		msg_exit("Something went wrong while initializating maps!");
	map->width = 0;
	map->height = 0;
	map->z_min = 0;
	map->z_max = 0;
	map->z_range = 0;
	map->val_arr = NULL;
	map->color_arr = NULL;
	return (map);
}

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		msg_exit("Failed while trying to initialize FDF!");
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		msg_exit("Failed while trying to initialize <fdf->mlx>!");
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	if (!fdf->win)
		msg_exit("Failed while trying to initialize <fdf->win>!");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		msg_exit("Failed while trying to initialize <fdf->img>!");
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->line_length), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		msg_exit("Failed while trying to initialize <fdf->mouse>!");
	return (fdf);
}

t_cam	*init_cam(t_fdf *fdf)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		msg_exit("Failed while trying to initialize the camera!");
	cam->zoom = ft_min((WIDTH - MENU_WIDTH) / fdf->map->width / 1.5, \
	(HEIGHT - MENU_HEIGHT) / fdf->map->height / 1.5);
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->z_divisor = 1;
	cam->x_offset = 0;
	cam->y_offset = 0;
	return (cam);
}
