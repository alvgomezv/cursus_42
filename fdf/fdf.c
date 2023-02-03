/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:14 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/03 13:47:22 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define BPP sizeof(int32_t)

void	leaks(void)
{
	system("leaks -q fdf");
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->s->size_y)
	{
		free(map->map[i]);
		i++;
	}
	free (map->map);
	free (map->s);
	free (map->v);
	free (map);
}

void	hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	//if (mlx_is_key_down(mlx, MLX_KEY_UP))
	//	g_img->instances[0].y -= 5;
	//if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	//	g_img->instances[0].y += 5;
	//if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	//	g_img->instances[0].x -= 5;
	//if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	//	g_img->instances[0].x += 5;
}

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	key_hook(mlx_key_data_t keydata, void* param)
{
	param = 0;
	
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && keydata.modifier == MLX_CONTROL)
		puts("Gotta grab it all!");
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	param = 0;
	
	// Simple up or down detection.
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	
	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

//Casi que la podemos borrar
/*void draw_line(void *img, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX;
	double deltaY;
	double pixelX;
	double pixelY;
	int pixels;

	deltaX = endX - beginX;
	deltaY = endY - beginY;

	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = beginX;
	pixelY = beginY;

	while (pixels)
	{
	    mlx_put_pixel(img, pixelX, pixelY, color);
	    pixelX += deltaX;
	    pixelY += deltaY;
	    --pixels;
	}	
}*/

//Esta ya si funciona bien sin colores
/*void draw_line(void *img, t_map *map)
{
	int pixels;

	map->s->delta_x = map->s->isometric_x_end - map->s->isometric_x_start;
	map->s->delta_y = map->s->isometric_y_end - map->s->isometric_y_start;

	pixels = sqrt((map->s->delta_x  * map->s->delta_x ) + (map->s->delta_y * map->s->delta_y));

	map->s->delta_x /= pixels;
	map->s->delta_y /= pixels;
	map->s->pixel_x = map->s->isometric_x_start;
	map->s->pixel_y = map->s->isometric_y_start;
	
	while (pixels)
	{
		mlx_put_pixel(img, map->s->pixel_x, map->s->pixel_y, map->s->color_start);
	    map->s->pixel_x += map->s->delta_x;
	    map->s->pixel_y += map->s->delta_y;
	    --pixels;
	}	
}*/

int rgb_to_int(int red, int green, int blue, int alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

int get_gradient_color(double fraction, int color_start, int color_end)
{
    int red;
    int green;
    int blue;
    int alpha;

	red = (color_start >> 24 & 0xff) + fraction * ((color_end >> 24 & 0xff) - (color_start >> 24 & 0xff));
    green = (color_start >> 16 & 0xff) + fraction * ((color_end >> 16 & 0xff) - (color_start >> 16 & 0xff));
    blue = (color_start >> 8 & 0xff) + fraction * ((color_end >> 8 & 0xff) - (color_start >> 8 & 0xff));
    alpha = (color_start & 0xff) + fraction * ((color_end & 0xff) - (color_start & 0xff));

    return (red << 24) | (green << 16) | (blue << 8) | alpha;
}

int	get_percentage_color(t_map *map, int height)
{
	float	percentage;
	int		color;
	
	percentage = (double)(height - map->s->min_height) / (double)(map->s->max_height - map->s->min_height);
	color = get_gradient_color(percentage, map->s->color_start, map->s->color_end);
	if (map->s->max_height == map->s->min_height)
		color = map->s->color_start;
	//printf("%f\n", percentage);
	
	return(color);
}

void draw_line_with_colors(void *img, t_map *map, int height_start, int height_end)
{
	int pixels;
	float percentage;
	int	current_color;
	int i;
	int aux_color_start;
	int	aux_color_end;

	i = 0;
	map->s->delta_x = map->s->isometric_x_end - map->s->isometric_x_start;
	map->s->delta_y = map->s->isometric_y_end - map->s->isometric_y_start;

	pixels = sqrt((map->s->delta_x  * map->s->delta_x ) + (map->s->delta_y * map->s->delta_y));

	map->s->delta_x /= pixels;
	map->s->delta_y /= pixels;
	map->s->pixel_x = map->s->isometric_x_start;
	map->s->pixel_y = map->s->isometric_y_start;
	aux_color_start = get_percentage_color(map, height_start);
	aux_color_end = get_percentage_color(map, height_end);
	while (i <= pixels)
	{
	    percentage = (double) i / (double) pixels;
		current_color = get_gradient_color(percentage, aux_color_start, aux_color_end);
		mlx_put_pixel(img, map->s->pixel_x, map->s->pixel_y, current_color);
	    map->s->pixel_x += map->s->delta_x;
	    map->s->pixel_y += map->s->delta_y;
		i++;
	}	
}

void	isometric_pixel(t_map *map, int source_x, int source_y, int source_z)
{
	float	angle;
	
	angle = map->s->angle * (M_PI / 180);
	map->s->isometric_x = (source_x - source_y) * cos(angle) + map->s->offset_x;
	map->s->isometric_y = (source_x + source_y) * sin(angle) - source_z + map->s->offset_y;
	//ft_printf("iso y = %d\n", map->s->isometric_x);
}

void	isometric_line_start(t_map *map, int source_x, int source_y, int source_z)
{
	float	angle;
	
	angle = map->s->angle * (M_PI / 180);
	map->s->isometric_x_start = (source_x - source_y) * cos(angle) + map->s->offset_x;
	map->s->isometric_y_start = (source_x + source_y) * sin(angle) - source_z + map->s->offset_y;
}

void	isometric_line_end(t_map *map, int source_x, int source_y, int source_z)
{
	float	angle;
	
	angle = map->s->angle * (M_PI / 180);
	map->s->isometric_x_end = (source_x - source_y) * cos(angle) + map->s->offset_x;
	map->s->isometric_y_end = (source_x + source_y) * sin(angle) - source_z + map->s->offset_y;
}

void	draw_horizontal_lines(t_map *map, mlx_image_t *img)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while(i < map->s->size_y)
	{ 
		while(j < (map->s->size_x - 1))
		{
			isometric_line_start(map, j * map->s->spacing, i * map->s->spacing, map->map[i][j]);
			isometric_line_end(map, (j + 1) * map->s->spacing, i * map->s->spacing, map->map[i][j + 1]);
			//draw_line(img, map->s->isometric_x_start, map->s->isometric_y_start, map->s->isometric_x_end, map->s->isometric_y_end, map->s->color);
			draw_line_with_colors(img, map, map->map[i][j], map->map[i][j + 1]);
			j++;
		}
	j = 0;
	i++;
	}
}

