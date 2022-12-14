/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:22:45 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/14 15:46:07 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	swap(t_stack **stack, char x)
{
	t_stack	*aux;
	int		len;

	len = stack_len(stack) - 1;
	aux = stack[len];
	stack[len] = stack[len - 1];
	stack[len - 1] = aux;
	ft_printf("s%c\n", x);
}

void	push(t_stack **stack_1, t_stack **stack_2, int max_len, char x)
{
	int	len_1;
	int	len_2;

	len_1 = stack_len(stack_1);
	len_2 = stack_len(stack_2);
	stack_2[len_2] = stack_1[len_1 - 1];
	stack_1[len_1 - 1] = 0;
	ft_printf("p%c\n", x);
}

void	rotate(t_stack **stack, char x)
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
	ft_printf("r%c\n", x);
}

void	reverse_rotate(t_stack **stack, char x)
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
	ft_printf("rr%c\n", x);
}
