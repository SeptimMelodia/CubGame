/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:01:31 by stune             #+#    #+#             */
/*   Updated: 2020/11/03 15:01:34 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int count;

	count = ft_strlen(s);
	while ((count + 1) != 0)
	{
		if (s[count] == c)
		{
			return ((char *)&s[count]);
		}
		count--;
	}
	return (0);
}
