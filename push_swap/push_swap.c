/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:57:00 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/19 11:21:28 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_1;
	t_stack	**stack_2;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		stack_1 = push_swap_split(argv);
	else
	{
		stack_1 = create_stack(argc - 1);
		if (stack_1 == 0)
			exit(EXIT_FAILURE);
		aux_main(stack_1, argv, argc);
	}
	find_positions(stack_1, stack_len(stack_1), 0);
	if (is_it_in_order_1(stack_1) == 0)
	{
		stack_2 = create_stack_to_zero(stack_len(stack_1));
		algorithm(stack_1, stack_2);
		free(stack_2);
	}
	ft_free_push_swap(stack_1);
}

void	aux_main(t_stack **stack_1, char **argv, int argc)
{
	int	i;

	i = 0;
	while (argc > 1)
	{
		if (is_it_a_string(argv[argc - 1]) == 1)
			there_is_an_error();
		stack_1[i]->val = ft_atoi(argv[argc - 1]);
		if (repeted(stack_1, i) == 1)
			there_is_an_error();
		i++;
		argc--;
	}
}

void	algorithm(t_stack **stack_1, t_stack **stack_2)
{
	int	a;
	int	b;
	int	i;

	a = 0;
	b = 0;
	if (stack_len(stack_1) < 2)
		exit (EXIT_SUCCESS);
	if (stack_len(stack_1) == 2)
		resolve_stack_1_of_two(stack_1);
	else if (stack_len(stack_1) == 3)
		resolve_stack_1_of_three(stack_1);
	else
	{
		push_all_to_b_but_3_smallest_half_first(stack_1, stack_2);
		resolve_stack_1_of_three(stack_1);
		algorithm_stack_two_to_stack_one(stack_1, stack_2, a, b);
		i = find_place_from_pos(stack_1, find_lowest_pos(stack_1));
		move_place_to_the_top(stack_1, i, 'a');
	}
}
