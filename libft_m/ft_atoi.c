/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:43:30 by stune             #+#    #+#             */
/*   Updated: 2020/10/30 20:39:30 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			co;
	long int	result;
	int			negativ;

	co = 0;
	result = 0;
	negativ = 1;
	while ((str[co] >= 9 && str[co] <= 13) || str[co] == 32)
		co++;
	if (str[co] == '-' && str[co + 1] != '+')
	{
		co++;
		negativ = -1;
	}
	if (str[co] == '+' && str[co + 1] != '-')
		co++;
	while (str[co] <= '9' && str[co] >= '0')
	{
		result = ((str[co] - 48) + result) * 10;
		co++;
	}
	return (result / 10 * negativ);
}
