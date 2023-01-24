/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:30:42 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/24 18:44:33 by alvgomez         ###   ########.fr       */
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

static char	**ft_realloc_char(char **matrix, int size)
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
	//aux[i] = '\0';
	free(matrix);
	return (aux);
}

static int	*ft_realloc_map(int *matrix, int size)
{
	int		*aux;
	int		i;

	//if (!matrix)
	//{
	//	aux = (int *)malloc(size * sizeof(int));
	//	free(matrix);
	//	return (aux);
	//}
	aux = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < (size - 1))
	{
		aux[i] = matrix[i];
		i++;
	}
	//aux[i] = '\0';
	free (matrix);
	return (aux);
}

t_map	*fill_map(char **matrix)
{
	t_map	*map;
	int		j;
	int		i;
	int		cont;

	j = 0;
	i = 0;
	cont = 0;
	while (matrix[i])
		i++;
	map = (t_map *)malloc(sizeof(t_map));
	map->map = (int **)malloc(i * sizeof(int *));
	i = 0;
	while (matrix[i])
	{
		map->map[i] = (int *)malloc(1 * sizeof(int));
		while (matrix[i][j])
		{
			//ft_printf("j = %d\n", j);
			if (matrix[i][j] != ' ' && matrix[i][j] != '\n')
			{
				//ft_printf("%d\n", ft_atoi(&matrix[i][j]));
				map->map[i][cont] = ft_atoi(&matrix[i][j]);
				cont++;
				map->x = cont;
				map->map[i] = ft_realloc_map(map->map[i], (cont + 1));
				//ft_printf("cont = %d\n", cont);
				while (matrix[i][j] != ' ' && matrix[i][j])
					j++;
			}
			j++;
		}
	map->y = (i + 1);
	cont = 0;
	j = 0;
	i++;
	}
	ft_free_matrix(matrix);
	return (map);
	
}

t_map	*get_map(char **argv)
{
	int		fd;
	char	**matrix;
	t_map	*map;
	int		i;
	
	fd = open(argv[1], O_RDONLY);
	matrix = (char **)malloc(2 * sizeof(char *));
	matrix[0] = get_next_line(fd);
	//matrix[1] = '\0';
	i = 0;
	while (matrix[i])
	{
		i++;
		matrix[i] = get_next_line(fd);
		if (matrix[i])
			matrix = ft_realloc_char(matrix, 2 + i);
	}
	//ft_printf("%d\n", ft_atoi(&matrix[2][5]));

	//i = 0;
	//while (matrix[i])
	//{
	//	ft_printf("%s ", matrix[i]);
	//	i++;
	//}
	
	map = fill_map(matrix);
	
	return (map);
}
