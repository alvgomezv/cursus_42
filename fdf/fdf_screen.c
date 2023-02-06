/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:37:55 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/06 12:43:10 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	inicialize_min_and_max(t_map *map)
{
	isometric_pixel(map, (0), (0), map->map[0][0]);
	map->v->max_x = map->s->isometric_x;
	map->v->min_x = map->s->isometric_x;
	map->v->max_y = map->s->isometric_y;
	map->v->min_y = map->s->isometric_y;
}

void	find_min_and_max(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	inicialize_min_and_max(map);
	while (i < map->s->size_y)
	{
		while (j < map->s->size_x[i])
		{
			isometric_pixel(map, (j * map->s->spacing),
				(i * map->s->spacing), map->map[i][j]);
			if (map->s->isometric_x > map->v->max_x)
				map->v->max_x = map->s->isometric_x;
			if (map->s->isometric_x < map->v->min_x)
				map->v->min_x = map->s->isometric_x;
			if (map->s->isometric_y > map->v->max_y)
				map->v->max_y = map->s->isometric_y;
			if (map->s->isometric_y < map->v->min_y)
				map->v->min_y = map->s->isometric_y;
		j++;
		}
	j = 0;
	i++;
	}
}

void	calculate_centers(t_map *map)
{
	float		center_x;
	float		center_y;
	float		win_center_x;
	float		win_center_y;

	center_x = (map->v->max_x + map->v->min_x) / 2;
	center_y = (map->v->max_y + map->v->min_y) / 2;
	win_center_x = map->s->win_x / 2;
	win_center_y = map->s->win_y / 2;
	map->s->offset_x += win_center_x - center_x;
	map->s->offset_y += win_center_y - center_y;
}

void	fit_into_screen(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_min_and_max(map);
	calculate_centers(map);
	while (((map->v->min_x < map->s->margin)
			|| (map->v->max_x > (map->s->win_x - map->s->margin))
			|| (map->v->min_y < map->s->margin)
			|| (map->v->max_y > (map->s->win_y - map->s->margin)))
		&& map->s->spacing > 0.5)
	{
		if (map->s->spacing <= 1)
			map->s->spacing -= 0.01;
		else
			map->s->spacing--;
		find_min_and_max(map);
		calculate_centers(map);
	}
}
