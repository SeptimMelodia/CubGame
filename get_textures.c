/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:10:35 by stune             #+#    #+#             */
/*   Updated: 2021/04/01 17:44:34 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_texture(t_data *vars)
{
	int		i;
	char	*text_path;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			text_path = vars->elem.no;
		else if (i == 1)
			text_path = vars->elem.so;
		else if (i == 2)
			text_path = vars->elem.we;
		else if (i == 3)
			text_path = vars->elem.ea;
		if (!(vars->texture[i].image = mlx_xpm_file_to_image(vars->mlx,
		text_path, &vars->texture[i].text_width, &vars->texture[i].text_heght)))
		{
			ft_putendl_fd("ERROR\nInvalid texture directory", 2);
			exit(0);
		}
		vars->texture[i].adr = mlx_get_data_addr(vars->texture[i].image,
				&vars->texture[i].bpp, &vars->texture[i].size_line,
						&vars->texture[i].endian);
		i++;
	}
}

void	texture_mapping(t_data *vars, double h, double start, int start_x)
{
	double	coeff;
	int		side;

	side = check_side(vars, start);
	coeff = (double)vars->texture[side].text_width / 10;
	vars->texture[side].ratio = vars->texture[side].text_heght / h;
	if (vars->ray.intersection == 1)
		vars->texture[side].x = (int)(vars->ray.hor_ray_x * coeff)\
						% (int)(10 * coeff);
	else
		vars->texture[side].x = (int)(vars->ray.ver_ray_y * coeff)\
						% (int)(10 * coeff);
	while (vars->start_row < vars->end_row)
	{
		vars->texture[side].y = vars->norm_wall * vars->texture[side].ratio;
		vars->texture[side].color = *((int *)(vars->texture[side].adr
		+ (int)((vars->texture[side].y * vars->texture[side].size_line +
		vars->texture[side].x * (vars->texture[side].bpp / 8)))));
		my_mlx_pixel_put(vars, start_x, vars->start_row,
					vars->texture[side].color);
		vars->norm_wall++;
		vars->start_row++;
	}
}

int		check_side(t_data *vars, double start)
{
	int		side;
	t_dir	dir;

	dir = ray_dir(start);
	if (dir.rayis_up && vars->ray.intersection == 1)
		side = 0;
	if (dir.rayis_down && vars->ray.intersection == 1)
		side = 1;
	if (dir.rayis_left && vars->ray.intersection == 0)
		side = 2;
	if (dir.rayis_right && vars->ray.intersection == 0)
		side = 3;
	return (side);
}

void	open_sprite(t_data *vars)
{
	char	*dr_pepper;

	dr_pepper = vars->elem.s;
	if (!(vars->texture[4].image = mlx_xpm_file_to_image(vars->mlx,
			dr_pepper, &vars->texture[4].text_width,
				&vars->texture[4].text_heght)))
	{
		ft_putendl_fd("ERROR\nInvalid sprite directory", 2);
		exit(0);
	}
	vars->texture[4].adr = mlx_get_data_addr(vars->texture[4].image,
		&vars->texture[4].bpp, &vars->texture[4].size_line,
					&vars->texture[4].endian);
}
