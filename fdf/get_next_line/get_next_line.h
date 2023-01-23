/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:07:18 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/23 19:00:53 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);

int		ft_strlen_gnl(char *s);

char	*ft_strjoin_gnl(char *s1, char *s2);

char	*ft_substr_gnl(char *s, int start, int len);

char	*ft_strchr_gnl(char *s, int c);

#endif