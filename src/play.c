#include "../include/fdf.h"

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	draw_background(t_data *data)
{
	int	*image;
	int	i;

	ft_bzero(data->addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	image = (int *)(data->addr);
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

static void	show_menu(t_data *img)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = img->mlx;
	win = img->win;
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

int	main(void)
{
	// void	*mlx;
	// void	*mlx_win;
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0xFFF);
	draw_background(&img);
	show_menu(&img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
