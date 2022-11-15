/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:44:22 by alvgomez          #+#    #+#             */
/*   Updated: 2022/11/15 21:09:12 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	repeted(t_stack **stack, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (stack[i]->val == stack[pos]->val)
			return (1);
	i++;
	}
	return (0);
}

void	find_positions(t_stack **stack, int len)
{
	int	*array;
	int	i;
	int	j;

	i = 0;
	j = 0;
	array = (int *)malloc(sizeof(int) * len);
	while (stack[i])
	{
		array[i] = stack[i]->val;
		i++;
	}
	put_in_order(array, len);
	i = 0;
	while (i < len)
	{
		while (j < len)
		{
			if (array[i] == stack[j]->val)
				stack[j]->pos = i + 1;
		j++;
		}
	j = 0;
	i++;
	}
}	

void	put_in_order(int *array, int len)
{
	int	i;
	int	j;
	int	rev;

	i = 0;
	j = 1;
	while (i < len)
	{
		while (j < len)
		{
			if (array[i] > array[j])
			{
				rev = array[j];
				array[j] = array[i];
				array[i] = rev;
			}
			j++;
		}
	i++;
	j = i + 1;
	}
}
