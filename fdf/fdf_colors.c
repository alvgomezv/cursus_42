/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:52:29 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/06 11:56:28 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb_to_int(int red, int green, int blue, int alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
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

	percentage = (double)(height - map->s->min_height)
		/ (double)(map->s->max_height - map->s->min_height);
	color = get_gradient_color(percentage,
			map->s->color_start, map->s->color_end);
	if (map->s->max_height == map->s->min_height)
		color = map->s->color_start;
	return (color);
}
