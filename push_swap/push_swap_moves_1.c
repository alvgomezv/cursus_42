/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:22:45 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/16 15:18:34 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	swap(t_stack **stack, char x, int write)
{
	t_stack	*aux;
	int		len;

	len = stack_len(stack) - 1;
	aux = stack[len];
	stack[len] = stack[len - 1];
	stack[len - 1] = aux;
	if (write == 1)
		ft_printf("s%c\n", x);
}

void	push(t_stack **stack_1, t_stack **stack_2, char x, int write)
{
	int	len_1;
	int	len_2;

	len_1 = stack_len(stack_1);
	len_2 = stack_len(stack_2);
	stack_2[len_2] = stack_1[len_1 - 1];
	stack_1[len_1 - 1] = 0;
	if (write == 1)
		ft_printf("p%c\n", x);
}

void	rotate(t_stack **stack, char x, int write)
{
	int		len;
	int		i;
	t_stack	*temp_1;
	t_stack	*temp_2;

	i = 0;
	len = stack_len(stack) - 1;
	temp_1 = stack[len];
	while (i <= len)
	{
		temp_2 = stack[i];
		stack[i] = temp_1;
		temp_1 = temp_2;
		i++;
	}
	if (write == 1)
		ft_printf("r%c\n", x);
}

void	reverse_rotate(t_stack **stack, char x, int write)
{
	int		len;
	t_stack	*temp_1;
	t_stack	*temp_2;

	len = stack_len(stack) - 1;
	temp_1 = stack[0];
	while (len >= 0)
	{
		temp_2 = stack[len];
		stack[len] = temp_1;
		temp_1 = stack[len - 1];
		if (len > 0)
			stack[len - 1] = temp_2;
		len -= 2;
	}
	if (write == 1)
		ft_printf("rr%c\n", x);
}

void	move_place_to_the_top(t_stack **stack, int i, char x)
{
	int	len;
	int	value;

	len = stack_len(stack);
	value = stack[i]->val;
	if (i == (len - 1))
		return ;
	else if (i < ((len - 1) / 2))
	{
		while (stack[stack_len(stack) - 1]->val != value)
			reverse_rotate(stack, x, 1);
	}
	else
	{
		while (stack[stack_len(stack) - 1]->val != value)
			rotate(stack, x, 1);
	}
}
