/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:05:53 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/13 18:15:52 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_1(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_1))
		if (map->h->height_factor > 0 && map->h->height_factor <= 20)
			map->h->height_factor *= 1.2;
	if (mlx_is_key_down(map->mlx, MLX_KEY_2))
		if (map->h->height_factor > 0)
			map->h->height_factor /= 1.2;
	if (mlx_is_key_down(map->mlx, MLX_KEY_P))
	{
		if (map->p->type == 1)
			map->p->type = 0;
		else
			map->p->type = 1;
		map->r->alpha = 0;
		map->r->beta = 0;
		map->r->gamma = 0;
		usleep(100000);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_C))
		change_colors(map);
	draw_map(map, map->img);
}

void	hook_2(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_X))
		map->r->alpha += 0.1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_Y))
		map->r->beta += 0.1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_Z))
		map->r->gamma += 0.1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->s->offset_y -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->s->offset_y += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->s->offset_x -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->s->offset_x += 5;
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (ydelta > 0)
	{
		if (map->v->zoom <= 10)
			map->v->zoom *= 1.1;
	}
	else if (ydelta < 0)
	{
		if (map->v->zoom >= 0.001)
			map->v->zoom /= 1.1;
	}
	draw_map(map, map->img);
	xdelta = 0;
}

void	set_hooks(t_map *map)
{
	mlx_loop_hook(map->mlx, &hook_1, map);
	mlx_loop_hook(map->mlx, &hook_2, map);
	mlx_scroll_hook(map->mlx, &my_scrollhook, map);
}
