/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:00:51 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/18 11:26:28 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	*s2;

	s2 = (char *)s;
	i = 0;
	if (!s || !f)
		return (0);
	str = (char *)malloc((ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s2[i])
	{
		str[i] = f(i, s2[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
