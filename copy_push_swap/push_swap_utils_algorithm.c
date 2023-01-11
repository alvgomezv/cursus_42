/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:48:29 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/11 17:10:03 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	move_both_places_to_the_top(t_stack **stack_1, t_stack **stack_2, int i, int j)
{
	int	len_1;
	int	len_2;
	int value_1;
	int value_2;

	len_1 = stack_len(stack_1);
	len_2 = stack_len(stack_2);
	//ft_printf("%d\n", len);
	value_1 = stack_1[i]->val;
	value_2 = stack_2[j]->val;
	if (i == (len_1 - 1) && j == (len_2 - 1))
		return;
	if (i < ((len_1 - 1) / 2) && j < ((len_2 - 1) / 2))
	{
		while(stack_1[stack_len(stack_1) - 1]->val != value_1 && stack_2[stack_len(stack_2) - 1]->val != value_2)
			reverse_rotate_both(stack_1, stack_2);
		while(stack_1[stack_len(stack_1) - 1]->val != value_1)
			reverse_rotate(stack_1, 'a');
		while(stack_2[stack_len(stack_2) - 1]->val != value_2)
			reverse_rotate(stack_2, 'b');
	}
	else if (i < ((len_1 - 1) / 2))
	{
		while(stack_1[stack_len(stack_1) - 1]->val != value_1)
			reverse_rotate(stack_1, 'a');
		while(stack_2[stack_len(stack_2) - 1]->val != value_2)
			rotate(stack_2, 'b');
	}
	else if (j < ((len_2 - 1) / 2))
	{
		while(stack_1[stack_len(stack_1) - 1]->val != value_1)
			rotate(stack_1, 'a');
		while(stack_2[stack_len(stack_2) - 1]->val != value_2)
			reverse_rotate(stack_2, 'b');
	}
	else
	{
		while(stack_1[stack_len(stack_1) - 1]->val != value_1 && stack_2[stack_len(stack_2) - 1]->val != value_2)
			rotate_both(stack_1, stack_2);
		while(stack_1[stack_len(stack_1) - 1]->val != value_1)
			rotate(stack_1, 'a');
		while(stack_2[stack_len(stack_2) - 1]->val != value_2)
			rotate(stack_2, 'b');
	}
}

void	move_place_to_the_top(t_stack **stack, int i, char x)
{
	int	len;
	int value;

	len = stack_len(stack);
	//ft_printf("%d\n", len);
	value = stack[i]->val;
	if (i == (len - 1))
		return;
	else if (i < ((len - 1) / 2))
	{
		while(stack[stack_len(stack) - 1]->val != value)
			reverse_rotate(stack, x);
	}
	else
	{
		while(stack[stack_len(stack) - 1]->val != value)
			rotate(stack, x);
	}
}

int	how_many_moves_to_the_top_from_place(t_stack **stack, int i)
{
	int	len;
	int j;

	len = stack_len(stack);
	//ft_printf("%d\n", len);
	j = 0;
	if (i == (len - 1))
		return (j);
	else if (i < ((len - 1) / 2))
	{
		while(i >= 0)
		{
			i--;
			j++;
		}
	}
	else
	{
		while(i < (len - 1))
		{
			i++;
			j++;
		}
	}
	return (j);
}

int	which_move_3_options(t_stack **stack_1, t_stack **stack_2, int j)
{
	int i;
	int	pos_to_move;
	int aux;

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
		i = 0;
		if (pos_to_move < 0)
		{
			while (i < stack_len(stack_1))
			{
				if ((stack_1[i]->pos - stack_2[j]->pos) > 1)
				{
					pos_to_move = stack_1[i]->pos; 
					aux = (stack_1[i]->pos - stack_2[j]->pos);
				}
				i++;
			}
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
		}
	}	
	return(pos_to_move);
}

// algorithm that works -> only checks where to put the last one of stack_2 in stack_1
/*int	find_pos_to_move(t_stack **stack_1, t_stack **stack_2)
{
	int i;
	int	pos_to_move;
	int aux;

	i = 0;
	pos_to_move = -1;
	if (stack_2[stack_len(stack_2) - 1]->pos > find_highest_pos(stack_1))
		pos_to_move = find_lowest_pos(stack_1);
	else
	{
		while (i < stack_len(stack_1))
		{
			if ((stack_1[i]->pos - stack_2[stack_len(stack_2) - 1]->pos) == 1)
				pos_to_move = stack_1[i]->pos;
			i++;
		}
		i = 0;
		if (pos_to_move < 0)
		{
			while (i < stack_len(stack_1))
			{
				if ((stack_1[i]->pos - stack_2[stack_len(stack_2) - 1]->pos) > 1)
				{
					pos_to_move = stack_1[i]->pos; 
					aux = (stack_1[i]->pos - stack_2[stack_len(stack_2) - 1]->pos);
				}
				i++;
			}
			i = 0;
			while (i < stack_len(stack_1))
			{
				if ((stack_1[i]->pos - stack_2[stack_len(stack_2) - 1]->pos) > 1)
				{
					if ((stack_1[i]->pos - stack_2[stack_len(stack_2) - 1]->pos) < aux)
					{
						pos_to_move = stack_1[i]->pos;
						aux = (stack_1[i]->pos - stack_2[stack_len(stack_2) - 1]->pos);
					}
				}
				i++;
			}
		}
	}	
	return(pos_to_move);
}*/

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