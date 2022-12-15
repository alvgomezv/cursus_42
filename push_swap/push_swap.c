/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:57:00 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/15 16:16:06 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	swap_both(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*aux;
	int		len;

	len = stack_len(stack_1) - 1;
	aux = stack_1[len];
	stack_1[len] = stack_1[len - 1];
	stack_1[len - 1] = aux;
	swap(stack_2, 's');
}

void	rotate_both(t_stack **stack_1, t_stack **stack_2)
{
	int		len;
	int		i;
	t_stack	*temp_1;
	t_stack	*temp_2;

	i = 0;
	len = stack_len(stack_1) - 1;
	temp_1 = stack_1[len];
	while (i <= len)
	{
		temp_2 = stack_1[i];
		stack_1[i] = temp_1;
		temp_1 = temp_2;
		i++;
	}
	rotate(stack_2, 'r');
}

void	reverse_rotate_both(t_stack **stack_1, t_stack **stack_2)
{
	int		len;
	t_stack	*temp_1;
	t_stack	*temp_2;

	len = stack_len(stack_1) - 1;
	temp_1 = stack_1[0];
	while (len >= 0)
	{
		temp_2 = stack_1[len];
		stack_1[len] = temp_1;
		temp_1 = stack_1[len - 1];
		if (len > 0)
			stack_1[len - 1] = temp_2;
		len -= 2;
	}
	reverse_rotate(stack_2, 'r');
}

int	main(int argc, char **argv)
{
	t_stack	**stack_1;
	t_stack	**stack_2;
	int		i;
	int		len;

	i = 0;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
	{
		stack_1 = push_swap_split(argv);
	}
	else
	{
		len = argc - 1;
		stack_1 = create_stack(len);
		if (stack_1 == 0)
			exit(EXIT_FAILURE);
		while (argc > 1)
		{
			if (is_it_a_string(argv[argc - 1]) == 1)
				Error();
			stack_1[i]->val = ft_atoi(argv[argc - 1]);
			if (repeted(stack_1, i) == 1)
				Error();
			i++;
			argc--;
		}
	}
	print_stack(stack_1, 1);
	find_positions(stack_1, stack_len(stack_1));
	//print_stack(stack_1, 2);
	//write(1, "\n", 1);
	stack_2 = create_stack_to_zero(len);
	algorithm(stack_1, stack_2);
	print_stack(stack_1, 1);
	print_stack(stack_2, 1);
	return (0);
}
