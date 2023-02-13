/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:59:30 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/13 17:32:08 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_pixel(t_map *map, int source_x, int source_y, int source_z)
{
	float	angle;

	angle = PROJ_ANGLE * (M_PI / 180);
	map->i->isometric_x = (source_x - source_y) * cos(angle);
	map->i->isometric_y = (source_x + source_y) * sin(angle)
		- source_z;
}

void	projection_pixel(t_map *map, int source_x, int source_y, int source_z)
{
	rotate_x(map, source_x, source_y, map->h->height_factor * source_z);
	rotate_y(map, map->r->rot_x, map->r->rot_y, map->r->rot_z);
	rotate_z(map, map->r->rot_x, map->r->rot_y, map->r->rot_z);
	if (map->p->type == 1)
	{
		isometric_pixel(map, map->r->rot_x, map->r->rot_y, map->r->rot_z);
		map->p->x = map->v->zoom * map->i->isometric_x + map->s->offset_x;
		map->p->y = map->v->zoom * map->i->isometric_y + map->s->offset_y;
	}
	else if (map->p->type == 0)
	{
		map->p->x = map->v->zoom * map->r->rot_x + map->s->offset_x;
		map->p->y = map->v->zoom * map->r->rot_y + map->s->offset_y;
	}
}

void	projection_line_start(t_map *map, int source_x,
			int source_y, int source_z)
{
	rotate_x(map, source_x, source_y, map->h->height_factor * source_z);
	rotate_y(map, map->r->rot_x, map->r->rot_y, map->r->rot_z);
	rotate_z(map, map->r->rot_x, map->r->rot_y, map->r->rot_z);
	if (map->p->type == 1)
	{
		isometric_pixel(map, map->r->rot_x, map->r->rot_y, map->r->rot_z);
		map->p->x_start = map->v->zoom * map->i->isometric_x + map->s->offset_x;
		map->p->y_start = map->v->zoom * map->i->isometric_y + map->s->offset_y;
	}
	else if (map->p->type == 0)
	{
		map->p->x_start = map->v->zoom * map->r->rot_x + map->s->offset_x;
		map->p->y_start = map->v->zoom * map->r->rot_y + map->s->offset_y;
	}
}

void	projection_line_end(t_map *map, int source_x,
			int source_y, int source_z)
{
	rotate_x(map, source_x, source_y, map->h->height_factor * source_z);
	rotate_y(map, map->r->rot_x, map->r->rot_y, map->r->rot_z);
	rotate_z(map, map->r->rot_x, map->r->rot_y, map->r->rot_z);
	if (map->p->type == 1)
	{
		isometric_pixel(map, map->r->rot_x, map->r->rot_y, map->r->rot_z);
		map->p->x_end = map->v->zoom * map->i->isometric_x + map->s->offset_x;
		map->p->y_end = map->v->zoom * map->i->isometric_y + map->s->offset_y;
	}
	else if (map->p->type == 0)
	{
		map->p->x_end = map->v->zoom * map->r->rot_x + map->s->offset_x;
		map->p->y_end = map->v->zoom * map->r->rot_y + map->s->offset_y;
	}
}
