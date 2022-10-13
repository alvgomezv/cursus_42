/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:58:32 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/05 18:11:48 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		len;
	int		i;

	len = ft_strlen(s) + 1;
	i = 0;
	str = (char *)s;
	ch = (char) c;
	while (i < len)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	if (ch == '\0')
		return (&str[i]);
	return (NULL);
}

/*
Finds the first occurrence of ch (after conversion to 
char as if by (char)ch) in the null-terminated byte 
string pointed to by str (each character interpreted 
as unsigned char). The terminating null character is 
considered to be a part of the string and can be 
found when searching for '\0'.

The behavior is undefined if str is not a pointer to a 
null-terminated byte string
*/

// It is important to use len + 1 so it includes '\0'

/*int main () 
{
   const char	str[] = "hola";
   const char	ch = '\0';
   char 		*rest1;
   char 		*rest2;
   rest1 = strchr(str, ch);
   rest2 = ft_strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, rest1);
   printf("String after |%c| is - |%s|\n", ch, rest2);
   
   return(0);
}*/