/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette_correct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:54:36 by stune             #+#    #+#             */
/*   Updated: 2021/04/02 15:22:52 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialization_var(t_data *vars, t_elem elem)
{
	vars->map = elem.map;
	vars->texture = malloc(sizeof(t_texture) * 5);
	vars->sprite = (t_sprite *)malloc(sizeof(t_sprite) * elem.sprite_num);
	get_coord_sprit(vars);
	vars->per_x = 0;
	vars->per_y = 0;
	if (elem.personage == 'N')
		vars->deg = M_PI_2;
	else if (elem.personage == 'S')
		vars->deg = 3 * M_PI_2;
	else if (elem.personage == 'W')
		vars->deg = M_PI;
	else
		vars->deg = 0;
	vars->elem = elem;
}

void	screen_limits(t_data *vars)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size(vars->mlx, &sizex, &sizey);
	if (sizex < vars->elem.r_x)
		vars->elem.r_x = sizex;
	if (sizey < vars->elem.r_y)
		vars->elem.r_y = sizey;
	if (vars->elem.r_x < (vars->elem.max_map_x * 10) ||
	vars->elem.r_y < (vars->elem.max_map_y * 10))
	{
		ft_putendl_fd("ERROR\nThe minimap is larger than the window size.", 2);
		exit(0);
	}
}

void	param_sprite_norme(t_data *vars, int i, double delta)
{
	vars->sprite[i].dist_sp = hypot(vars->per_y -\
	vars->sprite[i].sprite_y, vars->sprite[i].sprite_x - vars->per_x);
	vars->sprite[i].dist_sp = vars->sprite[i].dist_sp * cos(vars->deg\
					+ (M_PI / 6) - vars->deg);
	vars->sprite[i].size_sp = (int)((10 / vars->sprite[i].dist_sp)\
				* ((vars->elem.r_x / 2) / tan(M_PI / 6)));
	vars->sprite[i].h_offset = (delta / ((M_PI / 3) / vars->elem.r_x)\
				- vars->sprite[i].size_sp / 2);
	vars->sprite[i].v_offset = (vars->elem.r_y / 2\
			- vars->sprite[i].size_sp / 2);
	if (vars->sprite[i].h_offset < 0 && vars->sprite[i].h_offset\
						> vars->elem.r_x)
		vars->sprite[i].size_sp = 0;
	vars->sprite[i].ratio = vars->texture[4].text_heght\
			/ (double)vars->sprite[i].size_sp;
}
