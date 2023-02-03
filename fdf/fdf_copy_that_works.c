/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_copy_that_works.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:14 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/27 11:47:29 by alvgomez         ###   ########.fr       */
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
	while (i < map->size_y)
	{
		free(map->map[i]);
		i++;
	}
	free (map->map);
	free (map->s);
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


//Todo este código es el antiguo sin usar el struct con todas las variables
void draw_line(void *img, int beginX, int beginY, int endX, int endY, int color)
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
}

int	isometric_x(int	source_x, int source_y, int source_z, int offset_x)
{
	int		destination_x;
	float 	angle;
	
	angle = 30 * (M_PI / 180);
	destination_x = (source_x - source_y) * cos(angle) + offset_x;
	return (destination_x);
}

int	isometric_y(int	source_x, int source_y, int source_z, int offset_y)
{
	int		destination_y;
	float	angle;
	
	angle = 30 * (M_PI / 180);
	destination_y = (source_x + source_y) * sin(angle) - source_z + offset_y;
	return (destination_y);
}

void	draw_map(t_map *map, mlx_image_t *img)
{
	int	i;
	int	j;
	int offset_x;
	int	offset_y;
	int	spacing;
	int	pixel_x_start;
	int	pixel_y_start;
	
	int	pixel_x_end;
	int	pixel_y_end;
	

	offset_x = 350;
	offset_y = 200;
	spacing = 30;
	i = 0;
	j = 0;
	while(i < map->size_y)
	{ 
		while(j < map->size_x)
		{
			pixel_x_start = isometric_x ((j * spacing), (i * spacing), map->map[i][j], offset_x);
			pixel_y_start = isometric_y ((j * spacing), (i * spacing), map->map[i][j], offset_y);
			mlx_put_pixel(img, pixel_x_start, pixel_y_start, 0xFFFFFF);
			j++;
		}
	j = 0;
	i++;
	}
	
	i = 0;
	j = 0;
	while(i < map->size_y)
	{ 
		while(j < (map->size_x - 1))
		{
			pixel_x_start = isometric_x (j * spacing, i * spacing, map->map[i][j], offset_x);
			pixel_y_start = isometric_y (j * spacing, i * spacing, map->map[i][j], offset_y);
			pixel_x_end = isometric_x ((j + 1) * spacing, i * spacing, map->map[i][j + 1], offset_x);
			pixel_y_end = isometric_y ((j + 1) * spacing, i * spacing, map->map[i][j + 1], offset_y);	
			draw_line(img, pixel_x_start, pixel_y_start, pixel_x_end, pixel_y_end, 0xFFFFFF);
			//mlx_put_pixel(img, pixel_x, pixel_y, 0xFFFFFF);
			j++;
		}
	j = 0;
	i++;
	}
	
	i = 0;
	j = 0;
	while(i < (map->size_y - 1))
	{ 
		while(j < map->size_x)
		{
			pixel_x_start = isometric_x (j * spacing, i * spacing, map->map[i][j], offset_x);
			pixel_y_start = isometric_y (j * spacing, i * spacing, map->map[i][j], offset_y);
			pixel_x_end = isometric_x (j * spacing, (i + 1) * spacing, map->map[i + 1][j], offset_x);
			pixel_y_end = isometric_y (j * spacing, (i + 1) * spacing, map->map[i + 1][j], offset_y);	
			draw_line(img, pixel_x_start, pixel_y_start, pixel_x_end, pixel_y_end, 0xFFFFFF);
			//mlx_put_pixel(img, pixel_x, pixel_y, 0xFFFFFF);
			j++;
		}
	j = 0;
	i++;
	}
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	//int 		i;
	//int		j;
	
	if (argc != 2)
		exit(EXIT_FAILURE);
	map = get_map(argv);
	ft_printf("%d\n", map->win_x);
	ft_printf("%d\n", map->win_y);
	mlx = mlx_init(map->win_x, map->win_y, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
		
	img = mlx_new_image(mlx, map->win_x, map->win_y);
	//memset(g_img->pixels, 255, g_img->width * g_img->height * BPP);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	
	//mlx_put_pixel(img, WIDTH/2, HEIGHT/2, 0xFFFFFF);
	
	//draw_line(img, 0, 0, 200, 200, 0xFFFFFF);

	draw_map(map, img);
	
	mlx_loop_hook(mlx, &hook, mlx);
	//mlx_key_hook(mlx, &key_hook, NULL);
	//mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	
	//ft_printf("x = %d\n", map->size_x);
	//ft_printf("y = %d\n", map->size_y);
	//
	//i = 0;
	//j = 0;
	//while (i < map->size_y)
	//{
	//	while(j < map->size_x)
	//	{
	//		ft_printf("%d ", map->map[i][j]);
	//		j++;
	//	}
	//ft_printf("\n");
	//j = 0;
	//i++;
	//}
	
	ft_free_map(map);
	
	//atexit(leaks);
	return (EXIT_SUCCESS);
}
