/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:01:12 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/11 20:54:36 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexadecimal(unsigned int nbr, char *base)
{
	unsigned int	quot;
	unsigned int	mod;
	unsigned int	res;

	res = 0;
	quot = nbr / 16;
	mod = nbr % 16;
	if (quot != 0)
		res = (ft_hexadecimal(quot, base));
	write(1, &base[mod], 1);
	return (res + 1);
}

/*int	main(void)
{
	printf("\n%d\n", ft_hexadecimal(-1542, "0123456789ABCDEF"));
}*/
