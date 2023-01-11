/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:19:22 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/11 20:38:20 by alvgomez         ###   ########.fr       */
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
	stack_2 = create_stack_to_zero(stack_len(stack_1));
	find_positions(stack_1, stack_len(stack_1));
	//print_stack(stack_1, 1, 'A');
	//print_stack(stack_1, 2, 'A');
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

void	program(t_stack **stack_1, t_stack **stack_2)
{
	read(0, );
	//lectura bit a bit de la entrada estandar y ir modificando con realoc
}