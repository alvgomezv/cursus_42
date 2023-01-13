/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:08:39 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/13 12:06:44 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	resolve_stack_1_of_three(t_stack **stack_1)
{
	if (is_it_in_order_1 (stack_1) == 1)
		return ;
	else if (stack_1[0]->val > stack_1[1]->val
		&& stack_1[0]->val > stack_1[2]->val)
		swap(stack_1, 'a', 1);
	else if (stack_1[0]->val < stack_1[1]->val
		&& stack_1[1]->val > stack_1[2]->val
		&& stack_1[0]->val < stack_1[2]->val)
		reverse_rotate(stack_1, 'a', 1);
	else if (stack_1[0]->val > stack_1[1]->val
		&& stack_1[0]->val < stack_1[2]->val
		&& stack_1[1]->val < stack_1[2]->val)
		rotate(stack_1, 'a', 1);
	else if (stack_1[0]->val < stack_1[1]->val
		&& stack_1[1]->val < stack_1[2]->val)
	{
		swap(stack_1, 'a', 1);
		reverse_rotate(stack_1, 'a', 1);
	}
	else if (stack_1[0]->val < stack_1[1]->val
		&& stack_1[1]->val > stack_1[2]->val)
	{
		swap(stack_1, 'a', 1);
		rotate(stack_1, 'a', 1);
	}
}

void	resolve_stack_1_of_two(t_stack **stack_1)
{
	if (is_it_in_order_1(stack_1) == 1)
		return ;
	else
		swap(stack_1, 'a', 1);
}

void	push_all_to_b_but_3_smallest_half_first(t_stack **stack_1,
			t_stack **stack_2)
{
	int	len;
	int	i;

	len = stack_len(stack_1);
	i = 0;
	while (i < (len / 2) && stack_1[3])
	{
		if (stack_1[stack_len(stack_1) - 1]->pos <= (len / 2))
		{
			push(stack_1, stack_2, 'b', 1);
			i++;
		}
		else
			rotate (stack_1, 'a', 1);
	}
	while (stack_1[3])
		push(stack_1, stack_2, 'b', 1);
}

void	algorithm_stack_two_to_stack_one(t_stack **stack_1,
			t_stack **stack_2, int move_i, int move_j)
{
	int	*i;
	int	*j;

	i = &move_i;
	j = &move_j;
	while (stack_2[0])
	{	
		aux_algorithm(stack_1, stack_2, i, j);
		move_both_places_to_the_top(stack_1, stack_2, move_i, move_j);
		push(stack_2, stack_1, 'a', 1);
	}
}

void	aux_algorithm(t_stack **stack_1,
			t_stack **stack_2, int *move_i, int *move_j)
{
	int	i;
	int	j;
	int	a;
	int	b;

	j = 1;
	*move_j = 0;
	*move_i = find_place_from_pos(stack_1,
			which_move_3_options(stack_1, stack_2, 0));
	b = how_many_moves_to_the_top_from_place(stack_2, 0)
		+ how_many_moves_to_the_top_from_place(stack_1, *move_i);
	while (j < stack_len(stack_2))
	{
		a = how_many_moves_to_the_top_from_place(stack_2, j);
		i = find_place_from_pos(stack_1,
				which_move_3_options(stack_1, stack_2, j));
		a = a + how_many_moves_to_the_top_from_place(stack_1, i);
		if (a < b)
		{
			*move_i = i;
			*move_j = j;
			b = a;
		}
		j++;
	}
}
