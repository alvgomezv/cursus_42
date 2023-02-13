/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:37:55 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/13 17:56:22 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_min_max_height(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->s->size_y)
	{
		while (j < map->s->size_x[i])
		{
			if (map->map[i][j] > map->h->max_height)
				map->h->max_height = map->map[i][j];
			if (map->map[i][j] < map->h->min_height)
				map->h->min_height = map->map[i][j];
			j++;
		}
	j = 0;
	i++;
	}
}

void	inicialize_min_and_max(t_map *map)
{
	projection_pixel(map, (0), (0), map->map[0][0]);
	map->v->max_x = map->p->x;
	map->v->min_x = map->p->x;
	map->v->max_y = map->p->y;
	map->v->min_y = map->p->y;
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
			projection_pixel(map, (j * map->s->spacing),
				(i * map->s->spacing), map->map[i][j]);
			if (map->p->x > map->v->max_x)
				map->v->max_x = map->p->x;
			if (map->p->x < map->v->min_x)
				map->v->min_x = map->p->x;
			if (map->p->y > map->v->max_y)
				map->v->max_y = map->p->y;
			if (map->p->y < map->v->min_y)
				map->v->min_y = map->p->y;
		j++;
		}
	j = 0;
	i++;
	}
}

void	center_projection(t_map *map)
{
	float		center_x;
	float		center_y;
	float		win_center_x;
	float		win_center_y;

	find_min_and_max(map);
	center_x = (map->v->max_x + map->v->min_x) / 2;
	center_y = (map->v->max_y + map->v->min_y) / 2;
	win_center_x = SCRN_WIDTH / 2;
	win_center_y = SCRN_HEIGHT / 2;
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
	center_projection(map);
	while (((map->v->min_x < map->s->margin)
			|| (map->v->max_x > (SCRN_WIDTH - map->s->margin))
			|| (map->v->min_y < map->s->margin)
			|| (map->v->max_y > (SCRN_HEIGHT - map->s->margin)))
		&& map->s->spacing > 0.5)
	{
		if (map->s->spacing <= 1)
			map->s->spacing -= 0.01;
		else
			map->s->spacing--;
		find_min_and_max(map);
		center_projection(map);
	}
}
