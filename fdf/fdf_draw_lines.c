/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:52:34 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/06 12:58:48 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	aux_line(t_map *map, int pixels, int height_start, int height_end)
{
	map->s->delta_x /= pixels;
	map->s->delta_y /= pixels;
	map->s->pixel_x = map->s->isometric_x_start;
	map->s->pixel_y = map->s->isometric_y_start;
	map->s->aux_color_start = get_percentage_color(map, height_start);
	map->s->aux_color_end = get_percentage_color(map, height_end);
}

void	draw_line_with_colors(void *img, t_map *map,
		int height_start, int height_end)
{
	int		pixels;
	float	percentage;
	int		current_color;
	int		i;

	i = 0;
	map->s->delta_x = map->s->isometric_x_end - map->s->isometric_x_start;
	map->s->delta_y = map->s->isometric_y_end - map->s->isometric_y_start;
	pixels = sqrt((map->s->delta_x * map->s->delta_x)
			+ (map->s->delta_y * map->s->delta_y));
	aux_line(map, pixels, height_start, height_end);
	while (i <= pixels)
	{
		percentage = (double)i / (double)pixels;
		current_color = get_gradient_color(percentage,
				map->s->aux_color_start, map->s->aux_color_end);
		mlx_put_pixel(img, map->s->pixel_x, map->s->pixel_y, current_color);
		map->s->pixel_x += map->s->delta_x;
		map->s->pixel_y += map->s->delta_y;
		i++;
	}	
}

void	draw_line(void *img, t_map *map)
{
	int	pixels;

	map->s->delta_x = map->s->isometric_x_end - map->s->isometric_x_start;
	map->s->delta_y = map->s->isometric_y_end - map->s->isometric_y_start;
	pixels = sqrt((map->s->delta_x * map->s->delta_x)
			+ (map->s->delta_y * map->s->delta_y));
	map->s->delta_x /= pixels;
	map->s->delta_y /= pixels;
	map->s->pixel_x = map->s->isometric_x_start;
	map->s->pixel_y = map->s->isometric_y_start;
	while (pixels)
	{
		mlx_put_pixel(img, map->s->pixel_x,
			map->s->pixel_y, map->s->color_start);
		map->s->pixel_x += map->s->delta_x;
		map->s->pixel_y += map->s->delta_y;
		--pixels;
	}	
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
			isometric_line_start(map, j * map->s->spacing,
				i * map->s->spacing, map->map[i][j]);
			isometric_line_end(map, (j + 1) * map->s->spacing,
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
			isometric_line_start(map, j * map->s->spacing,
				i * map->s->spacing, map->map[i][j]);
			isometric_line_end(map, j * map->s->spacing,
				(i + 1) * map->s->spacing, map->map[i + 1][j]);
			draw_line_with_colors(img, map, map->map[i][j], map->map[i + 1][j]);
			j++;
		}
	j = 0;
	i++;
	}
}
