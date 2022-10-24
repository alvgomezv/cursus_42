/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:36:48 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/20 13:57:11 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	binary_search(int *array, int target, int start, int end)
{
	int	middle;
	int	pos_start;
	int	pos_end;

	if (start > end)
		exit (EXIT_FAILURE);
	pos_start = 0;
	pos_end = 0;
	while (array[pos_start] != start)
		pos_start++;
	while (array[pos_start + pos_end] != end)
		pos_end++;
	middle = (pos_end - pos_start) / 2;
	while (target != array[pos_start + middle])
	{
		if (target <= array[pos_start + middle])
			pos_end = pos_start + middle;
		else
			pos_start = pos_start + middle;
		middle = middle / 2;
	}
	return ((pos_start + middle));
}

/*La posición en C empieza en 0!!!!!

int main (void)
{
	int array[14] = {1,2,3,5,7,12,14,20,32,57,89,111,112,113};
	int result;

	result = binary_search(array, 57, 1, 113);
	ft_printf("%d\n", result);
	return (0);	
}*/
