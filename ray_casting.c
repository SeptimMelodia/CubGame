/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:22:23 by stune             #+#    #+#             */
/*   Updated: 2021/04/02 15:36:52 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dir			ray_dir(double start)
{
	t_dir	dir;

	dir.rayis_right = 0;
	dir.rayis_left = 0;
	dir.rayis_up = 0;
	dir.rayis_down = 0;
	if (cos(start) > 0)
		dir.rayis_right = 1;
	else if (cos(start) < 0)
		dir.rayis_left = 1;
	if (sin(start) > 0)
		dir.rayis_up = 1;
	else if (sin(start) < 0)
		dir.rayis_down = 1;
	return (dir);
}

static double	vertical_raycast(t_data *vars, double start, t_dir *dir)
{
	double	ray_xb;
	double	ray_yb;
	double	b;

	if (dir->rayis_right)
		ray_xb = (int)((vars->per_x) / 10) * 10 + 10;
	else
		ray_xb = (int)((vars->per_x) / 10) * 10 - 0.000000000001;
	ray_yb = (vars->per_y) + ((vars->per_x) - ray_xb) * tan(start);
	b = (10 * tan(start));
	b *= (dir->rayis_up && b > 0) ? -1 : 1;
	b *= (dir->rayis_down && b < 0) ? -1 : 1;
	while ((ray_yb / 10) >= 0 && (ray_yb / 10) <= vars->elem.max_map_y &&
	(ray_xb / 10) >= 0 && (ray_xb / 10) <= vars->elem.max_map_x &&
	vars->map[(int)(ray_yb / 10)][(int)(ray_xb / 10)] != '1'
	&& vars->map[(int)(ray_yb / 10)][(int)(ray_xb / 10)] != '\0')
	{
		ray_yb = ray_yb + b;
		if (dir->rayis_left)
			ray_xb = ray_xb - 10;
		else
			ray_xb = ray_xb + 10;
	}
	vars->ray.ver_ray_y = ray_yb;
	return (fabs((vars->per_x - ray_xb) / cos(start)));
}

static double	horizontal_raycast(t_data *vars, double start, t_dir *dir)
{
	double	ray_x;
	double	ray_y;
	double	a;

	if (dir->rayis_up)
		ray_y = floor((vars->per_y) / 10) * 10 - 0.000000000001;
	else
		ray_y = floor((vars->per_y) / 10) * 10 + 10;
	ray_x = (vars->per_x) + ((vars->per_y) - ray_y) / tan(start);
	a = (10 / tan(start));
	a *= (dir->rayis_left && a > 0) ? -1 : 1;
	a *= (dir->rayis_right && a < 0) ? -1 : 1;
	while ((ray_y / 10) >= 0 && (ray_y / 10) <= vars->elem.max_map_y &&
	(ray_x / 10) >= 0 && (ray_x / 10) <= vars->elem.max_map_x &&
	vars->map[(int)(ray_y / 10)][(int)(ray_x / 10)] != '1' &&
	vars->map[(int)(ray_y / 10)][(int)(ray_x / 10)] != '\0' &&
	vars->map[(int)(ray_y / 10)][(int)(ray_x / 10)] != ' ')
	{
		ray_x = ray_x + a;
		ray_y += (dir->rayis_up) ? -10 : 10;
	}
	vars->ray.hor_ray_x = ray_x;
	return (fabs((vars->per_y - ray_y) / sin(start)));
}

static int		height(t_data *vars, double start, double a, double b)
{
	int	h;

	h = (vars->elem.r_x / 2) / tan(M_PI / 6);
	if (a < b)
	{
		a *= cos(start - vars->deg);
		h = 10 / a * h;
		vars->ray.intersection = 1;
		vars->ray.distant = a;
	}
	else
	{
		b *= cos(start - vars->deg);
		h = 10 / b * h;
		vars->ray.intersection = 0;
		vars->ray.distant = b;
	}
	return (h);
}

int				ray_casting(t_data *vars, t_dir *dir, double start)
{
	int		h;
	double	a;
	double	b;

	a = 0;
	b = 0;
	h = 0;
	if (dir->rayis_left || dir->rayis_right)
		a = horizontal_raycast(vars, start, dir);
	if (dir->rayis_up || dir->rayis_down)
		b = vertical_raycast(vars, start, dir);
	if (b == 0)
		b = a;
	else if (a == 0)
		a = b;
	else
		h = height(vars, start, a, b);
	return (h);
}
