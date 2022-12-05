/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:48:29 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/05 18:23:02 by alvgomez         ###   ########.fr       */
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
	while (stack[i + 1])
	{
		if(stack[i]->pos < stack[i + 1]->pos)
			return (0);
	i++;
	}
	return (1);
}

int	find_lowest_pos(t_stack **stack)
{
	int pos;
	int	i;

	pos = stack[0]->pos;
	//ft_printf("%d\n", pos);
	i = 0;
	while (stack[i])
	{
		if (stack[i]->pos < pos)
			pos = stack[i]->pos;
	i++;
	}
	return (pos);
}

int	find_the_position(t_stack **stack, int pos)
{
	int	i;

	i = 0;
	while (stack[i]->pos != pos)
			i++;
	return (i);
}

void	algorithm(t_stack **stack_1, t_stack **stack_2)
{
	int pos;
	int a;
	int b;

	pos = 0;
	while (is_it_in_order(stack_1) == 0)
	{
		ft_printf("len = %d\n", stack_len(stack_1));
		if (stack_1[stack_len(stack_1) - 1]->val > stack_1[stack_len(stack_1) - 2]->val)
		{
			swap(stack_1);
			print_stack(stack_1, 1);
			print_stack(stack_2, 1);
		}
		else
		{
			find_moves(stack_1);
			pos = find_lowest_pos(stack_1);
			ft_printf("pos = %d\n", pos);
			if (pos == stack_1[stack_len(stack_1) - 1]->pos ||
					(pos + 1) == stack_1[stack_len(stack_1) - 1]->pos)
			{
				push(stack_1, stack_2, stack_len(stack_1));
				print_stack(stack_1, 1);
				print_stack(stack_2, 1);		
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
						reverse_rotate(stack_1);
						ft_printf("1\n");
						print_stack(stack_1, 1);
						print_stack(stack_2, 1);
					}
					else
					{
						rotate(stack_1);
						ft_printf("2\n");
						print_stack(stack_1, 1);
						print_stack(stack_2, 1);
					}
				}
				else
				{
					if ((b + 1) <= (stack_len(stack_1) / 2))
					{
						reverse_rotate(stack_1);
						ft_printf("3\n");
						print_stack(stack_1, 1);
						print_stack(stack_2, 1);
					}
					else
					{
						rotate(stack_1);
						ft_printf("4\n");
						print_stack(stack_1, 1);
						print_stack(stack_2, 1);
					}
				}
			}
		}
	}	
}