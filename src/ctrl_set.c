/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:28:37 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/17 10:28:42 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Close window with 'X'
*/

int	close_win(void *param)
{
	(void)param;
	exit(0);
}

/*
** Connect functions-controllers to window
*/

void	set_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, close_win, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
}
