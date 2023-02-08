/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:14 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/08 17:20:11 by alvgomez         ###   ########.fr       */
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
	while (i < SCRN_HEIGHT)
	{
		while (j < SCRN_WIDTH)
		{
			put_pixels(map->img, j, i, CLR_SCRN);
			j++;
		}
	j = 0;
	i++;
	}
}

void	put_pixels(mlx_image_t *img, int x, int y, int color)
{
	if (x < SCRN_WIDTH && y < SCRN_HEIGHT && x > 0 && y > 0)
		mlx_put_pixel(img, x, y, color);
}

void	draw_map(t_map *map, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	draw_clear_background(map);
	find_min_and_max(map);
	calculate_centers(map);
	while (i < map->s->size_y)
	{
		while (j < map->s->size_x[i])
		{
			if (map->map[i][j] > map->h->max_height)
				map->h->max_height = map->map[i][j];
			if (map->map[i][j] < map->h->min_height)
				map->h->min_height = map->map[i][j];
			projection_pixel(map, (j * map->s->spacing),
				(i * map->s->spacing), map->map[i][j]);
			//isometric_pixel(map, (j * map->s->spacing),
			//	(i * map->s->spacing), map->map[i][j]);
			put_pixels(map->img, map->i->isometric_x,
					map->i->isometric_y, map->c->color_start);
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
	map->c->color_start = rgb_to_int(243, 255, 0, 255);
	map->c->color_end = rgb_to_int(255, 39, 0, 255);
	map->h->max_height = map->map[0][0];
	map->h->min_height = map->map[0][0];
	map->s->spacing = 200;
	map->s->margin = 50;
	map->s->offset_x = 0;
	map->s->offset_y = 0;
	isometric_pixel(map, (0), (0), map->map[0][0]);
	map->v->max_x = 0;
	map->v->min_x = 0;
	map->v->max_y = 0;
	map->v->min_y = 0;
	map->h->height_factor = 1;
	map->r->alpha = 0;
	map->r->beta = 0;
	map->r->gamma = 0;
	map->v->zoom = 1;
	map->v->zoom_factor = 0.1;
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
	map->mlx = mlx_init(SCRN_WIDTH , SCRN_HEIGHT, "MLX42", true);
	if (!map->mlx)
		exit(EXIT_FAILURE);
	map->img = mlx_new_image(map->mlx, SCRN_WIDTH, SCRN_HEIGHT);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
		ft_error("mlx_image failed");
	draw_map(map, map->img);
	set_hooks(map);
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, map->img);
	mlx_terminate(map->mlx);
	ft_free_map(map);
	//atexit(leaks);
	return (EXIT_SUCCESS);
}
