/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:07:14 by alvgomez          #+#    #+#             */
/*   Updated: 2022/11/10 17:31:24 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

t_value	*to_zero(int n)
{
	int		i;
	t_value	*array;

	i = 0;
	array = (t_value *)malloc(sizeof(t_value) * n);
	while (i < n)
	{
		array[i].value = 0;
		array[i].position = i;
		i++;
	}
	return (array);
}

int	array_len(t_value *array)
{
	int	i;

	i = 0;
	while (array[i].value != 0)
	{
		i++;
	}
	return (i);
}
