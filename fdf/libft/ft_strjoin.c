/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:12:04 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/16 17:20:35 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		i;
	char	*str;

	i = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2) + a;
	str = (char *)malloc((b + 1) * sizeof(char));
	while (i < a)
	{
		str[i] = s1[i];
		i++;
	}
	a = 0;
	while (i < b)
	{
		str[i] = s2[a];
		i++;
		a++;
	}
	str[i] = '\0';
	return (str);
}
