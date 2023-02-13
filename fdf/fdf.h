/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:53:48 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/13 17:57:20 by alvgomez         ###   ########.fr       */
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
# define CLR_START		0xFFFF00FF
# define CLR_END		0xFF00FFFF

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
	unsigned int	color_start;
	unsigned int	color_end;
	int				aux_color_start;
	int				aux_color_end;
	int				r;
	int				g;
	int				b;
}				t_col;

typedef struct s_iso
{
	int		isometric_x;
	int		isometric_y;
	int		isometric_z;
}				t_iso;

typedef struct s_project
{
	int		x;
	int		y;
	int		z;
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	int		type;
}				t_project;

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
	int		rot_x;
	int		rot_y;
	int		rot_z;
}				t_rot;

typedef struct s_map
{
	int			**map;
	t_spec		*s;
	t_val		*v;
	t_col		*c;
	t_iso		*i;
	t_project	*p;
	t_height	*h;
	t_line		*l;
	t_rot		*r;
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_map;

//Main
void	initial_specifications(t_map *map);
void	draw_clear_background(t_map *map);
void	put_pixels(mlx_image_t *img, int x, int y, int color);
int		check_map(t_map *map);

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
void	change_colors(t_map *map);

//Screen
void	find_min_and_max(t_map *map);
void	center_projection(t_map *map);
void	fit_into_screen(t_map *map);
void	inicialize_min_and_max(t_map *map);
void	set_min_max_height(t_map *map);

//Draw
void	draw_map(t_map *map, mlx_image_t *img);
void	draw_line_with_colors(void *img, t_map *map,
			int height_start, int height_end);
void	draw_horizontal_lines(t_map *map, mlx_image_t *img);
void	draw_vertical_lines(t_map *map, mlx_image_t *img);

//Hooks
void	set_hooks(t_map *map);

//Rotate
void	rotate_x(t_map *map, int x, int y, int z);
void	rotate_y(t_map *map, int x, int y, int z);
void	rotate_z(t_map *map, int x, int y, int z);

//Projection
void	isometric_pixel(t_map *map, int source_x, int source_y, int source_z);
void	projection_pixel(t_map *map, int source_x, int source_y, int source_z);
void	projection_line_start(t_map *map, int source_x,
			int source_y, int source_z);
void	projection_line_end(t_map *map, int source_x,
			int source_y, int source_z);

#endif