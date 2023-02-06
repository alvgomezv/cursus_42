/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:14 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/06 18:42:13 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	leaks(void)
{
	system("leaks -q fdf");
}

void	draw_clear_background(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->s->win_y)
	{
		while (j < map->s->win_x)
		{
			mlx_put_pixel(map->img, j, i, CLR_SCRN);
			j++;
		}
	j = 0;
	i++;
	}
}

void	draw_map(t_map *map, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	draw_clear_background(map);
	while (i < map->s->size_y)
	{
		while (j < map->s->size_x[i])
		{
			if (map->map[i][j] > map->s->max_height)
				map->s->max_height = map->map[i][j];
			if (map->map[i][j] < map->s->min_height)
				map->s->min_height = map->map[i][j];
			isometric_pixel(map, (j * map->s->spacing),
				(i * map->s->spacing), map->map[i][j]);
			mlx_put_pixel(img, map->s->isometric_x,
				map->s->isometric_y, map->s->color_start);
			j++;
		}
	j = 0;
	i++;
	}
	draw_horizontal_lines(map, img);
	draw_vertical_lines(map, img);
}

void	initial_specifications(t_map *map)
{
	map->s->color_start = rgb_to_int(243, 255, 0, 255);
	map->s->color_end = rgb_to_int(255, 39, 0, 255);
	map->s->max_height = map->map[0][0];
	map->s->min_height = map->map[0][0];
	map->s->spacing = 200;
	map->s->angle = 30;
	map->s->margin = 50;
	map->s->offset_x = 0;
	map->s->offset_y = 0;
	map->s->win_x = 1500;
	map->s->win_y = 1000;
	isometric_pixel(map, (0), (0), map->map[0][0]);
	map->v->max_x = 0;
	map->v->min_x = 0;
	map->v->max_y = 0;
	map->v->min_y = 0;
	map->s->height_factor = 0.5;
}

int32_t	main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
		exit(EXIT_FAILURE);
	map = get_map(argv);
	initial_specifications(map);
	ft_printf("x[0] = %d\n", map->s->size_x[0]);
	ft_printf("y = %d\n", map->s->size_y);
	fit_into_screen(map);
	map->mlx = mlx_init(map->s->win_x, map->s->win_y, "MLX42", true);
	if (!map->mlx)
		exit(EXIT_FAILURE);
	map->img = mlx_new_image(map->mlx, map->s->win_x, map->s->win_y);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
		ft_error();
	draw_map(map, map->img);
	set_hooks(map);
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, map->img);
	mlx_terminate(map->mlx);
	ft_free_map(map);
	//atexit(leaks);
	return (EXIT_SUCCESS);
}
