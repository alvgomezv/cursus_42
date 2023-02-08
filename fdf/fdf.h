/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:53:48 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/08 17:19:22 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <fcntl.h>

# define SCRN_HEIGHT	1050
# define SCRN_WIDTH		1400
# define PROJ_ANGLE		30
# define CLR_SCRN		0x222222

typedef struct s_spec
{
	int		offset_x;
	int		offset_y;
	int		margin;
	float	spacing;
	int		*size_x;
	int		size_y;

}				t_spec;

typedef struct s_val
{
	int			max_x;
	int			max_y;
	int			min_x;
	int			min_y;
	float		zoom;
	float		zoom_factor;
}				t_val;

typedef struct s_col
{
	int		color_start;
	int		color_end;
	int		aux_color_start;
	int		aux_color_end;
}				t_col;

typedef struct s_iso
{
	int		isometric_x;
	int		isometric_y;
	int		isometric_z;
	int		isometric_x_start;
	int		isometric_y_start;
	int		isometric_x_end;
	int		isometric_y_end;
}				t_iso;

typedef struct s_height
{
	int		max_height;
	int		min_height;
	float	height_factor;
}				t_height;

typedef struct s_line
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
}				t_line;

typedef struct s_rot
{
	float	alpha;
	float	beta;
	float	gamma;
}				t_rot;

typedef struct s_map
{
	int			**map;
	t_spec		*s;
	t_val		*v;
	t_col		*c;
	t_iso		*i;
	t_height	*h;
	t_line		*l;
	t_rot		*r;
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_map;

//Main
void	draw_map(t_map *map, mlx_image_t *img);
void	initial_specifications(t_map *map);
void	draw_clear_background(t_map *map);
void	put_pixels(mlx_image_t *img, int x, int y, int color);

//Utils_1
t_map	*get_map(char **argv);
t_map	*inicialize_map(char **matrix);
void	fill_map(t_map	*map, char **matrix, int i, int j);
void	aux_fill_map(t_map	*map, int i, int cont);
void	print_map(t_map *map);

//Utils_2
void	ft_free_matrix(char **matrix);
char	**ft_realloc_char(char **matrix, int size);
int		*ft_realloc_map(int *matrix, int size);
void	ft_free_map(t_map *map);
void	ft_error(char *str);

//Colors
int		rgb_to_int(int red, int green, int blue, int alpha);
int		get_gradient_color(double fraction, int color_start, int color_end);
int		get_percentage_color(t_map *map, int height);

//Isometric
void	isometric_pixel(t_map *map, int source_x, int source_y, int source_z);
void	isometric_line_start(t_map *map, int source_x,
			int source_y, int source_z);
void	isometric_line_end(t_map *map, int source_x,
			int source_y, int source_z);

//Screen
void	find_min_and_max(t_map *map);
void	calculate_centers(t_map *map);
void	fit_into_screen(t_map *map);
void	inicialize_min_and_max(t_map *map);

//Draw_line
void	draw_line_with_colors(void *img, t_map *map,
			int height_start, int height_end);
void	draw_horizontal_lines(t_map *map, mlx_image_t *img);
void	draw_vertical_lines(t_map *map, mlx_image_t *img);
void	aux_line(t_map *map, int pixels, int height_start, int height_end);
void	draw_line(void *img, t_map *map);

//Hooks
//void	hook(void *param);
//void	key_hook(mlx_key_data_t keydata, void *param);
//void	my_scrollhook(double xdelta, double ydelta, void *param);
void	set_hooks(t_map *map);

//Rotate
void	projection_pixel(t_map *map, int source_x, int source_y, int source_z);
void	projection_line_start(t_map *map, int source_x, int source_y, int source_z);
void	projection_line_end(t_map *map, int source_x, int source_y, int source_z);

#endif