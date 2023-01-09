/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:08:39 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/20 20:55:12 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	resolve_stack_1_of_three(t_stack **stack_1)
{
	if (is_it_in_order_1 (stack_1) == 1)
		return;
	else if (stack_1[0]->val > stack_1[1]->val && stack_1[0]->val > stack_1[2]->val)
		swap(stack_1, 'a');
	else if (stack_1[0]->val < stack_1[1]->val && stack_1[1]->val > stack_1[2]->val
			 && stack_1[0]->val < stack_1[2]->val)
		reverse_rotate(stack_1, 'a');
	else if (stack_1[0]->val > stack_1[1]->val && stack_1[0]->val < stack_1[2]->val 
			&& stack_1[1]->val < stack_1[2]->val)
		rotate(stack_1, 'a');
	else if (stack_1[0]->val < stack_1[1]->val && stack_1[1]->val < stack_1[2]->val)
	{
		swap(stack_1, 'a');
		reverse_rotate(stack_1, 'a');
	}
	else if (stack_1[0]->val < stack_1[1]->val && stack_1[1]->val > stack_1[2]->val)
	{
		swap(stack_1, 'a');
		rotate(stack_1, 'a');
	}
}

void	resolve_stack_1_of_two(t_stack **stack_1)
{
	if (is_it_in_order_1(stack_1) == 1)
		return;
	else
		swap(stack_1, 'a');
}

void	push_all_to_B_but_3(t_stack **stack_1, t_stack **stack_2)
{
	while (stack_1[3])
		push(stack_1, stack_2, 'b');
}

void	algorithm_stack_two_to_stack_one(t_stack **stack_1, t_stack **stack_2, int a, int b)
{
	int	i;
	int	j;
	int move_i;
	int	move_j;

	int moves_total;

	j = 1;
	while (stack_2[0])
	{	
		move_j = 0;
		b = how_many_moves_to_the_top_from_place(stack_2, 0);
			//print_stack(stack_1, 1, 'A');
			//ft_printf("moves A: %d\n", b);
		move_i = find_place_from_pos(stack_1, which_move_3_options(stack_1, stack_2, 0));
		b = b + how_many_moves_to_the_top_from_place(stack_1, move_i);
		moves_total = b;
			//print_stack(stack_2, 1, 'B');
			//ft_printf("moves B: %d\n", how_many_moves_to_the_top_from_place(stack_1, move_i));
		while (j < stack_len(stack_2))
		{
			a = how_many_moves_to_the_top_from_place(stack_2, j);
				//print_stack(stack_1, 1, 'A');
				//ft_printf("moves A: %d\n", a);
			i = find_place_from_pos(stack_1, which_move_3_options(stack_1, stack_2, j));
			a = a + how_many_moves_to_the_top_from_place(stack_1, i);
				//print_stack(stack_2, 1, 'B');
				//ft_printf("moves B: %d\n", how_many_moves_to_the_top_from_place(stack_1, i));
			if (a < b)
			{
				move_i = i;
				move_j = j;
				moves_total = a;
			}
			j++;
		}
			//print_stack(stack_1, 1, 'A');
			//print_stack(stack_2, 1, 'B');
			//ft_printf("final move A: %d\n", stack_1[move_i]->val);
			//ft_printf("final move B: %d -> %d moves total\n", stack_2[move_j]->val, moves_total);
		move_place_to_the_top(stack_1, move_i, 'a');
			//print_stack(stack_1, 1, 'A');
			//print_stack(stack_2, 1, 'B');
		move_place_to_the_top(stack_2, move_j, 'b');
			//print_stack(stack_1, 1, 'A');
			//print_stack(stack_2, 1, 'B');
		push(stack_2, stack_1, 'a');
			//print_stack(stack_1, 1, 'A');
			//print_stack(stack_2, 1, 'B');
	}
}

void	algorithm(t_stack **stack_1, t_stack **stack_2)
{
	int	a;
	int b;
	int i;

	a = 0;
	b = 0;
	if (stack_len(stack_1) == 2)
		resolve_stack_1_of_two(stack_1);
	else if (stack_len(stack_1) == 3)
		resolve_stack_1_of_three(stack_1);
	else
	{
		push_all_to_B_but_3(stack_1, stack_2);
		//print_stack(stack_1, 1, 'A');
		//print_stack(stack_2, 1, 'B');
		resolve_stack_1_of_three(stack_1);
		//print_stack(stack_1, 1, 'A');
		//print_stack(stack_2, 1, 'B');
		algorithm_stack_two_to_stack_one(stack_1, stack_2, a, b);
		i = find_place_from_pos(stack_1, find_lowest_pos(stack_1));
		move_place_to_the_top(stack_1, i, 'a');
		//print_stack(stack_1, 1, 'A');
		//print_stack(stack_2, 1, 'B');
	}
}

// algorithm that works -> only checks where to put the last one of stack_2 in stack_1
/*void	algorithm(t_stack **stack_1, t_stack **stack_2)
{
	int	i;

	if (stack_len(stack_1) == 2)
		resolve_stack_1_of_two(stack_1);
	else if (stack_len(stack_1) == 3)
		resolve_stack_1_of_three(stack_1);
	else
	{
		push_all_to_B_but_3(stack_1, stack_2);
		resolve_stack_1_of_three(stack_1);
		while (stack_2[0])
		{
			i = find_place_from_pos(stack_1, which_move_3_options(stack_1, stack_2, (stack_len(stack_2) - 1)));
			move_place_to_the_top(stack_1, i, 'a');
			push(stack_2, stack_1, 'a');
		}
		i = find_place_from_pos(stack_1, find_lowest_pos(stack_1));
		move_place_to_the_top(stack_1, i, 'a');
	}
}*/