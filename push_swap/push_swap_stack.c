/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:07:14 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/14 12:01:04 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

t_stack	**create_stack(int n)
{
	int		i;
	t_stack	**stack;

	i = 0;
	stack = (t_stack **)malloc(sizeof(t_stack *) * (n + 1));
	while (i < n)
	{
		stack[i] = (t_stack *)malloc(sizeof(t_stack));
		i++;
	}
	stack[i] = 0;
	return (stack);
}

t_stack	**create_stack_to_zero(int n)
{
	int		i;
	t_stack	**stack;

	i = 0;
	stack = (t_stack **)malloc(sizeof(t_stack *) * (n + 1));
	while (i <= n)
	{
		stack[i] = 0;
		i++;
	}
	return (stack);
}

int	stack_len(t_stack **stack)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
	{
		i++;
	}
	return (i);
}

int	is_it_a_string(char *str)
{
	int	i;

	i = 0;
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i++;
	else
		return (1);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}
