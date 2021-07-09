/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:21:48 by stune             #+#    #+#             */
/*   Updated: 2021/03/20 17:12:05 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_personage(t_data *vars, t_wall *wall, int *adn, int *adj)
{
	if (ft_strchr("WSNE", vars->map[wall->i][wall->j]))
	{
		if (!vars->per_x && !vars->per_y)
		{
			vars->per_x = wall->x + 10;
			vars->per_y = wall->y;
		}
	}
	if (vars->map[wall->i][wall->j] == '2')
	{
		while (++wall->x < *adn + 10)
		{
			wall->y = *adj;
			while (++wall->y < *adj + 10)
				my_mlx_pixel_put(vars, wall->x, wall->y, 0x00FFFF00);
		}
		wall->x = wall->x - 10;
	}
}

void	margin(t_data *vars, t_wall *wall, int *adn, int *adj)
{
	if (vars->map[wall->i][wall->j] != '0' && vars->map[wall->i][wall->j]\
		!= ' ' && !ft_strchr("WSNE2", vars->map[wall->i][wall->j]))
	{
		while (++wall->x < *adn + 10)
		{
			wall->y = *adj;
			while (++wall->y < *adj + 10)
				my_mlx_pixel_put(vars, wall->x, wall->y, 0x00FF0000);
		}
		*adn = *adn + 10;
	}
	else
	{
		wall->x = wall->x + 10;
		*adn = *adn + 10;
	}
}

void	ft_wall(t_data *vars)
{
	static t_wall	*wall;
	int				adj;
	int				adn;

	wall = malloc(sizeof(t_wall) + 1);
	wall->i = 0;
	wall->x = -1;
	wall->y = -1;
	adj = 0;
	adn = 0;
	while (vars->map[wall->i])
	{
		wall->j = 0;
		while (vars->map[wall->i][wall->j] != '\0')
		{
			save_personage(vars, wall, &adn, &adj);
			margin(vars, wall, &adn, &adj);
			wall->j++;
		}
		wall->x = 0;
		adn = 0;
		adj = adj + 10;
		wall->i++;
	}
	free(wall);
}
