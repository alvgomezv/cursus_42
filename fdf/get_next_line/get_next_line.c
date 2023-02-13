/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:08:07 by alvgomez          #+#    #+#             */
/*   Updated: 2023/02/13 18:05:26 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_last_buff(char *last_buff, int fd)
{
	char	*buff;
	int		nbr_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	nbr_bytes = BUFFER_SIZE;
	while (ft_strchr_gnl(last_buff, '\n') == NULL && nbr_bytes == BUFFER_SIZE)
	{
		nbr_bytes = read(fd, buff, BUFFER_SIZE);
		if (nbr_bytes == 0)
		{
			free (buff);
			return (last_buff);
		}
		buff[nbr_bytes] = '\0';
		last_buff = ft_strjoin_gnl(last_buff, buff);
	}
	free (buff);
	return (last_buff);
}

char	*get_line(char *last_buff)
{
	int		i;
	char	*line;

	i = 0;
	while (last_buff[i] != '\n' && last_buff[i] != '\0')
		i++;
	line = ft_substr_gnl(last_buff, 0, (i + 1));
	return (line);
}

char	*get_new_buffer(char *last_buff)
{
	int		i;
	char	*temp;

	i = 0;
	while (last_buff[i] != '\n' && last_buff[i] != '\0')
		i++;
	temp = ft_substr_gnl(last_buff, (i + 1),
			(ft_strlen_gnl(last_buff) - i - 1));
	free (last_buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*last_buff;
	char		*line;
	int			x;

	x = 0;
	if (fd == -1)
		return (0);
	if (read(fd, &x, 0) < 0)
	{
		free (last_buff);
		return (0);
	}
	last_buff = get_last_buff(last_buff, fd);
	if (last_buff == 0)
		return (0);
	line = get_line(last_buff);
	last_buff = get_new_buffer(last_buff);
	return (line);
}
