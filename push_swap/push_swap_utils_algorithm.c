/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:48:29 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/15 17:52:46 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

//OLD
void	find_moves(t_stack **stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(stack);
	while (stack[i])
	{
		if (i < (len / 2))
			stack[i]->mov = i + 2;
		else
			stack[i]->mov = len - i;
	i++;
	}
}

int	find_position_to_move(t_stack **stack_1, t_stack **stack_2)
{
	
}

int	is_it_in_order_1(t_stack **stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(stack);
	while (stack[i + 1])
	{
		if (stack[i]->pos < stack[i + 1]->pos)
			return (0);
	i++;
	}
	return (1);
}

int	is_it_in_order_2(t_stack **stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(stack);
	while (stack[i + 1])
	{
		if (stack[i]->pos > stack[i + 1]->pos)
			return (0);
	i++;
	}
	return (1);
}

//OLD
int	find_lowest_pos(t_stack **stack)
{
	int	pos;
	int	i;

	pos = stack[0]->pos;
	i = 0;
	while (stack[i])
	{
		if (stack[i]->pos < pos)
			pos = stack[i]->pos;
	i++;
	}
	return (pos);
}

//OLD
int	find_the_position(t_stack **stack, int pos)
{
	int	i;

	i = 0;
	while (stack[i]->pos != pos)
			i++;
	return (i);
}