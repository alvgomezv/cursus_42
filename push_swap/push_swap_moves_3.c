/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:31:12 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/10 19:13:40 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	move_both_places_to_the_top(t_stack **stack_1,
			t_stack **stack_2, int i, int j)
{
	int	len_1;
	int	len_2;
	int	value_1;
	int	value_2;

	len_1 = stack_len(stack_1);
	len_2 = stack_len(stack_2);
	value_1 = stack_1[i]->val;
	value_2 = stack_2[j]->val;
	if (i == (len_1 - 1) && j == (len_2 - 1))
		return ;
	if (i < ((len_1 - 1) / 2) && j < ((len_2 - 1) / 2))
		aux_move_1(stack_1, stack_2, value_1, value_2);
	else if (i < ((len_1 - 1) / 2))
		aux_move_2(stack_1, stack_2, value_1, value_2);
	else if (j < ((len_2 - 1) / 2))
		aux_move_3(stack_1, stack_2, value_1, value_2);
	else
	{
		aux_move_4(stack_1, stack_2, value_1, value_2);
	}
}

void	aux_move_1(t_stack **stack_1,
			t_stack **stack_2, int value_1, int value_2)
{
	while (stack_1[stack_len(stack_1) - 1]->val != value_1
		&& stack_2[stack_len(stack_2) - 1]->val != value_2)
		reverse_rotate_both(stack_1, stack_2);
	while (stack_1[stack_len(stack_1) - 1]->val != value_1)
		reverse_rotate(stack_1, 'a');
	while (stack_2[stack_len(stack_2) - 1]->val != value_2)
		reverse_rotate(stack_2, 'b');
}

void	aux_move_2(t_stack **stack_1,
			t_stack **stack_2, int value_1, int value_2)
{
	while (stack_1[stack_len(stack_1) - 1]->val != value_1)
		reverse_rotate(stack_1, 'a');
	while (stack_2[stack_len(stack_2) - 1]->val != value_2)
		rotate(stack_2, 'b');
}

void	aux_move_3(t_stack **stack_1,
			t_stack **stack_2, int value_1, int value_2)
{
	while (stack_1[stack_len(stack_1) - 1]->val != value_1)
		rotate(stack_1, 'a');
	while (stack_2[stack_len(stack_2) - 1]->val != value_2)
		reverse_rotate(stack_2, 'b');
}

void	aux_move_4(t_stack **stack_1,
			t_stack **stack_2, int value_1, int value_2)
{
	while (stack_1[stack_len(stack_1) - 1]->val != value_1
		&& stack_2[stack_len(stack_2) - 1]->val != value_2)
		rotate_both(stack_1, stack_2);
	while (stack_1[stack_len(stack_1) - 1]->val != value_1)
		rotate(stack_1, 'a');
	while (stack_2[stack_len(stack_2) - 1]->val != value_2)
		rotate(stack_2, 'b');
}
