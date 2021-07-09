/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:10:50 by stune             #+#    #+#             */
/*   Updated: 2021/04/01 17:49:38 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(int ident)
{
	write(2, "Error!\n", 7);
	if (ident == 1)
		ft_putendl_fd("Wrong map", 2);
	if (ident == 2)
		ft_putendl_fd("Invalid map file", 2);
	exit(0);
}

int		sprite_and_personage(char *s, t_elem *elem)
{
	while (*s)
	{
		if (ft_strchr("NSEW", *s))
		{
			if (elem->personage)
				return (0);
			elem->personage = *s;
		}
		if (*s == '2')
			elem->sprite_num++;
		s++;
	}
	return (1);
}

void	valid_valid(char **tmp, int x, int y)
{
	if ((!tmp[x][y + 1] || y == 0 || !tmp[x + 1] ||
	!tmp[x + 1][y]) && ft_strchr("02NSEW", tmp[x][y]))
		print_error(1);
	else if (tmp[x][y] != '1' && !ft_strchr("012NSEW", tmp[x][y - 1]))
		print_error(1);
	else if (tmp[x][y] != '1' && !ft_strchr("012NSEW", tmp[x][y + 1]))
		print_error(1);
	else if (tmp[x][y] != '1' && !ft_strchr("012NSEW", tmp[x - 1][y]))
		print_error(1);
	else if (tmp[x][y] != '1' && !ft_strchr("012NSEW", tmp[x + 1][y]))
		print_error(1);
}
