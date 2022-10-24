/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:57:00 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/24 17:34:58 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
int	*to_zero(int n);
int	array_len(int *array);

void	swap(int *array)
{
	int aux;
	int	len;

	len = array_len(array) - 1;
	aux = array[len];
	array[len] = array[len - 1];
	array[len - 1] = aux;
}

void	push(int *array_1, int *array_2, int max_len)
{
	int	len_1;
	int	len_2;

	len_1 = array_len(array_1);
	len_2 = array_len(array_2);
	ft_printf("%d\n", len_1);
	ft_printf("%d\n", len_2);
	ft_printf("%d\n", max_len);
	if (len_1 == 0)
		return;
	if ((len_2 + 1) > max_len)
		exit(EXIT_FAILURE);
	array_2[len_2] = array_1[len_1 - 1];
	array_1[len_1 - 1] = 0;	
}

void	reverse_rotate(int *array)
{
	int	len;
	int	temp_1;
	int	temp_2;

	len = array_len(array) - 1;
	//ft_printf("%d\n", len);
	temp_1 = array[0];
	while (len >= 0)
	{
		temp_2 = array[len];
		array[len] = temp_1;
		temp_1 = array[len - 1];
		if (len > 0)
			array[len - 1] = temp_2;
		len -= 2;
	}
}

void	rotate(int *array)
{
	int	len;
	int	i;
	int	temp_1;
	int	temp_2;

	i = 0;
	len = array_len(array) - 1;
	//ft_printf("%d\n", len);
	temp_1 = array[len];
	while (i < len)
	{
		temp_2 = array[i];
		array[i] = temp_1;
		temp_1 = array[i + 1];
		if (i <= len)
			array[i + 1] = temp_2;
		i += 2;
	}
}

int	main(int argc, char **argv)
{
	int	*list;
	int	*temp;
	int	i;
	int len;

	i = 0;
	len = argc - 1;
	if (argc < 2)
		exit(EXIT_FAILURE);
	list = (int *)malloc(sizeof(int) * len);
	if (list == 0)
		exit(EXIT_FAILURE);
	while (argc > 1)
	{
		list[i] = ft_atoi(argv[argc - 1]);
		i++;
		argc--;
	}
	temp = to_zero(len - 1);
	//rotate(list);
	i = 0;
	while (list[i])
	{
		ft_printf("%d ", list[i]);
		i++;
	}
	i = 0;
	write(1, "\n", 1);
	//push(list, temp, len - 1);
	/*while (list[i])
	{
		ft_printf("%d ", list[i]);
		i++;
	}
		write(1, "\n", 1);
	i = 0;
	while (temp[i] != 0)
	{
		ft_printf("%d ", temp[i]);
		i++;
	}*/
	return (0);
}
