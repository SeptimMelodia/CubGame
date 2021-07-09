/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:54:55 by stune             #+#    #+#             */
/*   Updated: 2021/03/30 18:56:54 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elem	*ft_lstnew_elem(void)
{
	t_elem	*create;

	create = (t_elem *)malloc(sizeof(t_elem));
	if (create)
	{
		create->r_x = 0;
		create->r_y = 0;
		create->no = NULL;
		create->so = NULL;
		create->we = NULL;
		create->ea = NULL;
		create->s = NULL;
		create->all_color = NULL;
		create->map = NULL;
		create->personage = 0;
		create->max_map_x = 0;
		create->max_map_y = 0;
	}
	else
		free(create);
	return (create);
}

t_color	*ft_lstnew_color(void)
{
	t_color	*create;

	create = (t_color *)malloc(sizeof(t_color));
	if (create)
	{
		create->fl_r = 0;
		create->fl_g = 0;
		create->fl_b = 0;
		create->fl_valid = 0;
		create->ce_r = 0;
		create->ce_g = 0;
		create->ce_b = 0;
		create->ce_valid = 0;
	}
	else
		free(create);
	return (create);
}
