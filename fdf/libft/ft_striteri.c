/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:27:36 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/28 12:55:24 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s || f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

/*
Applies the function ’f’ on each character 
of the string passed as argument, passing 
its index as first argument. Each character 
is passed by address to ’f’ to be modified if necessary.
*/

/*void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	iter(unsigned int i, char *c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int	main(void)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * 12);
	if (str)
	{
		strcpy(str, "LoReM iPsUm");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	return (0);
}*/