/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:29:44 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/11 21:03:47 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*int main () 
{
   const char str[] = "hola que tal como estas";
   const char ch = 't';
   char *rest1;
   char *rest2;

   rest1 = memchr(str, ch, 5);
   rest2 = ft_memchr(str, ch, 5);

   printf("String after |%c| is - |%s|\n", ch, rest1);
   printf("String after |%c| is - |%s|\n", ch, rest2);

   return(0);
}*/