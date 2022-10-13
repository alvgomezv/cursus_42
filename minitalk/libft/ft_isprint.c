/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:00:50 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/22 12:35:05 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int argument)
{
	if ((argument >= 32 && argument <= 126))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_isprint(' '));
	printf("%d", isprint(' '));
}*/
