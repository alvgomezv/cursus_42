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

int	find_lowest_pos(t_stack **stack)
{
	int pos;
	int	i;

	pos = stack_len(stack);
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
	//while (is_it_in_order(stack_1) == 0)

		if (stack_1[stack_len(stack_1) - 1]->val > stack_1[stack_len(stack_1) - 2]->val)
			swap(stack_1);
		else
		{
			find_moves(stack_1);
			pos = find_lowest_pos(stack_1);
			if (pos == stack_len(stack_1))
				push(stack_1, stack_2, stack_len(stack_1));
			else
			{
				a = find_the_position(stack_1, pos);
				b = find_the_position(stack_1, pos + 1);
				if (stack_1[a]->mov < stack_1[b]->mov)
				{
					if (a < (stack_len(stack_1) / 2))
						rotate(stack_1);
					else
						reverse_rotate(stack_1);
				}
				else
				{
					if (b < (stack_len(stack_1) / 2))
						rotate(stack_1);
					else
						reverse_rotate(stack_1);
				}
			}
		}	
}