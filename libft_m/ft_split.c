/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:09:41 by stune             #+#    #+#             */
/*   Updated: 2021/03/23 17:45:58 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_wd(char const *s, char c)
{
	size_t	co;
	size_t	cococ;

	co = 0;
	cococ = 0;
	while (s[cococ] != '\0' && cococ <= ft_strlen(s))
	{
		if (s[cococ] != c)
		{
			co++;
			while (s[cococ] != c && cococ <= ft_strlen(s))
				cococ++;
		}
		cococ++;
	}
	return (co);
}

static char	**ft_free_memory(char **buf, int i)
{
	while (i >= 0)
	{
		i--;
		free(buf[i]);
	}
	free(buf);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**buf;
	size_t	count;
	char	*poz;
	size_t	j;
	size_t	sp;

	count = 0;
	if (!s || !(sp = ft_wd(s, c)))
		sp = 0;
	if (!s || !(buf = (char **)malloc(sp * sizeof(char *) + 1)))
		return (NULL);
	while (*s != '\0' && count < sp)
	{
		if (*s++ != c)
		{
			j = 0;
			poz = (char *)--s;
			while (*s++ != c && s[-1] != '\0')
				j++;
			if (!(buf[count++] = ft_substr(poz, 0, j)))
				return (ft_free_memory(buf, count));
		}
	}
	buf[count] = NULL;
	return (buf);
}
