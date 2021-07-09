/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:26:38 by stune             #+#    #+#             */
/*   Updated: 2020/11/03 14:26:42 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len]);
	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			return ((char *)&s[count]);
		}
		count++;
	}
	return (0);
}
