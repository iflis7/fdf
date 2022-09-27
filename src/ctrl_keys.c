/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:28:22 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/17 15:39:35 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Handle mouse press
*/

int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = 1;
	return (0);
}

/*
** Handle mouse release
*/

int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = 0;
	return (0);
}

/*
** Handle mouse move
*/

int	mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->back_x = fdf->mouse->x;
	fdf->mouse->back_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->cam->beta += (x - fdf->mouse->back_x) * 0.002;
		fdf->cam->alpha += (y - fdf->mouse->back_y) * 0.002;
		draw_on_win(fdf->map, fdf);
	}
	return (0);
}

/*
** Handle key press
*/
int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS || key == NUM_PAD_MINUS
		|| key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_UP \
	|| key == ARROW_DOWN)
		move(key, fdf);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1 || key == NUM_PAD_2 \
	|| key == MAIN_PAD_2 || key == NUM_PAD_3 || key == MAIN_PAD_3 \
	|| key == NUM_PAD_4 || key == MAIN_PAD_4 || key == NUM_PAD_6 \
	|| key == MAIN_PAD_6 || key == NUM_PAD_7 || key == MAIN_PAD_7 \
	|| key == NUM_PAD_8 || key == MAIN_PAD_8 || key == NUM_PAD_9 \
	|| key == MAIN_PAD_9)
		rotate(key, fdf);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, fdf);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, fdf);
	return (0);
}
