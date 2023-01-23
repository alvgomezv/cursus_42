/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_hexadecimal_printf.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:01:12 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/23 15:52:11 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexadecimal_2(unsigned long int nbr, char *base)
{
	unsigned long int	quot;
	unsigned long int	mod;
	int					res;

	res = 0;
	quot = nbr / 16;
	mod = nbr % 16;
	if (quot != 0)
		res = (ft_hexadecimal_2(quot, base));
	write(1, &base[mod], 1);
	return (res + 1);
}

int	ft_void_hexadecimal_printf(void *ptr)
{
	unsigned long int	a;

	a = (unsigned long int)ptr;
	write(1, "0x", 2);
	return (2 + ft_hexadecimal_2(a, "0123456789abcdef"));
}
