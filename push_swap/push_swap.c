/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:57:00 by alvgomez          #+#    #+#             */
/*   Updated: 2022/12/05 18:03:16 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	swap(t_stack **stack)
{
	t_stack	*aux;
	int		len;

	len = stack_len(stack) - 1;
	aux = stack[len];
	stack[len] = stack[len - 1];
	stack[len - 1] = aux;
	ft_printf("swap\n");
}

void	push(t_stack **stack_1, t_stack **stack_2, int max_len)
{
	int	len_1;
	int	len_2;

	len_1 = stack_len(stack_1);
	len_2 = stack_len(stack_2);
	//ft_printf("%d\n", len_1);
	//ft_printf("%d\n", len_2);
	//ft_printf("%d\n", max_len);
	//if (len_1 == 0)
	//	return ;
	//if ((len_2 + 1) > max_len)
	//	exit(EXIT_FAILURE);
	stack_2[len_2] = stack_1[len_1 - 1];
	stack_1[len_1 - 1] = 0;	
	ft_printf("push\n");
}

void	reverse_rotate(t_stack **stack)
{
	int	len;
	t_stack	*temp_1;
	t_stack	*temp_2;

	len = stack_len(stack) - 1;
	//ft_printf("%d\n", len);
	temp_1 = stack[0];
	while (len >= 0)
	{
		temp_2 = stack[len];
		stack[len] = temp_1;
		temp_1 = stack[len - 1];
		if (len > 0)
			stack[len - 1] = temp_2;
		len -= 2;
	}
	ft_printf("reverse_rotate\n");
}

void	rotate(t_stack **stack)
{
	int		len;
	int		i;
	t_stack	*temp_1;
	t_stack	*temp_2;

	i = 0;
	len = stack_len(stack) - 1;
	ft_printf("%d\n", len);
	//ft_printf("%d\n", len);
	temp_1 = stack[len];
	while (i <= len)
	{
		temp_2 = stack[i];
		stack[i] = temp_1;
		temp_1 = temp_2;
		i++;
	}
	ft_printf("rotate\n");
}

int	main(int argc, char **argv)
{
	t_stack	**stack_1;
	t_stack	**stack_2;
	int		i;
	int		len;

	i = 0;
	len = argc - 1;
	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_1 = create_stack(len);
	if (stack_1 == 0)
		exit(EXIT_FAILURE);
	while (argc > 1)
	{
		stack_1[i]->val = ft_atoi(argv[argc - 1]);
		if (repeted(stack_1, i) == 1)
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
		argc--;
	}
	print_stack(stack_1, 1);
	find_positions(stack_1, stack_len(stack_1));
	print_stack(stack_1, 2);
	write(1, "\n", 1);
	stack_2 = create_stack_to_zero(len);
	algorithm(stack_1, stack_2);
	return (0);
}
