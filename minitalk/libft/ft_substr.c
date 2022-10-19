/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:53:33 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/18 11:26:51 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str1;	

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		str1 = (char *)ft_calloc(1, sizeof(char));
		return (str1);
	}
	if ((start + len) >= ft_strlen(s))
		str1 = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		str1 = (char *)malloc((len + 1) * sizeof(char));
	if (!str1)
		return (0);
	while (s[start] && i < len)
	{
		str1[i] = s[start];
		i++;
		start++;
	}
	str1[i] = '\0';
	return (str1);
}
