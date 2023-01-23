/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:37:00 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/23 12:07:34 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// No entiendo como funciona el return en medio de la funcion

/*int	main(void)
{
	unsigned int	size;
	char			src[20] = "";
	char			dest[20] = "jasddjffaskad";
	unsigned int	nuevo;

	size = 8;
	nuevo = strlcpy(dest, src ,size);
	printf("%u\n", nuevo);
	printf("%s\n", src);
	printf("%s\n", dest);
	printf("%lu, %lu\n", sizeof(src), sizeof(dest));
	nuevo = ft_strlcpy(dest, src, size);
	printf("%u\n", nuevo);
	printf("%s\n", src);
	printf("%s\n", dest);
	printf("%lu, %lu\n", sizeof(src), sizeof(dest));
}*/
