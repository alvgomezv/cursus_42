/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:48:29 by alvgomez          #+#    #+#             */
/*   Updated: 2022/11/15 20:17:57 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	find_moves(t_stack **stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(stack);
	while (stack[i])
	{
		if(i < (len / 2))
			stack[i]->mov = i + 2;
		else
			stack[i]->mov = len - i;
	i++;
	}
}

int	is_it_in_order(t_stack **stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(stack);
	while (stack[i])
	{
		if(stack[i]->pos != len)
			return (0);
	i++;
	len--;
	}
	return (1);
}

void	algorithm(t_stack **stack_1, t_stack **stack_2)
{
	if (is_it_in_order(stack_1) == 0)
	{
		find_moves(stack_1);
		ft_printf("mal");
	}
	else
		ft_printf("bien");
		
}