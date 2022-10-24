/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:16:39 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/18 12:24:37 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	convert_to_int(char *str, int i)
{
	int	rest;

	rest = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rest = rest * 10;
		rest = rest + (str[i] - '0');
		i++;
	}
	return (rest);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nbr;
	char	*s;

	i = 0;
	sign = 1;
	s = (char *)str;
	while (s[i] == ' '
		|| (s[i] >= 9 && s[i] <= 13))
	i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
	i++;
	}
	nbr = convert_to_int(s, i);
	return (nbr * sign);
}
