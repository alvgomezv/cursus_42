/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:48:04 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/20 17:54:59 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if ((c >= 97 && c <= 122))
		return (c - 32);
	else
		return (c);
}

/*int main() 
{
    char c;

    c = 'm';
    printf("%c -> %c\n", c, toupper(c));
	printf("%c -> %c", c, ft_toupper(c));

    c = 'D';
    printf("\n%c -> %c\n", c, toupper(c));
	printf("%c -> %c", c, ft_toupper(c));

    c = '9';
    printf("\n%c -> %c\n", c, toupper(c));
	printf("%c -> %c", c, ft_toupper(c));
    return 0;
}*/
