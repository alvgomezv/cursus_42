/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:52:12 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/27 15:30:19 by alvgomez         ###   ########.fr       */
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

/*
The strnstr() function locates the	first occurrence of the	
null-termi-nated string little in the string big, where 
not more than len characters are searched. 
Characters that appear after a `\0'	character are not
searched.
*/

/*int	main (void)
{
	char	*big = "lorem ipsum dolor sit amet";
	char	*little = "dol";
	size_t	len;
	char	*result1;
	char	*result2;

	len = ft_strlen(big);
	result1 = strnstr(big, little, len);
	printf("%s\n", result1);
	result2 = ft_strnstr(big, little, len);
	printf("%s\n", result2);
	return (0);
}*/