void	draw_vertical_lines(t_map *map, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < (map->s->size_y - 1))
	{ 
		while(j < map->s->size_x)
		{
			isometric_line_start(map, j * map->s->spacing, i * map->s->spacing, map->map[i][j]);
			isometric_line_end(map, j * map->s->spacing, (i + 1) * map->s->spacing, map->map[i + 1][j]);
			//draw_line(img, map->s->isometric_x_start, map->s->isometric_y_start, map->s->isometric_x_end, map->s->isometric_y_end, map->s->color);
			draw_line_with_colors(img, map, map->map[i][j], map->map[i + 1][j]);
			j++;
		}
	j = 0;
	i++;
	}
}

void	find_min_and_max(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	isometric_pixel(map, (0), (0), map->map[0][0]);
	map->v->max_x = map->s->isometric_x;
	map->v->min_x = map->s->isometric_x;
	map->v->max_y = map->s->isometric_y;
	map->v->min_y = map->s->isometric_y;
	while(i < map->s->size_y)
	{ 
		while(j < map->s->size_x)
		{
			isometric_pixel(map, (j * map->s->spacing), (i * map->s->spacing), map->map[i][j]);
			//ft_printf("iso y = %d\n", map->s->isometric_x);
			//ft_printf("max y = %d\n", map->s->max_y);
			//ft_printf("min x = %d\n", map->s->min_x);
			//ft_printf("min y = %d\n", map->s->min_y);
			if (map->s->isometric_x > map->v->max_x)
				map->v->max_x = map->s->isometric_x;
			if (map->s->isometric_x < map->v->min_x)
				map->v->min_x = map->s->isometric_x;
			if (map->s->isometric_y > map->v->max_y)
				map->v->max_y = map->s->isometric_y;
			if (map->s->isometric_y < map->v->min_y)
				map->v->min_y = map->s->isometric_y;
		j++;
		}
	j = 0;
	i++;
	}
	//ft_printf("max x = %d\n", map->v->max_x);
	//ft_printf("max y = %d\n", map->v->max_y);
	//ft_printf("min x = %d\n", map->v->min_x);
	//ft_printf("min y = %d\n", map->v->min_y);
}

void	calculate_centers(t_map *map)
{
	float		center_x;
	float		center_y;
	float		win_center_x;
	float		win_center_y;
	
	center_x = (map->v->max_x + map->v->min_x) / 2;
	center_y = (map->v->max_y + map->v->min_y) / 2;
	win_center_x = map->s->win_x / 2;
	win_center_y = map->s->win_y / 2;
	map->s->offset_x += win_center_x - center_x;
	map->s->offset_y += win_center_y - center_y;
}

