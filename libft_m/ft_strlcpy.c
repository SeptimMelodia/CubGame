/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:18:53 by stune             #+#    #+#             */
/*   Updated: 2020/11/02 18:18:56 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t count;

	count = 0;
	if (!dst || !src)
		return (0);
	while (src[count] != '\0')
	{
		if (count < (n) && n != 0)
		{
			dst[count] = src[count];
			dst[n - 1] = '\0';
		}
		count++;
	}
	if (n > count)
		dst[count] = '\0';
	return (count);
}
