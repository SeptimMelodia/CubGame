/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:43:14 by stune             #+#    #+#             */
/*   Updated: 2020/11/14 17:43:16 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*create;

	create = (t_list *)malloc(sizeof(t_list));
	if (create)
	{
		create->content = content;
		create->next = NULL;
	}
	return (create);
}
