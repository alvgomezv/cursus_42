/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:08:39 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/10 13:55:03 by alvgomez         ###   ########.fr       */
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

void	push_all_to_B_but_3_smallest_half_first(t_stack **stack_1, t_stack **stack_2)
{
	int	len;
	int	i;

	len = stack_len(stack_1);
	i = 0;
	//ft_printf("len: %d\n", len);
	//ft_printf("len / 2: %d\n", len / 2);
	while (i < (len / 2) && stack_1[3])
	{
		if (stack_1[stack_len(stack_1) - 1]->pos <= (len / 2))
		{
			push(stack_1, stack_2, 'b');
			i++;
		}
		else 
			rotate (stack_1, 'a');
	}
	while (stack_1[3])
		push(stack_1, stack_2, 'b');
}

void	algorithm_stack_two_to_stack_one(t_stack **stack_1, t_stack **stack_2, int a, int b)
{
	int	i;
	int	j;
	int move_i;
	int	move_j;

	//int moves_total;

	while (stack_2[0])
	{	
		j = 1;
		move_j = 0;
		b = how_many_moves_to_the_top_from_place(stack_2, 0);
			//print_stack(stack_1, 1, 'A');
			//ft_printf("moves B: %d\n", b);
		move_i = find_place_from_pos(stack_1, which_move_3_options(stack_1, stack_2, 0));
		b = b + how_many_moves_to_the_top_from_place(stack_1, move_i);
		//moves_total = b;
			//print_stack(stack_2, 1, 'B');
			//ft_printf("moves A: %d\n", how_many_moves_to_the_top_from_place(stack_1, move_i));
			//ft_printf("moves total: %d\n", b);
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
				b = a;
				//moves_total = a;
			}
			j++;
		}
			//ft_printf("j: %d\n", j);
			//print_stack(stack_1, 1, 'A');
			//print_stack(stack_2, 1, 'B');
			//ft_printf("final move B: %d -> %d moves total\n", stack_2[move_j]->val, moves_total);
			//ft_printf("moves A: %d\nmoves B:%d \nmoves total: %d\n", how_many_moves_to_the_top_from_place(stack_1, move_i),how_many_moves_to_the_top_from_place(stack_2, move_j) , moves_total);
		//move_place_to_the_top(stack_1, move_i, 'a');
			//print_stack(stack_1, 1, 'A');
			//print_stack(stack_2, 1, 'B');
		//move_place_to_the_top(stack_2, move_j, 'b');
			//print_stack(stack_1, 1, 'A');
			//print_stack(stack_2, 1, 'B');
			//ft_printf("i: %d j: %d\n", move_i, move_j);
		move_both_places_to_the_top(stack_1, stack_2, move_i, move_j);
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
		//push_all_to_B_but_3(stack_1, stack_2);
			//print_stack(stack_1, 2, 'A');
			//print_stack(stack_2, 2, 'B');
		push_all_to_B_but_3_smallest_half_first(stack_1, stack_2);
		resolve_stack_1_of_three(stack_1);
			//print_stack(stack_1, 1, 'A');
			//print_stack(stack_2, 1, 'B');
		algorithm_stack_two_to_stack_one(stack_1, stack_2, a, b);
		i = find_place_from_pos(stack_1, find_lowest_pos(stack_1));
		move_place_to_the_top(stack_1, i, 'a');
			//print_stack(stack_1, 2, 'A');
			//print_stack(stack_2, 2, 'B');
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