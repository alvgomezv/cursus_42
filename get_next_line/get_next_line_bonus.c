/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:08:07 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/05 18:00:38 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_last_buff(char *last_buff, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		nbr_bytes;

	nbr_bytes = 1;
	while (ft_strchr(last_buff, '\n') == NULL && nbr_bytes != 0)
	{
		nbr_bytes = read(fd, buff, BUFFER_SIZE);
		if (nbr_bytes == -1)
			return (0);
		if (nbr_bytes == 0)
		{
			return (last_buff);
		}
		buff[nbr_bytes] = '\0';
		last_buff = ft_strjoin(last_buff, buff);
	}
	return (last_buff);
}

char	*get_line(char *last_buff)
{
	int		i;
	char	*line;

	i = 0;
	while (last_buff[i] != '\n' && last_buff[i] != '\0')
		i++;
	line = ft_substr(last_buff, 0, (i + 1));
	return (line);
}

char	*get_new_buffer(char *last_buff)
{
	int		i;
	char	*temp;

	i = 0;
	while (last_buff[i] != '\n' && last_buff[i] != '\0')
		i++;
	temp = ft_substr(last_buff, (i + 1), (ft_strlen(last_buff) - i - 1));
	free (last_buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*last_buff[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	last_buff[fd] = get_last_buff(last_buff[fd], fd);
	if (last_buff[fd] == 0)
		return (0);
	line = get_line(last_buff[fd]);
	last_buff[fd] = get_new_buffer(last_buff[fd]);
	return (line);
}
