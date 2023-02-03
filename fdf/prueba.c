#include "fdf.h"

int rgb_to_int(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
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


void draw_line_with_colors(void *img, int beginX, int beginY, int endX, int endY, int color_start, int color_end)
{
	double fraction;
	int	current_color;
	double deltaX;
	double deltaY;
	double pixelX;
	double pixelY;
	int pixels;
	int i;

	i = 0;
	deltaX = endX - beginX;
	deltaY = endY - beginY;

	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = beginX;
	pixelY = beginY;

	while (i <= pixels)
	{
	    fraction = (double) i / (double) pixels;
		current_color = get_gradient_color(fraction, color_start, color_end);
		mlx_put_pixel(img, pixelX, pixelY, current_color);
	    pixelX += deltaX;
	    pixelY += deltaY;
		i++;
	}	
}


void	hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	
	
	mlx = mlx_init(1000, 1000, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
		
	img = mlx_new_image(mlx, 1000, 1000);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit(EXIT_SUCCESS);
	
	ft_printf("%d\n", rgb_to_int(64, 60, 212, 255));
	draw_line_with_colors(img, 0, 0, 800, 800, rgb_to_int(64, 60, 212, 255), rgb_to_int(29, 207, 18, 255));

	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	
	return (EXIT_SUCCESS);
}