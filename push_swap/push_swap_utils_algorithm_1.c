/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algorithm_1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:48:29 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/16 15:32:42 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	how_many_moves_to_the_top_from_place(t_stack **stack, int i)
{
	int	len;
	int	j;

	len = stack_len(stack);
	j = 0;
	if (i == (len - 1))
		return (j);
	else if (i < ((len - 1) / 2))
	{
		while (i >= 0)
		{
			i--;
			j++;
		}
	}
	else
	{
		while (i < (len - 1))
		{
			i++;
			j++;
		}
	}
	return (j);
}

int	aux_which_move_3_options_1(t_stack **stack_1,
		t_stack **stack_2, int pos_to_move, int j)
{
	int	i;
	int	aux;

	pos_to_move = -1;
	i = 0;
	while (i < stack_len(stack_1))
	{
		if ((stack_1[i]->pos - stack_2[j]->pos) > 1)
		{
			pos_to_move = stack_1[i]->pos;
			aux = (stack_1[i]->pos - stack_2[j]->pos);
		}
		i++;
	}
	return (pos_to_move);
}

int	aux_which_move_3_options_2(t_stack **stack_1,
		t_stack **stack_2, int pos_to_move, int j)
{
	int	i;
	int	aux;

	i = 0;
	while (i < stack_len(stack_1))
	{
		if ((stack_1[i]->pos - stack_2[j]->pos) > 1)
		{
			if ((stack_1[i]->pos - stack_2[j]->pos) < aux)
			{
				pos_to_move = stack_1[i]->pos;
				aux = (stack_1[i]->pos - stack_2[j]->pos);
			}
		}
		i++;
	}
	return (pos_to_move);
}

int	which_move_3_options(t_stack **stack_1, t_stack **stack_2, int j)
{
	int	i;
	int	pos_to_move;

	i = 0;
	pos_to_move = -1;
	if (stack_2[j]->pos > find_highest_pos(stack_1))
		pos_to_move = find_lowest_pos(stack_1);
	else
	{
		while (i < stack_len(stack_1))
		{
			if ((stack_1[i]->pos - stack_2[j]->pos) == 1)
				pos_to_move = stack_1[i]->pos;
			i++;
		}
		if (pos_to_move < 0)
		{
			pos_to_move = aux_which_move_3_options_1(stack_1, stack_2,
					pos_to_move, j);
			pos_to_move = aux_which_move_3_options_2(stack_1, stack_2,
					pos_to_move, j);
		}
	}
	return (pos_to_move);
}

void	there_is_an_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
