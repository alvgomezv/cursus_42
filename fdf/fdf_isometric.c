/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:30:17 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/06 18:19:14 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_pixel(t_map *map, int source_x, int source_y, int source_z)
{
	float	angle;

	angle = map->s->angle * (M_PI / 180);
	map->s->isometric_x = (source_x - source_y) * cos(angle) + map->s->offset_x;
	map->s->isometric_y = (source_x + source_y) * sin(angle)
		- (source_z * map->s->height_factor) + map->s->offset_y;
}

void	isometric_line_start(t_map *map, int source_x,
	int source_y, int source_z)
{
	float	angle;

	angle = map->s->angle * (M_PI / 180);
	map->s->isometric_x_start = (source_x - source_y)
		* cos(angle) + map->s->offset_x;
	map->s->isometric_y_start = (source_x + source_y)
		* sin(angle) - (source_z * map->s->height_factor) + map->s->offset_y;
}

void	isometric_line_end(t_map *map, int source_x, int source_y, int source_z)
{
	float	angle;

	angle = map->s->angle * (M_PI / 180);
	map->s->isometric_x_end = (source_x - source_y)
		* cos(angle) + map->s->offset_x;
	map->s->isometric_y_end = (source_x + source_y)
		* sin(angle) - (source_z * map->s->height_factor) + map->s->offset_y;
}
