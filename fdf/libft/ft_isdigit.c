/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:10:27 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/20 13:25:38 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int argument)
{
	if ((argument >= 48 && argument <= 57))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_isdigit('0'));
	printf("%d", isdigit('0'));
}*/
