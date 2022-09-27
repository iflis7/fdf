/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:29:19 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/17 15:39:49 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
	   int	mlx_loop_hook (fdf->mlx, int (*funct_ptr)(), void *param); */
int	main(int argc, char *argv[])
{
	int		fd;
	t_map	*map;
	t_val	*buff;
	t_fdf	*fdf;

	if (argc != 2)
		msg_exit("The program needs 2 args!\n👇Like👇\n./fdf <map.fdf>");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		msg_exit("Map file 🚫exist ❌pathname or ⛔️ permissions!\nPlease retry!");
	map = init_map();
	read_map(fd, &buff, map);
	fdf = init_fdf(map);
	stack_to_arrays(&buff, map);
	fdf->cam = init_cam(fdf);
	draw_on_win(fdf->map, fdf);
	set_controls(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
