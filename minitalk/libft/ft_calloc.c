/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:34:51 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/17 09:57:13 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*a;

	a = (size_t *)malloc(nitems * size);
	if (a == 0)
		return (NULL);
	ft_bzero(a, nitems * size);
	return (a);
}

// Crea un buffer y lo inicializa a \0
// es importante que el buffer sea void, si no da problemas

/*int main () 
{
   int i; 
   int n;
   int *a;
   int *b;

   printf("Number of elements to be entered:");
   scanf("%d",&n);

   a = (int*)calloc(n, sizeof(int));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d ",a[i]);
   }
   free(a);


   printf("\nNumber of elements to be entered:");
   scanf("%d",&n);

   b = ft_calloc(n, sizeof(int));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&b[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d ",b[i]);
   }
   free(b);
   
   return(0);
}*/