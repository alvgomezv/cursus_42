/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:48:29 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/20 20:56:43 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

//OLD
void	move_i_to_the_top(t_stack **stack, int i)
{
	int	len;
	int value;

	len = stack_len(stack);
	//ft_printf("%d\n", len);
	value = stack[i]->val;
	if (i == (len - 1))
		return;
	else if (i < ((len - 1) / 2))
	{
		while(stack[stack_len(stack) - 1]->val != value)
			reverse_rotate(stack, 'a');
	}
	else
	{
		while(stack[stack_len(stack) - 1]->val != value)
			rotate(stack, 'a');
	}
}

int	find_position_to_move(t_stack **stack_1, t_stack **stack_2)
{
	int	pos_to_move;
	int i;
	
	i = 0;
//	if (stack_2[stack_len(stack_2) - 1]->pos > find_highest_pos(stack_1))
	pos_to_move = find_lowest_pos(stack_1);
	while (i < stack_len(stack_1))
	{
		if ((stack_2[stack_len(stack_2) - 1]->pos - stack_1[i]->pos) == 1)
			pos_to_move = stack_1[i]->pos;
		i++;
	}	
	return(pos_to_move);
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

/*int	find_highest_pos(t_stack **stack)
{
	int	pos;
	int	i;

	pos = stack[0]->pos;
	i = 0;
	while (stack[i])
	{
		if (stack[i]->pos > pos)
			pos = stack[i]->pos;
	i++;
	}
	return (pos);
}*/

int	find_the_position(t_stack **stack, int pos)
{
	int	i;

	i = 0;
	while (stack[i]->pos != pos)
			i++;
	return (i);
}