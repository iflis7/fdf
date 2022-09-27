/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:31:24 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/20 11:49:36 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* *-*-*-*-*  MINILIBX *-*-*-*-* */
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "keys_color.h"
# include "libft/libft.h"

/* Open, */
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

/* ***** TO DELETE ***** */
# include <ctype.h>

/* ***** MACROS ***** */
# define WIDTH 1920
# define HEIGHT 1080
# define MENU_WIDTH 300
# define MENU_HEIGHT 200

// # define WIDTH 800
// # define HEIGHT 650
// # define MENU_WIDTH 100
// # define MENU_HEIGHT 50

/* ***** STRUCTS ***** */
typedef enum s_project
{
	ISO,
	PARALLEL
}					t_project;

typedef struct s_map
{
	int				width;
	int				height;
	int				z_min;
	int				z_max;
	int				z_range;
	int				*val_arr;
	int				*color_arr;
}					t_map;

typedef struct s_val
{
	int				z;
	int				color;
	struct s_val	*next;
}					t_val;

typedef struct s_pnt
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pnt;

typedef struct s_cam
{
	t_project		project;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}					t_cam;

typedef struct s_mouse
{
	char			is_pressed;
	int				x;
	int				y;
	int				back_x;
	int				back_y;
}					t_mouse;

typedef struct s_fdf
{
	t_map			*map;
	void			*mlx;
	void			*win;
	t_cam			*cam;
	t_mouse			*mouse;

	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_fdf;

/* ***** UTILS.C ***** */
void				msg_exit(char *error);
void				fru_arr(char **arr);
void				ft_strdel(char **str);
t_pnt				new_pnt(int x, int y, t_map *map);
void				make_sign(t_pnt *f, t_pnt *s, t_pnt *sign, t_pnt *range);

/* ***** READ_UTILS.C ***** */
int					ft_isnumber(char *str, int base);
int					ft_atoi_base(const char *str, int base);

/* ***** INIT.C ***** */
t_map				*init_map(void);
t_fdf				*init_fdf(t_map *map);
t_cam				*init_cam(t_fdf *fdf);

/* ***** READ_MAP.C ***** */
void				read_map(const int fd, t_val **buff, t_map *map);
// int				read_map(const int fd, t_map *map);

/* ***** STACK_OPS.C ***** */
void				push(t_val **values, t_val *new);
t_val				*pop(t_val **buff);
void				stack_to_arrays(t_val **val_arr, t_map *map);

/* ***** PIXELING.C ***** */
void				draw_on_win(t_map *map, t_fdf *fdf);

/* ***** PROJECTION.C ***** */
t_pnt				project(t_pnt p, t_fdf *fdf);

/* ***** MANAGE_COLORS.C ***** */
int					get_def_color(int z, t_map *map);
int					get_light(int start, int end, double percentage);
int					get_color(t_pnt current, t_pnt start, t_pnt end,
						t_pnt range);

int					key_press(int key, void *param);

/* ***** CTRL_UTILS.C ***** */
void				zoom(int key, t_fdf *fdf);
void				move(int key, t_fdf *fdf);
void				rotate(int key, t_fdf *fdf);
void				flatten(int key, t_fdf *fdf);
void				change_projection(int key, t_fdf *fdf);

/* ***** CTRL_SET.C ***** */
int					close_win(void *param);
void				set_controls(t_fdf *fdf);

/* ***** KEYS_CTRL.C ***** */
int					mouse_press(int button, int x, int y, void *param);
int					mouse_release(int button, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);
int					key_press(int key, void *param);

#endif
