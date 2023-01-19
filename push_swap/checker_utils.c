/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:21:31 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/16 16:27:11 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

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

char	*read_std_imput(void)
{
	char	*str;
	char	*buff;
	int		bytes_read;

	str = (char *)malloc(sizeof(char) * 2);
	buff = (char *)malloc(sizeof(char) * 2);
	if (str == 0)
		exit (EXIT_FAILURE);
	bytes_read = read(0, str, 1);
	str[1] = '\0';
	while (bytes_read != 0)
	{
		buff[1] = '\0';
		str = ft_strjoin(str, buff);
		bytes_read = read(0, buff, 1);
	}
	free(buff);
	return (str);
}

void	ft_free_all(t_stack **stack_1, t_stack **stack_2, char *imput)
{
	free(imput);
	ft_free_push_swap(stack_1);
	ft_free_push_swap(stack_2);
}
