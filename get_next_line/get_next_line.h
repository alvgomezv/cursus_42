/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:07:18 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/04 11:49:45 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);

int		ft_strlen(char *s);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_substr(char *s, int start, int len);

char	*ft_strchr(char *s, int c);

#endif