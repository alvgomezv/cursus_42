/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:52:12 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/18 11:26:40 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str_big;
	char	*str_little;

	i = 0;
	str_big = (char *)big;
	str_little = (char *)little;
	size = ft_strlen(str_little);
	if (!str_little[0])
		return (str_big);
	while (str_big[i] && i < len)
	{
		if (str_big[i] == little[0]
			&& ft_memcmp(&str_big[i], str_little, size) == 0
			&& (i + size) <= len)
			return (&str_big[i]);
	i++;
	}
	return (NULL);
}
