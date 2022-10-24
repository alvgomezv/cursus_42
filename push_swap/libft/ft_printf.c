/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:44:10 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/18 11:25:14 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	what_to_print(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	if (c == 'p')
		return (ft_void_hexadecimal(va_arg(list, void *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(list, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(list, unsigned int)));
	if (c == 'x')
		return (ft_hexadecimal(va_arg(list, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_hexadecimal(va_arg(list, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *arg, ...)
{
	va_list	list;
	int		a;
	int		cont;
	int		b;

	va_start(list, arg);
	cont = 0;
	a = 0;
	while (arg[a] != '\0')
	{
		if (arg[a] == '%')
		{
			a++;
			b = what_to_print(arg[a], list);
			cont = cont + b;
		}
		else
		{
			write (1, &arg[a], 1);
			cont++;
		}	
	a++;
	}
	va_end(list);
	return (cont);
}
