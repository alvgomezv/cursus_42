/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:23:29 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/22 14:19:36 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char *str1;
	char *str2;

	str1 = (char *)malloc(6 * sizeof(char));
	str2 = (char *)malloc(6 * sizeof(char));
	bzero(str1, 2);
	ft_bzero(str2, 4);
	printf("%s\n", str1);
	printf("%s", str2);
}*/
