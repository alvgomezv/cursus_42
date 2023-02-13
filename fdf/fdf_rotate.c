/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:13:36 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/13 17:31:15 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *map, int x, int y, int z)
{
	int		prev_y;
	float	angle;

	map->r->rot_x = x;
	angle = map->r->alpha * (M_PI / 180);
	prev_y = y;
	map->r->rot_y = prev_y * cos(map->r->alpha) + (z) * sin(map->r->alpha);
	map->r->rot_z = -prev_y * sin(map->r->alpha) + (z) * cos(map->r->alpha);
}

void	rotate_y(t_map *map, int x, int y, int z)
{
	int		prev_x;
	float	angle;

	map->r->rot_y = y;
	angle = map->r->beta * (M_PI / 180);
	prev_x = x;
	map->r->rot_x = prev_x * cos(map->r->beta) + (z) * sin(map->r->beta);
	map->r->rot_z = -prev_x * sin(map->r->beta) + (z) * cos(map->r->beta);
}

void	rotate_z(t_map *map, int x, int y, int z)
{
	int		prev_x;
	int		prev_y;
	float	angle;

	map->r->rot_z = z;
	angle = map->r->gamma * (M_PI / 180);
	prev_x = x;
	prev_y = y;
	map->r->rot_x = prev_x * cos(map->r->gamma) - prev_y * sin(map->r->gamma);
	map->r->rot_y = prev_x * sin(map->r->gamma) + prev_y * cos(map->r->gamma);
}
