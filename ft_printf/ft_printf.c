/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:44:10 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/04 18:48:57 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	what_to_print(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, char)));
	if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	//if (c == 'p')
		//return (ft_hexadecimal(va_arg(list, void *)));
	//if (c == 'd')
		//return (ft_putstr(va_arg(list, char *)));
	if (c == 'i')
		return (ft_putnbr(va_arg(list, char *)));
	//if (c == 'u')
		//return (ft_putstr(va_arg(list, char *)));
	//if (c == 'x')
		//return (ft_putstr(va_arg(list, char *)));
	//if (c == 'X')
		//return (ft_putstr(va_arg(list, char *)));
	if (c == '%')
		return (ft_putchar('%'));
}

int	ft_printf(const char *arg, ...)
{
	va_list	list;
	int		a;
	int		b;
	int		cont;

	va_start(list, arg);
	cont = 0;
	b = 0;
	while (arg[a] != '\0')
	{
		if (arg[a] == '%')
		{
			a++;
			b = what_to_print(arg[a], list);
			if (b == -1)
				return (-1);
			cont = cont + b - 2;
		}
	a++;
	}
	cont = cont + a;
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