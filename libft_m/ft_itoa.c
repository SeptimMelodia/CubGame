/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:27:52 by stune             #+#    #+#             */
/*   Updated: 2020/11/12 22:27:53 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n == -2147483648)
	{
		count = 11;
		n = 0;
	}
	while (n)
	{
		if (n < 0)
		{
			n = n * -1;
			count++;
		}
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		itter;
	int		neg;

	count = ft_count(n) + 1;
	itter = n;
	neg = 1;
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	if (n == 0)
		str[count - 2] = '0';
	str[count - 1] = '\0';
	if (n < 0)
	{
		neg = -1;
		str[0] = '-';
	}
	while (--count && n)
	{
		itter = n % 10 * neg;
		n = n / 10;
		str[count - 1] = itter + '0';
	}
	return (str);
}
