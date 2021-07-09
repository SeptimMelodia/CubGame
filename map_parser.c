/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:22:19 by stune             #+#    #+#             */
/*   Updated: 2021/04/02 15:40:14 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elem	*ft_type_elem(t_list *l_map)
{
	t_elem	*elem;
	t_list	*tmp;

	elem = ft_lstnew_elem();
	elem->all_color = ft_lstnew_color();
	elem->personage = 0;
	tmp = l_map;
	while (tmp)
	{
		elem_if_not_true(tmp);
		elem = ft_resolution(tmp, elem);
		elem = ft_sonowesea(tmp, elem);
		elem = ft_cel_col(tmp, elem);
		elem = ft_flo_col(tmp, elem);
		elem->map = ft_map_pars(&tmp, &elem);
		if (tmp)
			tmp = tmp->next;
	}
	ft_check_valid(elem);
	ft_valid_map(elem);
	return (elem);
}

char	**ft_map_pars(t_list **l_map, t_elem **elem)
{
	char	**map;
	int		i;
	int		max_len;

	map = NULL;
	if (ft_if_one(*l_map))
	{
		if ((max_len = valid_end_map(*l_map, elem)))
			map = ft_calloc(ft_lstsize(*l_map) + 1, sizeof(char *));
		else
			print_error(1);
		i = -1;
		while (*l_map)
		{
			map[++i] = ft_calloc(max_len + 1, sizeof(char));
			ft_memset(map[i], ' ', max_len);
			ft_strlcpy(map[i], (*l_map)->content, max_len + 1);
			*l_map = (*l_map)->next;
		}
	}
	return (map);
}

int		ft_if_one(t_list *tmp)
{
	char	*rr;

	rr = tmp->content;
	if (!*rr)
		return (0);
	while (*rr)
	{
		if (*rr != '1' && *rr != ' ')
			return (0);
		rr++;
	}
	return (1);
}
