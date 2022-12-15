/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_push_swap_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:08:39 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/15 16:13:31 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	stack_of_3(t_stack **stack, char x)
{
	while (is_it_in_order_1(stack) == 0)
	{
		if (stack[0]->val > stack[1]->val && stack[0]->val > stack[2]->val)
			swap(stack, x);
		else if (stack[0]->val < stack[1]->val && stack[1]->val > stack[2]->val)
			reverse_rotate(stack, x);
		else if (stack[0]->val > stack[1]->val && stack[0]->val < stack[2]->val)
			rotate(stack, x);
		else if (stack[0]->val < stack[1]->val && stack[1]->val < stack[2]->val)
		{
			swap(stack, x);
			reverse_rotate(stack, x);
		}
		else if (stack[0]->val < stack[1]->val && stack[1]->val > stack[2]->val)
		{
			swap(stack, x);
			rotate(stack, x);
		}
	}
}



void	old_algorithm(t_stack **stack_1, t_stack **stack_2)
{
	int	pos;
	int	a;
	int	b;

	pos = 0;
	while (is_it_in_order_1(stack_1) == 0 || is_it_in_order_2(stack_2) == 0)
	{
		//ft_printf("len = %d\n", stack_len(stack_1));
		if (stack_len(stack_2) >= 2)
		{
			if ((stack_2[stack_len(stack_2) - 1]->val
					< stack_2[stack_len(stack_2) - 2]->val)
				&& (stack_1[stack_len(stack_1) - 1]->val
					> stack_1[stack_len(stack_1) - 2]->val))
			{
				swap_both(stack_1, stack_2);
				//print_stack(stack_1, 1);
				//print_stack(stack_2, 1);
			}
			else if (stack_2[stack_len(stack_2) - 1]->val
				< stack_2[stack_len(stack_2) - 2]->val)
				swap(stack_2, 'b');
		}
		if (stack_len(stack_1) == 3)
		{
			stack_of_3(stack_1, 'a');
			//print_stack(stack_1, 1);clear
			
			//print_stack(stack_2, 1);
		}
		else if (stack_1[stack_len(stack_1) - 1]->val
			> stack_1[stack_len(stack_1) - 2]->val)
		{
			swap(stack_1, 'a');
			//print_stack(stack_1, 1);
			//print_stack(stack_2, 1);
		}
		else
		{
			find_moves(stack_1);
			pos = find_lowest_pos(stack_1);
			//ft_printf("pos = %d\n", pos);
			if (pos == stack_1[stack_len(stack_1) - 1]->pos)
			{
				push(stack_1, stack_2, 'b');
				//print_stack(stack_1, 1);
				//print_stack(stack_2, 1);		
			}
			else if (!stack_2[0] || pos > stack_2[stack_len(stack_2) - 1]->pos)
			{
				if ((pos + 1) == stack_1[stack_len(stack_1) - 1]->pos)
				{
					push(stack_1, stack_2, 'b');
					//print_stack(stack_1, 1);
					//print_stack(stack_2, 1);			
				}
				else
				{
					a = find_the_position(stack_1, pos);
					//ft_printf("a = %d\n", a);
					b = find_the_position(stack_1, pos + 1);
					//ft_printf("b = %d\n", b);
					if (stack_1[a]->mov <= stack_1[b]->mov)
					{
						if ((a + 1) <= (stack_len(stack_1) / 2))
						{
							reverse_rotate(stack_1, 'a');
							//ft_printf("1\n");
							//print_stack(stack_1, 1);
							//print_stack(stack_2, 1);
						}
						else
						{
							rotate(stack_1, 'a');
							//ft_printf("2\n");
							//print_stack(stack_1, 1);
							//print_stack(stack_2, 1);
						}
					}
					else
					{
						if ((b + 1) <= (stack_len(stack_1) / 2))
						{
							reverse_rotate(stack_1, 'a');
							//ft_printf("3\n");
							//print_stack(stack_1, 1);
							//print_stack(stack_2, 1);
						}
						else
						{
							rotate(stack_1, 'a');
							//ft_printf("4\n");
							//print_stack(stack_1, 1);
							//print_stack(stack_2, 1);
						}
					}
				}
			}
			else
			{
				a = find_the_position(stack_1, pos);
				//ft_printf("a = %d\n", a);
				if ((a + 1) <= (stack_len(stack_1) / 2))
				{
					reverse_rotate(stack_1, 'a');
					//ft_printf("5\n");
					//print_stack(stack_1, 1);
					//print_stack(stack_2, 1);
				}
				else
				{
					rotate(stack_1, 'a');
					//ft_printf("6\n");
					//print_stack(stack_1, 1);
					//print_stack(stack_2, 1);
				}
			}
		}
	}
	while (stack_2[0])
	{
		if (is_it_in_order_1(stack_1) == 0)
		{
			swap(stack_1, 'a');
			//print_stack(stack_1, 1);
			//print_stack(stack_2, 1);
		}
		push(stack_2, stack_1, 'a');
		//print_stack(stack_1, 1);
		//print_stack(stack_2, 1);
	}	
}
