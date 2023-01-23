/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:22:33 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/21 10:56:18 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned long	cont;
	unsigned char	*str2;

	str2 = (unsigned char *)str;
	cont = 0;
	while (cont < n)
	{
		str2[cont] = c;
		cont++;
	}
	return (str);
}

/*int main () 
{
   char str[50];

   strcpy(str,"This is string.h library function");
   //printf("%s\n", str);

   memset(str,'$',7);
   printf("%s\n", str);

   ft_memset(str,'$',7);
   printf("%s\n", str);
   
   return(0);
}*/