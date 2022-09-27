/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixeling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:27:58 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/17 15:39:57 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	i;

	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->line_length);
		fdf->addr[i] = color;
		fdf->addr[++i] = color >> 8;
		fdf->addr[++i] = color >> 16;
	}
}

/*
** Draw background colors (Menu background + main background)
*/
static void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < MENU_WIDTH)
			image[i] = MENU_BACKGROUND;
		else
			image[i] = BACKGROUND;
		i++;
	}
}

/*
** Draw line from f (first) to s (second)
*/
static void	draw_line(t_pnt f, t_pnt s, t_fdf *fdf)
{
	t_pnt	range;
	t_pnt	sign;
	t_pnt	current;
	int		error[2];

	make_sign(&f, &s, &sign, &range);
	error[0] = range.x - range.y;
	current = f;
	error[1] = error[0] * 2;
	while (current.x != s.x || current.y != s.y)
	{
		put_pixel(fdf, current.x, current.y, get_color(current, f, s, range));
		if (error[1] > -range.y)
		{
			error[0] -= range.y;
			current.x += sign.x;
		}
		if (error[1] < range.x)
		{
			error[0] += range.x;
			current.y += sign.y;
		}
		error[1] = error[0] * 2;
	}
}

/* Print instructions */
static void	show_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 70, y += 20, COLOR_BLOOD, "Menu");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten z: </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis - 1(7)/3(9)");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Change Projection:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
}

void	draw_on_win(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	draw_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line(project(new_pnt(x, y, map), fdf), \
				project(new_pnt(x + 1, y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				draw_line(project(new_pnt(x, y, map), fdf), \
				project(new_pnt(x, 1 + y, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	show_menu(fdf);
}
