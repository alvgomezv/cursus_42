/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:32:27 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/06 11:25:45 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	print_number(unsigned int nb, long int mult)
{
	char	a;
	int		i;

	i = 1;
	if (nb < 10)
	{
		a = nb + '0';
		write(1, &a, 1);
		return (1);
	}
	else
	{
		while (mult > 1)
		{
			a = (nb / mult) + '0';
			nb = nb % mult;
			mult = mult / 10;
			write(1, &a, 1);
			i++;
		}
		a = (nb) + '0';
		write(1, &a, 1);
		return (i);
	}
}

static long int	multi(unsigned int nb)
{
	long int	mult;

	mult = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		mult = mult * 10;
	}
	return (mult);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	long int	mult;
	int			a;

	a = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		mult = multi(nb);
		return (a + print_number(nb, mult));
	}
}