void	fit_into_screen(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//while(i < map->s->size_y)
	//{ 
	//	while(j < map->s->size_x)
	//	{
	//		isometric_pixel(map, (j * map->s->spacing), (i * map->s->spacing), map->map[i][j]);
	//		while (map->s->isometric_x < map->s->margin_x)
	//		{
	//			map->s->offset_x++;
	//			isometric_pixel(map, (j * map->s->spacing), (i * map->s->spacing), map->map[i][j]);
	//		}
	//		while (map->s->isometric_y < map->s->margin_y)
	//		{
	//			map->s->offset_y++;
	//			isometric_pixel(map, (j * map->s->spacing), (i * map->s->spacing), map->map[i][j]);
	//		}
	//		j++;
	//	}
	//j = 0;
	//i++;
	//}
	find_min_and_max(map);
	calculate_centers(map);
	while ((map->v->min_x < map->s->margin) || (map->v->max_x  > (map->s->win_x - map->s->margin))
		|| (map->v->min_y < map->s->margin) || (map->v->max_y  > (map->s->win_y - map->s->margin)))
	{ 
		map->s->spacing--;
		//ft_printf("spacing = %d\n", map->s->spacing);
		find_min_and_max(map);
		calculate_centers(map);
		//ft_printf("x = %d\n", map->s->isometric_x);
		//ft_printf("off x = %d\n", map->s->offset_x);
		//ft_printf("off y = %d\n", map->s->offset_y);
	}
}

void	draw_map(t_map *map, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < map->s->size_y)
	{ 
		while(j < map->s->size_x)
		{
			if (map->map[i][j] > map->s->max_height)
				map->s->max_height = map->map[i][j];
			if (map->map[i][j] < map->s->min_height)
				map->s->min_height = map->map[i][j];
			isometric_pixel(map, (j * map->s->spacing), (i * map->s->spacing), map->map[i][j]);
			//ft_printf("x = %d\n", map->s->isometric_x);
			//ft_printf("y = %d\n", map->s->isometric_y);
			mlx_put_pixel(img, map->s->isometric_x, map->s->isometric_y, map->s->color_start);
			j++;
		}
	j = 0;
	i++;
	}
	draw_horizontal_lines(map, img);
	draw_vertical_lines(map, img);
}

void	initial_specifications(t_map *map)
{
	map->s->color_start = rgb_to_int(243, 255, 0, 255);
	map->s->color_end = rgb_to_int(255, 39, 0, 255);
	map->s->max_height = map->map[0][0];
	map->s->min_height = map->map[0][0];
	map->s->spacing = 200;
	map->s->angle = 30;
	map->s->margin = 50;
	map->s->offset_x = 0;
	map->s->offset_y = 0;
	map->s->win_x = 1500;
	map->s->win_y = 1000;
	isometric_pixel(map, (0), (0), map->map[0][0]);
	map->v->max_x = 0;
	map->v->min_x = 0;
	map->v->max_y = 0;
	map->v->min_y = 0;
}

void	print_map(t_map *map)
{
	int i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < map->s->size_y)
	{
		while(j < map->s->size_x)
		{
			ft_printf("%d ", map->map[i][j]);
			j++;
		}
	ft_printf("\n");
	j = 0;
	i++;
	}
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	
	if (argc != 2)
		exit(EXIT_FAILURE);
	map = get_map(argv);
	print_map(map);

	initial_specifications(map);
	
	ft_printf("x = %d\n", map->s->size_x);
	ft_printf("y = %d\n", map->s->size_y);

	//ft_printf("off x = %d\n", map->s->offset_x);
	//ft_printf("off y = %d\n", map->s->offset_y);
	//ft_printf("------\n");
	
	fit_into_screen(map);

	//ft_printf("%d\n", map->s->win_x);
	//ft_printf("%d\n", map->s->win_y);
	
	mlx = mlx_init(map->s->win_x, map->s->win_y, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
		
	img = mlx_new_image(mlx, map->s->win_x, map->s->win_y);
	//memset(g_img->pixels, 255, g_img->width * g_img->height * BPP);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	
	draw_map(map, img);
	//ft_printf("%d\n", map->s->max_height);
	

	//ft_printf("max x %d\n", map->v->max_x);
	//ft_printf("max y %d\n", map->v->max_y);
	//ft_printf("min x %d\n", map->v->min_x);
	//ft_printf("min y %d\n", map->v->min_y);
	
	mlx_loop_hook(mlx, &hook, mlx);
	//mlx_key_hook(mlx, &key_hook, NULL);
	//mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	
	ft_free_map(map);
	
	//atexit(leaks);
	return (EXIT_SUCCESS);
}
