/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:17 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/10 16:33:29 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	swap_both(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*aux;
	int		len;

	len = stack_len(stack_1) - 1;
	aux = stack_1[len];
	stack_1[len] = stack_1[len - 1];
	stack_1[len - 1] = aux;
	swap(stack_2, 's');
}

void	rotate_both(t_stack **stack_1, t_stack **stack_2)
{
	int		len;
	int		i;
	t_stack	*temp_1;
	t_stack	*temp_2;

	i = 0;
	len = stack_len(stack_1) - 1;
	temp_1 = stack_1[len];
	while (i <= len)
	{
		temp_2 = stack_1[i];
		stack_1[i] = temp_1;
		temp_1 = temp_2;
		i++;
	}
	rotate(stack_2, 'r');
}

void	reverse_rotate_both(t_stack **stack_1, t_stack **stack_2)
{
	int		len;
	t_stack	*temp_1;
	t_stack	*temp_2;

	len = stack_len(stack_1) - 1;
	temp_1 = stack_1[0];
	while (len >= 0)
	{
		temp_2 = stack_1[len];
		stack_1[len] = temp_1;
		temp_1 = stack_1[len - 1];
		if (len > 0)
			stack_1[len - 1] = temp_2;
		len -= 2;
	}
	reverse_rotate(stack_2, 'r');
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
