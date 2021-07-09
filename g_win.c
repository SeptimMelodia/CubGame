/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_win.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:21:57 by stune             #+#    #+#             */
/*   Updated: 2021/03/26 15:59:32 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	xclose(t_data *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	aclose(int keycode, t_data *vars)
{
	if (keycode == 0x35)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 0xd)
		move_forward(vars);
	if (keycode == 0x1)
		move_back(vars);
	if (keycode == 0x0)
		move_left(vars);
	if (keycode == 0x2)
		move_right(vars);
	if (keycode == 0x7b)
		vars->deg += M_PI / 60;
	if (keycode == 0x7c)
		vars->deg -= M_PI / 60;
	return (0);
}

int	all_all(t_data *vars)
{
	int	x;
	int start_x;

	start_x = 0;
	mlx_do_sync(vars->mlx);
	x = 0;
	minimapa(vars);
	all_math(vars, start_x);
	minimapa(vars);
	if (vars->elem.screen == 1)
		make_screenshot(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	g_win_test(t_elem *elem)
{
	t_data		vars;

	initialization_var(&vars, *elem);
	vars.mlx = mlx_init();
	screen_limits(&vars);
	vars.img = mlx_new_image(vars.mlx, vars.elem.r_x, vars.elem.r_y);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
				&vars.line_length, &vars.endian);
	if (vars.elem.screen != 1)
		vars.win = mlx_new_window(vars.mlx, vars.elem.r_x,
					vars.elem.r_y, "cub3D");
	open_texture(&vars);
	open_sprite(&vars);
	if (vars.elem.screen != 1)
	{
		mlx_hook(vars.win, 2, 1L << 0, aclose, &vars);
		mlx_hook(vars.win, 3, 1L << 1, aclose, &vars);
		mlx_hook(vars.win, 17, 1L << 17, xclose, &vars);
		mlx_loop_hook(vars.mlx, all_all, &vars);
		mlx_loop(vars.mlx);
	}
	else
		all_all(&vars);
	return (0);
}
