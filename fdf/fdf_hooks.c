/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:05:53 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/06 18:19:07 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	hook(void *param)
//{
//	t_map	*map;
//	
//	map = (t_map *)param;
//	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
//		mlx_close_window(param);
//	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
//		draw_clear_background(map);
//	//if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
//	//	g_img->instances[0].y += 5;
//	//if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
//	//	g_img->instances[0].x -= 5;
//	//if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
//	//	g_img->instances[0].x += 5;
//}

//void	key_hook(mlx_key_data_t keydata, void *param)
//{
//	if (keydata.key == MLX_KEY_A && keydata.action
//		== MLX_RELEASE && keydata.modifier == MLX_CONTROL)
//		puts("Gotta grab it all!");
//}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	// Simple up or down detection.
	if (ydelta > 0)
	{
		//ft_printf("%d\n", map->s->margin);
		puts("Up!");
		map->s->height_factor += 0.01;
	}
	else if (ydelta < 0)
	{
		puts("Down!");
		map->s->height_factor -= 0.01;
	}
	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
	draw_map(map, map->img);
}


void	set_hooks(t_map *map)
{
	//mlx_loop_hook(map->mlx, &hook, map);
	//mlx_key_hook(mlx, &key_hook, map);
	mlx_scroll_hook(map->mlx, &my_scrollhook, map);
}
