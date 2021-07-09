/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimapa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:40:38 by stune             #+#    #+#             */
/*   Updated: 2021/04/01 17:52:19 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	contour(t_data *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < vars->elem.max_map_x * 10)
	{
		my_mlx_pixel_put(vars, x, 0, 0x00FF0000);
		x++;
	}
	y = 0;
	while (y < vars->elem.max_map_y * 10)
	{
		my_mlx_pixel_put(vars, vars->elem.max_map_x * 10, y, 0x00FF0000);
		y++;
	}
	x = 0;
	while (x < vars->elem.max_map_x * 10)
	{
		my_mlx_pixel_put(vars, x, vars->elem.max_map_y * 10, 0x00FF0000);
		x++;
	}
}

static void	draw_personage(t_data *vars)
{
	int	x;
	int	y;

	x = vars->per_x;
	while (vars->per_x - 10 < x)
	{
		y = vars->per_y;
		while (vars->per_y - 10 < y)
		{
			my_mlx_pixel_put(vars, x, y, 0x0091E8A2D);
			y--;
		}
		x--;
	}
}

void		minimapa(t_data *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < vars->elem.max_map_x * 10)
	{
		y = 0;
		while (y < vars->elem.max_map_y * 10)
		{
			my_mlx_pixel_put(vars, x, y, 0x00D7FAF0);
			y++;
		}
		x++;
	}
	contour(vars);
	ft_wall(vars);
	draw_personage(vars);
}
