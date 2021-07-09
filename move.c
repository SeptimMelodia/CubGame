/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:34:08 by stune             #+#    #+#             */
/*   Updated: 2021/04/02 15:21:55 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *vars)
{
	if (vars->elem.map[(int)((vars->per_y + (-1 * sin(vars->deg) * 4))\
	/ 10)][(int)((vars->per_x + (cos(vars->deg) * 4)) / 10)] != '1')
	{
		vars->per_y -= (sin(vars->deg) * 1);
		vars->per_x += (cos(vars->deg) * 1);
	}
	else if (vars->elem.map[(int)((vars->per_y - (sin(vars->deg)\
	* 4)) / 10)][(int)(vars->per_x)] != '1')
	{
		vars->per_x += (cos(vars->deg) * 1);
	}
	else if (vars->elem.map[(int)((vars->per_y) / 10)][(int)((vars->per_x\
	+ (cos(vars->deg) * 4)) / 10)] != '1')
	{
		vars->per_y -= (sin(vars->deg) * 1);
	}
}

void	move_left(t_data *vars)
{
	if (vars->elem.map[(int)((vars->per_y - ((4 * sin(vars->deg\
		+ M_PI_2)))) / 10)][(int)((vars->per_x + (4 * cos(vars->deg\
					+ M_PI_2))) / 10)] != '1')
	{
		vars->per_y -= (1 * sin(vars->deg + M_PI_2));
		vars->per_x += (1 * cos(vars->deg + M_PI_2));
	}
}

void	move_back(t_data *vars)
{
	if (vars->elem.map[(int)((vars->per_y - ((4 * sin(vars->deg +\
		M_PI)))) / 10)][(int)((vars->per_x + (4 * cos(vars->deg\
						+ M_PI))) / 10)] != '1')
	{
		vars->per_x += (1 * cos(vars->deg + M_PI));
		vars->per_y -= ((1 * sin(vars->deg + M_PI)));
	}
}

void	move_right(t_data *vars)
{
	if (vars->elem.map[(int)((vars->per_y - ((4 * sin(vars->deg\
		+ 3 * M_PI_2)))) / 10)][(int)((vars->per_x + (4 *\
			cos(vars->deg + 3 * M_PI_2))) / 10)] != '1')
	{
		vars->per_x += (1 * cos(vars->deg + 3 * M_PI_2));
		vars->per_y -= ((1 * sin(vars->deg + 3 * M_PI_2)));
	}
}
