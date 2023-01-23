/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:44:41 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/22 19:33:41 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static void	fill_dest(char	*str1, char *str2, size_t len)
{
	unsigned long	i;

	i = 0;
	while (i < len)
	{
		str2[i] = str1[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*str1;
	char			*str2;

	str1 = (char *)src;
	str2 = dst;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		fill_dest(str1, str2, len);
	else
	{
		while (len > 0)
		{
			str2[len - 1] = str1[len - 1];
			len--;
		}
	}
	return (dst);
}

/*int main () 
{
   char dst1[11];
   char dst2[11];
   const char src[]  = "lorem ipum dolor sit a";

   printf("1 dest = %s\n", dst1);
   memmove(dst1, src, 10);
   printf("1 dest = %s\n", dst1);
   
   printf("\n");
   
   printf("2 dest = %s\n", dst2);
   ft_memmove(dst2, src, 10);
   printf("2 dest = %s\n", dst2);
   return(0);
}*/