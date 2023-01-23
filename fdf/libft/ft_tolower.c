/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:55:46 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/20 17:57:09 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if ((c >= 65 && c <= 90))
		return (c + 32);
	else
		return (c);
}

/*int main() 
{
    char c;

    c = 'm';
    printf("%c -> %c\n", c, tolower(c));
	printf("%c -> %c", c, ft_tolower(c));

    c = 'D';
    printf("\n%c -> %c\n", c, tolower(c));
	printf("%c -> %c", c, ft_tolower(c));

    c = '9';
    printf("\n%c -> %c\n", c, tolower(c));
	printf("%c -> %c", c, ft_tolower(c));
    return 0;
}*/