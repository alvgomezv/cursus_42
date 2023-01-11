/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:17:22 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/18 11:23:59 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int argument)
{
	if ((argument >= 48 && argument <= 57)
		|| (argument >= 65 && argument <= 90)
		|| (argument >= 97 && argument <= 122))
		return (1);
	else
		return (0);
}
