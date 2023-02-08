/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:13:36 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/08 17:00:34 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_map *map, int x, int y, int z)
{
	int		prev_y;
	float	angle;

	x = 0;
	angle = map->r->alpha * (M_PI / 180);
	prev_y = y;
	map->i->isometric_y = prev_y * cos(map->r->alpha) + (z) * sin(map->r->alpha);
	map->i->isometric_z = -prev_y * sin(map->r->alpha) + (z) * cos(map->r->alpha);
}

//static void	rotate_y(t_map *map, int x, int y, int z)
//{
//	int	prev_x;
//	float	angle;
//
//	y = 0;
//	angle = map->r->alpha * (M_PI / 180);
//	prev_x = x;
//	map->i->isometric_x = prev_x * cos(map->r->beta) + (z) * sin(map->r->beta);
//	map->i->isometric_z = -prev_x * sin(map->r->beta) + (z) * cos(map->r->beta);
//}
//
//static void	rotate_z(t_map *map, int x, int y, int z)
//{
//	int	prev_x;
//	int	prev_y;
//	float	angle;
//
//	z = 0;
//	angle = map->r->alpha * (M_PI / 180);
//	prev_x = x;
//	prev_y = y;
//	map->i->isometric_x = prev_x * cos(map->r->gamma) - prev_y * sin(map->r->gamma);
//	map->i->isometric_y= prev_x * sin(map->r->gamma) + prev_y * cos(map->r->gamma);
//}

void	projection_pixel(t_map *map, int source_x, int source_y, int source_z)
{
	map->i->isometric_x = source_x;
	//map->i->isometric_y = source_y;
	//map->i->isometric_z = source_z;
	rotate_x(map, source_x, source_y, source_z);
	//rotate_y(map, source_x, source_y, source_z);
	//rotate_z(map, source_x, source_y, source_z);
	isometric_pixel(map, map->i->isometric_x, map->i->isometric_y, map->i->isometric_z);
}

void	projection_line_start(t_map *map, int source_x, int source_y, int source_z)
{
	map->i->isometric_x = source_x;
	//map->i->isometric_y = source_y;
	//map->i->isometric_z = source_z;
	rotate_x(map, source_x, source_y, source_z);
	//rotate_y(map, source_x, source_y, source_z);
	//rotate_z(map, source_x, source_y, source_z);
	isometric_line_start(map, map->i->isometric_x, map->i->isometric_y, map->i->isometric_z);
}

void	projection_line_end(t_map *map, int source_x, int source_y, int source_z)
{
	map->i->isometric_x = source_x;
	//map->i->isometric_y = source_y;
	//map->i->isometric_z = source_z;
	rotate_x(map, source_x, source_y, source_z);
	//rotate_y(map, source_x, source_y, source_z);
	//rotate_z(map, source_x, source_y, source_z);
	isometric_line_end(map, map->i->isometric_x, map->i->isometric_y, map->i->isometric_z);
}
