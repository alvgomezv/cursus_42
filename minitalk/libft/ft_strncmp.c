/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:01:31 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/23 16:32:07 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && (i < n))
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}

/*int	main (void)
{
	char			s1[] = "holzbuna";
	char			s2[] = "holabuana";
	unsigned int	n;

	n = 2;
	strncmp(s1, s2, n);
	printf("%d\n", strncmp(s1, s2, n));
	ft_strncmp(s1, s2, n);	
	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
}*/