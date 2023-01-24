/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:53:48 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/24 17:06:21 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./Libft/libft.h"
#include "./MLX42/include/MLX42/MLX42.h"
#include "./get_next_line/get_next_line.h"
#include <math.h>
#include <fcntl.h>


typedef struct s_map
{
	int	**map;
	int	x;
	int y;
}				t_map;

t_map	*get_map(char **argv);

#endif