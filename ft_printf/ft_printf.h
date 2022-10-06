/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:07:18 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/05 18:48:48 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *arg, ...);

int	ft_putchar(int c);

int	ft_putnbr(int nb);

int	ft_putstr(char *str);

int	ft_putnbr_base(int nbr, char *base);

int	ft_hexadecimal(unsigned int nbr, char *base);

int	ft_unsigned_putnbr(unsigned int nb);

int	ft_void_hexadecimal(void *ptr);

#endif