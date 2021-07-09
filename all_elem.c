/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:02:43 by stune             #+#    #+#             */
/*   Updated: 2021/04/02 15:43:08 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elem	*ft_resolution(t_list *tmp, t_elem *elem)
{
	char	*rr;

	if ((rr = ft_check_elem(tmp->content, "R", 'n'))
			&& (!elem->r_x || !elem->r_y))
	{
		elem->r_x = ft_atoi(rr);
		while (*rr && (*rr <= '9' && *rr >= '0'))
			rr++;
		while (*rr && (*rr == ' '))
			rr++;
		elem->r_y = ft_atoi(rr);
		while (*rr && (*rr <= '9' && *rr >= '0'))
			rr++;
		while (*rr)
		{
			if (*rr != ' ')
			{
				ft_putendl_fd("ERROR\nInvalid argument\n", 2);
				exit(0);
			}
			rr++;
		}
	}
	return (elem);
}

t_elem	*ft_sonowesea(t_list *tmp, t_elem *elem)
{
	char	*rr;

	if ((rr = ft_check_elem(tmp->content, "SO", '.')) && !elem->so)
		elem->so = rr;
	if ((rr = ft_check_elem(tmp->content, "NO", '.')) && !elem->no)
		elem->no = rr;
	if ((rr = ft_check_elem(tmp->content, "WE", '.')) && !elem->we)
		elem->we = rr;
	if ((rr = ft_check_elem(tmp->content, "EA", '.')) && !elem->ea)
		elem->ea = rr;
	if ((rr = ft_check_elem(tmp->content, "S", '.')) && !elem->s)
		elem->s = rr;
	return (elem);
}

t_elem	*ft_cel_col(t_list *tmp, t_elem *elem)
{
	char	*rr;

	if ((rr = ft_check_elem(tmp->content, "C", 'n'))
			&& !elem->all_color->ce_valid)
	{
		elem->all_color->ce_valid = 1;
		if ((elem->all_color->ce_r = ft_atoi(rr)) > 255)
			elem->all_color->ce_valid = 0;
		while (*rr && ((*rr <= '9' && *rr >= '0' && *(rr - 1) != ',')
							|| (*rr == ',')))
			rr++;
		if (!(*rr <= '9' && *rr >= '0'))
			elem->all_color->ce_valid = 0;
		if ((elem->all_color->ce_g = ft_atoi(rr)) > 255)
			elem->all_color->ce_valid = 0;
		while (*rr && ((*rr <= '9' && *rr >= '0')))
			rr++;
		if (*rr == ',')
			rr++;
		if (!(*rr <= '9' && *rr >= '0'))
			elem->all_color->ce_valid = 0;
		if ((elem->all_color->ce_b = ft_atoi(rr)) > 255)
			elem->all_color->ce_valid = 0;
	}
	return (elem);
}

t_elem	*ft_flo_col(t_list *tmp, t_elem *elem)
{
	char	*rr;

	if ((rr = ft_check_elem(tmp->content, "F", 'n'))
			&& !elem->all_color->fl_valid)
	{
		elem->all_color->fl_valid = 1;
		if ((elem->all_color->fl_r = ft_atoi(rr)) > 255)
			elem->all_color->fl_valid = 0;
		while (*rr && ((*rr <= '9' && *rr >= '0' && *(rr - 1) != ',')
							|| (*rr == ',')))
			rr++;
		if (!(*rr <= '9' && *rr >= '0'))
			elem->all_color->fl_valid = 0;
		if ((elem->all_color->fl_g = ft_atoi(rr)) > 255)
			elem->all_color->fl_valid = 0;
		while (*rr && ((*rr <= '9' && *rr >= '0')))
			rr++;
		if (*rr == ',')
			rr++;
		if (!(*rr <= '9' && *rr >= '0'))
			elem->all_color->fl_valid = 0;
		if ((elem->all_color->fl_b = ft_atoi(rr)) > 255)
			elem->all_color->fl_valid = 0;
	}
	return (elem);
}
