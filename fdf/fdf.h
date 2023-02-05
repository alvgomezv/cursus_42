/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:53:48 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/03 12:35:01 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include "./get_next_line/get_next_line.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_spec
{
	float	angle;
	int		offset_x;
	int		offset_y;
	int		margin;
	float	spacing;
	int		color_start;
	int		color_end;
	int		max_height;
	int		min_height;
	int		isometric_x;
	int		isometric_y;
	int		isometric_x_start;
	int		isometric_y_start;
	int		isometric_x_end;
	int		isometric_y_end;
	double 	delta_x;
	double 	delta_y;
	double 	pixel_x;
	double 	pixel_y;
	int		win_x;
	int		win_y;
	int		*size_x;
	int		size_y;
	float	height_factor;
}				t_spec;

typedef struct s_val
{
	int			max_x;
	int			max_y;
	int			min_x;
	int			min_y;
}				t_val;

typedef struct s_map
{
	int		**map;
	t_spec	*s;
	t_val	*v;
}				t_map;



t_map	*get_map(char **argv);

#endif