/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:45:36 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/20 15:38:41 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int argument)
{
	if ((argument >= 65 && argument <= 90)
		|| (argument >= 97 && argument <= 122))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_isalpha('0'));
	printf("%d", isalpha('0'));
}*/
