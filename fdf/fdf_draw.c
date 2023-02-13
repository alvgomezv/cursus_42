/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:52:34 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/13 17:34:12 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	aux_line(t_map *map, int pixels, int height_start, int height_end)
{
	map->l->delta_x /= pixels;
	map->l->delta_y /= pixels;
	map->l->pixel_x = map->p->x_start;
	map->l->pixel_y = map->p->y_start;
	map->c->aux_color_start = get_percentage_color(map, height_start);
	map->c->aux_color_end = get_percentage_color(map, height_end);
}

void	draw_line_with_colors(void *img, t_map *map,
		int height_start, int height_end)
{
	int		pixels;
	float	percentage;
	int		current_color;
	int		i;

	i = 0;
	map->l->delta_x = map->p->x_end - map->p->x_start;
	map->l->delta_y = map->p->y_end - map->p->y_start;
	pixels = sqrt((map->l->delta_x * map->l->delta_x)
			+ (map->l->delta_y * map->l->delta_y));
	aux_line(map, pixels, height_start, height_end);
	while (i <= pixels)
	{
		percentage = (double)i / (double)pixels;
		current_color = get_gradient_color(percentage,
				map->c->aux_color_start, map->c->aux_color_end);
		put_pixels(img, map->l->pixel_x, map->l->pixel_y, current_color);
		map->l->pixel_x += map->l->delta_x;
		map->l->pixel_y += map->l->delta_y;
		i++;
	}	
}

void	draw_map(t_map *map, mlx_image_t *img)
{
	draw_clear_background(map);
	set_min_max_height(map);
	draw_horizontal_lines(map, img);
	draw_vertical_lines(map, img);
}

void	draw_horizontal_lines(t_map *map, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->s->size_y)
	{
		while (j < (map->s->size_x[i] - 1))
		{
			projection_line_start(map, j * map->s->spacing,
				i * map->s->spacing, map->map[i][j]);
			projection_line_end(map, (j + 1) * map->s->spacing,
				i * map->s->spacing, map->map[i][j + 1]);
			draw_line_with_colors(img, map, map->map[i][j], map->map[i][j + 1]);
			j++;
		}
	j = 0;
	i++;
	}
}

void	draw_vertical_lines(t_map *map, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (map->s->size_y - 1))
	{
		while (j < map->s->size_x[i])
		{
			projection_line_start(map, j * map->s->spacing,
				i * map->s->spacing, map->map[i][j]);
			projection_line_end(map, j * map->s->spacing,
				(i + 1) * map->s->spacing, map->map[i + 1][j]);
			draw_line_with_colors(img, map, map->map[i][j], map->map[i + 1][j]);
			j++;
		}
	j = 0;
	i++;
	}
}
