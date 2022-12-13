/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:18:13 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/13 14:30:36 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

static int	number_count(char **s)
{
	int	number_count;
	int	i;

	number_count = 0;
	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[1][i] == ' ')
			i++;
		else
		{
			if ((s[1][i] >= '0' && s[1][i] <= '9') || s[1][i] == '-') 
				number_count++;
			else
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			while (s[1][i] && s[1][i] != ' ')
			{
				if (s[1][i] >= '0' && s[1][i] <= '9')
					i++;
				else
				{
					write(1, "Error\n", 6);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	return (number_count);
}

t_stack	**push_swap_split(char **argv)
{
	t_stack	**stack;
	int		nb_count;
	int		i;

	i = 0;
	nb_count = number_count(argv);
	stack = create_stack(nb_count);
	if (!stack)
		return (0);
	while (argv[1][i] && nb_count > 0)
	{
		while (*argv[1] == ' ' && *argv[1])
			argv[1]++;
		if (*argv[1] != ' ' && *argv[1])
		{
			stack[i]->val = ft_atoi(argv[1]);
			if (repeted(stack, i) == 1)
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			i++;
			nb_count--;
			while (*argv[1] != ' ' && *argv[1])
				argv[1]++;
		}
	}
	return (stack);
}
