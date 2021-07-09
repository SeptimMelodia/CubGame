/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:43:03 by stune             #+#    #+#             */
/*   Updated: 2021/03/30 19:05:51 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_valid(t_elem *elem)
{
	if (!elem->r_x || !elem->r_y || !elem->no || !elem->so || !elem->we ||
			!elem->ea || !elem->s || !elem->all_color->ce_valid ||
				!elem->all_color->fl_valid || !elem->map)
	{
		ft_putendl_fd("ERROR\nNOT VALID!", 2);
		exit(0);
	}
	if (elem->personage == 0)
	{
		ft_putendl_fd("ERROR\nPERSONAGE MISSED", 2);
		exit(0);
	}
}

char	*ft_check_elem(char *str, char *src, char stop)
{
	while (*str == ' ')
		str++;
	while (*src != '\0' && *str != '\0')
	{
		if (*str != *src && *src != '\0')
			return (NULL);
		str++;
		src++;
	}
	while (*str != '\0' && *str != '.' && *src == '\0' && stop == '.')
	{
		if (*str != '.' && *str != ' ')
			return (NULL);
		str++;
	}
	if (*str == '.' && *str + 1 == '/' && stop == '.')
		return (str);
	while (*str == ' ')
		str++;
	if (stop == 'n' && *str <= '9' && *str >= '0')
		return (str);
	return (NULL);
}

void	elem_if_not_true(t_list *tmp)
{
	char	*s;

	s = tmp->content;
	if (!*s)
		tmp->content = tmp->content;
	else if (tmp->content && (!ft_check_elem(tmp->content, "SO", '.') &&
	!ft_check_elem(tmp->content, "NO", '.') &&
	!ft_check_elem(tmp->content, "WE", '.') &&
	!ft_check_elem(tmp->content, "EA", '.') &&
	!ft_check_elem(tmp->content, "S", '.') &&
	!ft_check_elem(tmp->content, "R", 'n') &&
	!ft_check_elem(tmp->content, "C", 'n') &&
	!ft_check_elem(tmp->content, "F", 'n') &&
	!ft_if_one(tmp)))
	{
		ft_putendl_fd("Error\nUnknown argument", 2);
		exit(0);
	}
}

int		ft_valid_map(t_elem *elem)
{
	char	**tmp;
	int		x;
	int		y;

	tmp = elem->map;
	x = 0;
	while (tmp[x])
	{
		y = 0;
		while (tmp[x][y])
		{
			if (ft_strchr("012NSEW", tmp[x][y]))
				valid_valid(tmp, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

int		valid_end_map(t_list *l_map, t_elem **elem)
{
	t_list	*tmp;
	char	*s;

	(*elem)->sprite_num = 0;
	tmp = l_map;
	while (tmp)
	{
		s = tmp->content;
		if (!(sprite_and_personage(s, *elem)))
			return (0);
		if ((*elem)->max_map_x < (int)ft_strlen(tmp->content))
			(*elem)->max_map_x = (int)ft_strlen(tmp->content);
		tmp = tmp->next;
		(*elem)->max_map_y++;
	}
	tmp = ft_lstlast(l_map);
	if ((*elem)->max_map_x < (int)ft_strlen(tmp->content))
		(*elem)->max_map_x = (int)ft_strlen(tmp->content);
	if (!ft_if_one(tmp))
		return (0);
	return ((*elem)->max_map_x);
}
