/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:18:13 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/14 13:50:03 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

static int	number_count(char *s)
{
	int	number_count;

	number_count = 0;
	while (*s)
	{
		if (*s == ' ')
			s++;
		else
		{
			if ((*s >= '0' && *s <= '9')
				|| *s == '-')
				number_count++;
			else
				Error();
			s++;
			while (*s && *s != ' ')
			{
				if (*s >= '0' && *s <= '9')
					s++;
				else
					Error();
			}
		}
	}
	return (number_count);
}

int	*fill_array(char *argv, int nb_count, t_stack **stack)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * nb_count);
	if (array == 0)
		exit(EXIT_FAILURE);
	while (*argv && nb_count > 0)
	{
		while (*argv == ' ' && *argv)
			argv++;
		if (*argv != ' ' && *argv)
		{
			array[nb_count - 1] = ft_atoi(argv);
			nb_count--;
			while (*argv != ' ' && *argv)
				argv++;
		}
	}
	return (array);
}

t_stack	**push_swap_split(char **argv)
{
	t_stack	**stack;
	int		nb_count;
	int		i;
	int		*array;

	i = 0;
	nb_count = number_count(argv[1]);
	//ft_printf("%d\n", nb_count);
	stack = create_stack(nb_count);
	if (stack == 0)
		exit(EXIT_FAILURE);
	array = fill_array(argv[1], nb_count, stack);
	//ft_printf("%d\n", nb_count);
	while (i < nb_count)
	{
		stack[i]->val = array[i];
		if (repeted(stack, i) == 1)
			Error();
		i++;
	}
	return (stack);
}
