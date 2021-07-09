/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:54:15 by stune             #+#    #+#             */
/*   Updated: 2021/01/13 18:02:37 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_m(const char *s, int c)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen_m(s);
	if (c == '\0')
		return ((char *)&s[len]);
	if (!s)
		return (NULL);
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

size_t	ft_strlen_m(const char *str)
{
	size_t count;

	count = 0;
	if (!str)
		return (count);
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin_m(char const *s1, char const *s2)
{
	char	*buf;
	size_t	count;
	size_t	len1;
	size_t	len2;

	count = 0;
	len1 = ft_strlen_m(s1);
	len2 = ft_strlen_m(s2);
	if (!(buf = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (s1 && *s1 != '\0')
	{
		buf[count] = *s1++;
		count++;
	}
	while (s2 && *s2 != '\0')
	{
		buf[count] = *s2++;
		count++;
	}
	buf[count] = '\0';
	return (buf);
}

char	*ft_strdup_m(const char *s1)
{
	char	*buf;
	int		count;
	size_t	len;

	count = 0;
	len = ft_strlen_m(s1);
	buf = (char *)malloc(sizeof(char) * len + 1);
	if (buf == NULL)
		return (NULL);
	while (s1[count] != '\0')
	{
		buf[count] = s1[count];
		count++;
	}
	buf[count] = '\0';
	return (buf);
}
