/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:05:53 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/08 17:10:25 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	//if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
	//	draw_clear_background(map);
	//if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	//	g_img->instances[0].y += 5;
	//if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	//	g_img->instances[0].x -= 5;
	//if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	//	g_img->instances[0].x += 5;
}

//void	key_hook(mlx_key_data_t keydata, void *param)
//{
//	if (keydata.key == MLX_KEY_A && keydata.action
//		== MLX_RELEASE && keydata.modifier == MLX_CONTROL)
//		puts("Gotta grab it all!");
//

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (ydelta > 0)
	{
		puts("Up!");
		//if (map->h->height_factor > 0 && map->h->height_factor <= 5)
		//	map->h->height_factor *= 2;
		if (map->v->zoom <= 4)
			map->v->zoom *= 1.1;
		
		//map->r->alpha += 0.03;
	}
	else if (ydelta < 0)
	{
		puts("Down!");
		//if (map->h->height_factor > 0)
		//	map->h->height_factor /= 2;

		if (map->v->zoom >= 0.001)
			map->v->zoom /= 1.1;
		
		//map->r->beta -= 0.03;
	}
	draw_map(map, map->img);
	printf("%f\n", map->v->zoom);
	xdelta = 0;
}

//void	my_mousefunc(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
//{
//	
//}

void	set_hooks(t_map *map)
{
	mlx_loop_hook(map->mlx, &hook, map);
	//mlx_key_hook(mlx, &key_hook, map);
	mlx_scroll_hook(map->mlx, &my_scrollhook, map);
	//mlx_mouse_hook(map->mlx, &my_mousefunc, map);
}
