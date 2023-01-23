/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:00:51 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/28 12:53:14 by alvgomez         ###   ########.fr       */
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

/*
Applies the function ’f’ to each character of 
the string ’s’, and passing its index as first 
argument to create a new string (with malloc(3)) 
resulting from successive applications of ’f’.
*/

/*void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

char	mapi(unsigned int i, char c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int		main(void)
{
	char	*str;
	char	*strmapi;

	str = (char *)malloc(sizeof(*str) * 12);
	if (!str)
		return (0);
	strcpy(str, "LoReM iPsUm");
	strmapi = ft_strmapi(str, &mapi);
	ft_print_result(strmapi);
	if (strmapi == str)
		ft_print_result("\nA new string was not returned");
	if (strmapi[11] != '\0')
		ft_print_result("\nString is not null terminated");
	return (0);
}*/
