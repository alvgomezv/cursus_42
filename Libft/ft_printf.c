/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:44:10 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/23 15:52:26 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	what_to_print(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar_printf(va_arg(list, int)));
	if (c == 's')
		return (ft_putstr_printf(va_arg(list, char *)));
	if (c == 'p')
		return (ft_void_hexadecimal_printf(va_arg(list, void *)));
	if (c == 'd')
		return (ft_putnbr_printf(va_arg(list, int)));
	if (c == 'i')
		return (ft_putnbr_printf(va_arg(list, int)));
	if (c == 'u')
		return (ft_unsigned_putnbr_printf(va_arg(list, unsigned int)));
	if (c == 'x')
		return (ft_hexadecimal_printf(va_arg(list, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_hexadecimal_printf(va_arg(list, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar_printf('%'));
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

/*Variadic functions -  functions that can take
a variable number of arguments.

Library - #include <stdarg.h>

functions:

va_start(va_list ap, argN) 
va_arg(va_list ap, type)
va_copy(va_list dest, va_list src)
va_end(va_list ap)

va_list holds the information needed 
by va_start, va_arg, va_end, and va_copy.
*/