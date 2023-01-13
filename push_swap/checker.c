/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:19:22 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/13 12:29:54 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	case_of_letter_s(t_stack **stack_1,
			t_stack **stack_2, char *imput, int i)
{
	if (imput[i + 1] == 'a')
		swap(stack_1, 'a', 0);
	else if (imput[i + 1] == 'b')
		swap(stack_2, 'b', 0);
	else if (imput[i + 1] == 's')
		swap_both(stack_1, stack_2, 0);
}

void	case_of_letter_p(t_stack **stack_1,
			t_stack **stack_2, char *imput, int i)
{
	if (imput[i + 1] == 'a')
		push(stack_2, stack_1, 'a', 0);
	else if (imput[i + 1] == 'b')
		push(stack_1, stack_2, 'b', 0);
}

void	case_of_double_letter_r(t_stack **stack_1,
			t_stack **stack_2, char *imput, int i)
{
	if (imput[i + 2] == 'a')
		reverse_rotate(stack_1, 'a', 0);
	else if (imput[i + 2] == 'b')
		reverse_rotate(stack_2, 'b', 0);
	else if (imput[i + 2] == 'r')
		reverse_rotate_both(stack_1, stack_2, 0);
}

void	program(t_stack **stack_1, t_stack **stack_2, char *imput)
{
	int		i;

	i = 0;
	while (imput[i])
	{
		if (imput[i] == 's')
			case_of_letter_s(stack_1, stack_2, imput, i);
		else if (imput[i] == 'p')
			case_of_letter_p(stack_1, stack_2, imput, i);
		else if (imput[i] == 'r')
		{
			if (imput[i + 1] == 'r')
			{
				case_of_double_letter_r(stack_1, stack_2, imput, i);
			i++;
			}
			else if (imput[i + 1] == 'a')
				rotate(stack_1, 'a', 0);
			else if (imput[i + 1] == 'b')
				rotate(stack_2, 'b', 0);
			else if (imput[i + 1] == 'r')
				rotate_both(stack_1, stack_2, 0);
		}	
	i++;
	}
}

int	main(int argc, char **argv)
{
	char	*imput;
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
	imput = read_std_imput();
	program(stack_1, stack_2, imput);
	if (is_it_in_order_1(stack_1) == 1 && !stack_2[0])
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
