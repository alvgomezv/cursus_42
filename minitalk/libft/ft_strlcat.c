/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:31:33 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/27 15:45:38 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*
The function concatenates the strings dst and src, 
and places the result in the string dst. 
Unlike the strcat() function, strlcat() guarantees 
that the total length of the result string will be 
between the initial length of dst and size. 
The zero at the end of the string is included. 
This function is mainly used to avoid oversize 
of the character array.
*/

/*int main()
{
    char first1[100] = "1234";
    char last1[100] = "ABCD";
	char first2[100] = "1234";
    char last2[100] = "ABCD";
    int r;
    int size = 7;

    r = strlcat(first1, last1, size);
    printf("%s\n%s\n%d\n", first1, last1, r);

	r = ft_strlcat(first2, last2, size);
	printf("%s\n%s\n%d\n", first2, last2, r);

    return(0);
}*/