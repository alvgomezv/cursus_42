/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:30:42 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/06 12:36:20 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	aux_fill_map(t_map	*map, int i, int cont)
{
	map->s->size_x[i] = cont;
	map->s->size_y = (i + 1);
}

void	fill_map(t_map	*map, char **matrix, int i, int j)
{
	int		cont;

	cont = 0;
	while (matrix[i])
	{
		map->map[i] = (int *)malloc(1 * sizeof(int));
		while (matrix[i][j])
		{
			if (matrix[i][j] != ' ' && matrix[i][j])
			{
				map->map[i][cont] = ft_atoi(&matrix[i][j]);
				cont++;
				map->map[i] = ft_realloc_map(map->map[i], (cont + 1));
				while (matrix[i][j] != ' ' && matrix[i][j]
					!= '\n' && matrix[i][j])
					j++;
			}
			while (matrix[i][j] == ' ' || matrix[i][j] == '\n')
				j++;
		}
		aux_fill_map(map, i, cont);
	cont = 0;
	j = 0;
	i++;
	}
}

t_map	*inicialize_map(char **matrix)
{
	t_map	*map;
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	map = (t_map *)malloc(sizeof(t_map));
	map->s = (t_spec *)malloc(sizeof(t_spec));
	map->v = (t_val *)malloc(sizeof(t_val));
	map->map = (int **)malloc(i * sizeof(int *));
	map->s->size_x = (int *)malloc(i * sizeof(int));
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
	i = 0;
	while (matrix[i])
	{
		i++;
		matrix[i] = get_next_line(fd);
		if (matrix[i])
			matrix = ft_realloc_char(matrix, 2 + i);
	}
	close (fd);
	fd = 0;
	i = 0;
	map = inicialize_map(matrix);
	fill_map(map, matrix, fd, i);
	ft_free_matrix(matrix);
	return (map);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->s->size_y)
	{
		while (j < map->s->size_x[i])
		{
			ft_printf("%d ", map->map[i][j]);
			j++;
		}
		ft_printf("\n");
	j = 0;
	i++;
	}
}
