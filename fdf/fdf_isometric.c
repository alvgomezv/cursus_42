/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:30:17 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/08 16:03:09 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_pixel(t_map *map, int source_x, int source_y, int source_z)
{
	float	angle;

	angle = PROJ_ANGLE * (M_PI / 180);
	map->i->isometric_x = map->v->zoom * ((source_x - source_y) * cos(angle) + map->s->offset_x);
	map->i->isometric_y = map->v->zoom * ((source_x + source_y) * sin(angle)
		- (source_z * map->h->height_factor) + map->s->offset_y);
}

void	isometric_line_start(t_map *map, int source_x,
	int source_y, int source_z)
{
	float	angle;

	angle = PROJ_ANGLE * (M_PI / 180);
	map->i->isometric_x_start = map->v->zoom * ((source_x - source_y)
		* cos(angle) + map->s->offset_x);
	map->i->isometric_y_start = map->v->zoom * ((source_x + source_y)
		* sin(angle) - (source_z * map->h->height_factor) + map->s->offset_y);
}

void	isometric_line_end(t_map *map, int source_x, int source_y, int source_z)
{
	float	angle;

	angle = PROJ_ANGLE * (M_PI / 180);
	map->i->isometric_x_end = map->v->zoom * ((source_x - source_y)
		* cos(angle) + map->s->offset_x);
	map->i->isometric_y_end = map->v->zoom * ((source_x + source_y)
		* sin(angle) - (source_z * map->h->height_factor) + map->s->offset_y);
}
