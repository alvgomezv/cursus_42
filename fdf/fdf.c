/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:14 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/23 19:07:32 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIDTH 500
#define HEIGHT 500
#define BPP sizeof(int32_t)

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



int32_t	main(int argc, char **argv)
{
	mlx_t	*mlx;
	mlx_image_t	*img;

	if (argc != 2)
		exit(EXIT_FAILURE);
	read_map(argv);
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
		
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	//memset(g_img->pixels, 255, g_img->width * g_img->height * BPP);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	
	//mlx_put_pixel(img, WIDTH/2, HEIGHT/2, 0xFFFFFF);
	draw_line(img, 0, 0, 200, 200, 0xFFFFFF);
	
	mlx_loop_hook(mlx, &hook, mlx);
	//mlx_key_hook(mlx, &key_hook, NULL);
	//mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
