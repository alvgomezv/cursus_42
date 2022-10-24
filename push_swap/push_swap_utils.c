/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:07:14 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/24 15:59:14 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	*to_zero(int n)
{
	int i;
	int *array;

	i = 0;
	array = (int *)malloc(sizeof(int) * n);
	while (i < n)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

int	array_len(int *array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		i++;
	}
	return(i);
}