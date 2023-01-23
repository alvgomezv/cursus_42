/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:23:17 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/27 13:36:01 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	if ((unsigned char)c == '\0')
		return (&str[i]);
	while (i-- > 0)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
	}
	return (NULL);
}

/*int main () 
{
   char	*str = "abbbbbbbb";
   char	ch = 'a';
   char 		*rest1;
   char 		*rest2;

   rest1 = strrchr(str, ch);
   rest2 = ft_strrchr(str, ch);

   printf("String after last |%c| is - |%s|\n", ch, rest1);
   printf("String after last |%c| is - |%s|\n", ch, rest2);
   
   return(0);
}*/