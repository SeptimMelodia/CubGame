/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:29:52 by stune             #+#    #+#             */
/*   Updated: 2020/11/13 18:29:54 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	int		count;
	int		len;

	count = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(buf = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (count < len)
	{
		buf[count] = f(count, s[count]);
		count++;
	}
	buf[count] = '\0';
	return (buf);
}
