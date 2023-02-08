/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:05:30 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/08 17:18:34 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}

char	**ft_realloc_char(char **matrix, int size)
{
	char	**aux;
	int		i;

	aux = (char **)malloc(size * sizeof(char *));
	i = 0;
	while (i < (size - 1))
	{
		aux[i] = matrix[i];
		i++;
	}
	free(matrix);
	return (aux);
}

int	*ft_realloc_map(int *matrix, int size)
{
	int		*aux;
	int		i;

	aux = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < (size - 1))
	{
		aux[i] = matrix[i];
		i++;
	}
	free (matrix);
	return (aux);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->s->size_y)
	{
		free(map->map[i]);
		i++;
	}
	free (map->map);
	free (map->s->size_x);
	free (map->s);
	free (map->v);
	free (map->c);
	free (map->i);
	free (map->h);
	free (map->l);
	free (map->r);
	free (map);
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
