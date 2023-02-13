/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:14 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/13 18:13:33 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	initial_specifications(t_map *map)
{
	map->h->max_height = map->map[0][0];
	map->h->min_height = map->map[0][0];
	map->c->color_start = CLR_START;
	map->c->color_end = CLR_END;
	map->p->type = 1;
	map->s->spacing = 200;
	map->s->margin = 50;
	map->s->offset_x = 0;
	map->s->offset_y = 0;
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
	map->c->r = 1000;
}

int	check_map(t_map *map)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (i < map->s->size_y)
	{
		while (j < map->s->size_x[i])
		{
			if (map->map[i][j] && map->s->size_x[i])
				check = 1;
			j++;
		}
		ft_printf("\n");
	j = 0;
	i++;
	}
	if (map->s->size_y)
		check = 1;
	return (check);
}

int32_t	main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
		ft_error("Map reading error");
	map = get_map(argv);
	if (check_map(map) == 0)
		ft_error("Map reading error");
	initial_specifications(map);
	fit_into_screen(map);
	map->mlx = mlx_init(SCRN_WIDTH, SCRN_HEIGHT, "MLX42", true);
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
	return (EXIT_SUCCESS);
}
