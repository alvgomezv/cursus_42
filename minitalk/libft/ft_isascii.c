/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:22:23 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/20 15:19:16 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int argument)
{
	if ((argument >= 0 && argument <= 127))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_isascii('0'));
	printf("%d", isascii('0'));
}*/
