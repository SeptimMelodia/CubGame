/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_not_drink.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:51:23 by stune             #+#    #+#             */
/*   Updated: 2021/04/02 15:38:44 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		spryte_sort(t_data *vars)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i < vars->elem.sprite_num)
	{
		if (vars->sprite[i + 1].dist_sp && vars->sprite[i].dist_sp <\
					vars->sprite[i + 1].dist_sp)
		{
			tmp = vars->sprite[i + 1];
			vars->sprite[i + 1] = vars->sprite[i];
			vars->sprite[i] = tmp;
			i = 0;
		}
		i++;
	}
}

void			draw_sprite(t_data *vars, int start_x)
{
	int		i;

	i = 0;
	spryte_sort(vars);
	while (i < vars->elem.sprite_num)
	{
		vars->sprite[i].x = (start_x - vars->sprite[i].h_offset)\
		* (vars->texture[4].text_width) / vars->sprite[i].size_sp - 0.5;
		if (vars->elem.r_y < vars->sprite[i].size_sp)
			vars->sprite[i].size_sp = 0;
		if (vars->sprite[i].h_offset < 0 &&
		vars->sprite[i].h_offset > vars->elem.r_y - 1)
			vars->sprite[i].size_sp = 0;
		col_draw(vars, i, start_x);
		i++;
	}
}

void			get_coord_sprit(t_data *vars)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '2')
			{
				vars->sprite[z].sprite_x = j * 10 + 5;
				vars->sprite[z].sprite_y = i * 10 + 5;
				z++;
			}
			j++;
		}
		i++;
	}
}

void			get_param_sprite(t_data *vars)
{
	int		i;
	double	dir;
	double	delta;

	i = 0;
	while (i < vars->elem.sprite_num)
	{
		dir = atan2(vars->per_y - vars->sprite[i].sprite_y,
			vars->sprite[i].sprite_x - vars->per_x);
		dir = dir >= 0 ? dir : 2 * M_PI + dir;
		delta = (vars->deg + M_PI / 6) - dir;
		if (delta <= -M_PI)
			delta = 2 * M_PI + delta;
		else if (delta >= M_PI)
			delta = delta - 2 * M_PI;
		param_sprite_norme(vars, i, delta);
		i++;
	}
}

void			col_draw(t_data *vars, int i, int start_x)
{
	int	color;
	int	j;

	if (start_x >= vars->sprite[i].h_offset &&
		start_x <= vars->sprite[i].h_offset + vars->sprite[i].size_sp
		&& vars->sprite[i].dist_sp < vars->ray.distant)
	{
		j = 0;
		while (j < vars->sprite[i].size_sp &&
		vars->sprite[i].size_sp < vars->elem.r_y)
		{
			vars->sprite[i].y = j * vars->sprite[i].ratio;
			color = *((int *)(vars->texture[4].adr +\
			(vars->sprite[i].y * vars->texture[4].size_line\
			+ vars->sprite[i].x * (vars->texture[4].bpp / 8))));
			if (color != 0x00980088)
				my_mlx_pixel_put(vars, start_x,
				vars->sprite[i].v_offset + j, color);
			j++;
		}
	}
}
