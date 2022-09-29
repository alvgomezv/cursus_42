/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:04:50 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/27 16:26:08 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	char	*str;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	length = ft_strlen(s1);
	while (length != 0 && ft_strchr(set, s1[length]))
		length--;
	str = ft_substr(s1, 0, length + 1);
	return (str);
}

/*int	main(void)
{
	printf("%s\n", ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t"));
}*/
