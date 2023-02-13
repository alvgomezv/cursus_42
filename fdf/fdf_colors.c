/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:52:29 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/13 16:40:21 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb_to_int(int red, int green, int blue, int alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

void	change_colors(t_map *map)
{
	if (map->c->r == 1000)
	{
		map->c->r = 255;
		map->c->g = 255;
		map->c->b = 0;
	}
	else if (map->c->r > 0 && map->c->g == 255 && map->c->b == 0)
		map->c->r -= 5;
	else if (map->c->r == 0 && map->c->g == 255 && map->c->b < 255)
		map->c->b += 5;
	else if (map->c->r < 255 && map->c->g == 0 && map->c->b == 255)
		map->c->r += 5;
	else if (map->c->r == 0 && map->c->g > 0 && map->c->b == 255)
		map->c->g -= 5;
	else if (map->c->r == 255 && map->c->g == 0 && map->c->b > 0)
		map->c->b -= 5;
	else
	{
		map->c->r = 255;
		map->c->g = 255;
		map->c->b = 0;
	}
	map->c->color_start = rgb_to_int(map->c->r, map->c->g, map->c->b, 255);
	map->c->color_end = rgb_to_int(map->c->g, map->c->b, map->c->r, 255);
}

int	get_gradient_color(double fraction, int color_start, int color_end)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = (color_start >> 24 & 0xff) + fraction
		* ((color_end >> 24 & 0xff) - (color_start >> 24 & 0xff));
	green = (color_start >> 16 & 0xff) + fraction
		* ((color_end >> 16 & 0xff) - (color_start >> 16 & 0xff));
	blue = (color_start >> 8 & 0xff) + fraction
		* ((color_end >> 8 & 0xff) - (color_start >> 8 & 0xff));
	alpha = (color_start & 0xff) + fraction
		* ((color_end & 0xff) - (color_start & 0xff));
	return ((red << 24) | (green << 16) | (blue << 8) | alpha);
}

int	get_percentage_color(t_map *map, int height)
{
	float	percentage;
	int		color;

	percentage = (double)(height - map->h->min_height)
		/ (double)(map->h->max_height - map->h->min_height);
	color = get_gradient_color(percentage,
			map->c->color_start, map->c->color_end);
	if (map->h->max_height == map->h->min_height)
		color = map->c->color_start;
	return (color);
}
