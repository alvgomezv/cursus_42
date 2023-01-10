/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algorithm_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:35:24 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/10 16:35:53 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	find_lowest_pos(t_stack **stack)
{
	int	pos;
	int	i;

	pos = stack[0]->pos;
	i = 0;
	while (stack[i])
	{
		if (stack[i]->pos < pos)
			pos = stack[i]->pos;
	i++;
	}
	return (pos);
}

int	find_highest_pos(t_stack **stack)
{
	int	pos;
	int	i;

	pos = stack[0]->pos;
	i = 0;
	while (stack[i])
	{
		if (stack[i]->pos > pos)
			pos = stack[i]->pos;
	i++;
	}
	return (pos);
}

int	find_place_from_pos(t_stack **stack, int pos)
{
	int	i;

	i = 0;
	while (stack[i]->pos != pos)
			i++;
	return (i);
}
