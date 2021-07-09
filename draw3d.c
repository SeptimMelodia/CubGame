/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:38:43 by stune             #+#    #+#             */
/*   Updated: 2021/04/01 17:23:46 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flor_cel(t_data *vars, int cent_line, int start_x)
{
	int	cel;
	int	flo;
	int	j;

	cel = create_trgb(00, vars->elem.all_color->ce_r,
	vars->elem.all_color->ce_g, vars->elem.all_color->ce_b);
	flo = create_trgb(00, vars->elem.all_color->fl_r,
	vars->elem.all_color->fl_g, vars->elem.all_color->fl_b);
	if (start_x < vars->elem.r_x)
	{
		j = 0;
		while (j <= cent_line)
		{
			my_mlx_pixel_put(vars, start_x, j, cel);
			j++;
		}
		while (j < vars->elem.r_y)
		{
			my_mlx_pixel_put(vars, start_x, j, flo);
			j++;
		}
	}
}

void	all_math(t_data *vars, int start_x)
{
	t_dir	dir;
	double	start;
	double	end;
	int		h;

	start = 0;
	end = 0;
	if (vars->deg > 2 * M_PI)
		vars->deg -= 2 * M_PI;
	if (vars->deg < 0)
		vars->deg += 2 * M_PI;
	if (vars->per_x && vars->per_y)
	{
		start = vars->deg - M_PI / 6;
		end = vars->deg + M_PI / 6;
		start_x = vars->elem.r_x - 1;
		while (start_x >= 0)
		{
			dir = ray_dir(start);
			h = ray_casting(vars, &dir, start);
			draw3dwall(vars, h, start_x, start);
			start += M_PI / 3 / vars->elem.r_x;
			start_x--;
		}
	}
}

void	draw3dwall(t_data *vars, double h, int start_x, double start)
{
	int	ofs;

	vars->norm_wall = 0;
	vars->cent_line = vars->elem.r_y / 2;
	if (h > vars->elem.r_y)
	{
		ofs = h - vars->elem.r_y;
		vars->norm_wall = (ofs / 2);
		vars->start_row = 0;
		vars->end_row = (vars->cent_line + h / 2) - (ofs / 2);
	}
	else
	{
		vars->start_row = vars->cent_line - h / 2;
		vars->end_row = vars->cent_line + h / 2;
	}
	flor_cel(vars, vars->cent_line, start_x);
	get_param_sprite(vars);
	texture_mapping(vars, h, start, start_x);
	draw_sprite(vars, start_x);
}
