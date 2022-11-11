/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:57:00 by alvgomez          #+#    #+#             */
/*   Updated: 2022/11/11 18:27:46 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

t_stack	**create_stack(int n);
t_stack	**create_stack_to_zero(int n);
int		stack_len(t_stack **stack);

/*void	swap(t_stack *stack)
{
	int	aux;
	int	len;

	len = stack_len(stack) - 1;
	aux = stack[len].val;
	stack[len].val = stack[len - 1].val;
	stack[len - 1].val = aux;
}*/

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
}

/*void	reverse_rotate(int *stack)
{
	int	len;
	int	temp_1;
	int	temp_2;

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
}

void	rotate(int *stack)
{
	int	len;
	int	i;
	int	temp_1;
	int	temp_2;

	i = 0;
	len = stack_len(stack) - 1;
	//ft_printf("%d\n", len);
	temp_1 = stack[len];
	while (i < len)
	{
		temp_2 = stack[i];
		stack[i] = temp_1;
		temp_1 = stack[i + 1];
		if (i <= len)
			stack[i + 1] = temp_2;
		i += 2;
	}
}*/

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
		i++;
		argc--;
	}
	stack_2 = create_stack_to_zero(len);
	ft_printf("%d\n", stack_len(stack_2));
	//rotate(stack_1);
	i = 0;
	while (stack_1[i])
	{
		ft_printf("%d ", stack_1[i]->val);
		i++;
	}
	i = 0;
	write(1, "\n", 1);
	push(stack_1, stack_2, len);
	while (stack_1[i])
	{
		ft_printf("%d ", stack_1[i]->val);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	while (stack_2[i])
	{
		ft_printf("%d ", stack_2[i]->val);
		i++;
	}
	return (0);
}
