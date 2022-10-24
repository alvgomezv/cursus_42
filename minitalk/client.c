/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:34:37 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/19 18:25:07 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	send_message(pid_t s_id, char *message)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (message[i] == 0)
			kill(s_id, SIGUSR1);
		else if (message[i] == 1)
			kill(s_id, SIGUSR2);
		i++;
		usleep(150);
	}
	free (message);
}

char	*convert_to_binary(char nbr)
{
	char	*message;
	int		i;
	char	aux;

	aux = nbr;
	i = 7;
	message = (char *)malloc(sizeof(char) * 8);
	if (message == 0)
		exit(EXIT_FAILURE);
	while (nbr > 0 && i > -1)
	{
		message[i] = (nbr % 2);
		nbr = nbr / 2;
		i--;
	}
	while (i >= 0)
	{
		message[i] = 0;
		i--;
	}
	return (message);
}

int	main(int argc, char **argv)
{
	pid_t	s_id;
	char	*message;
	int		i;

	i = 0;
	if (argc != 3)
		exit(EXIT_FAILURE);
	s_id = (pid_t)ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		message = convert_to_binary((char)argv[2][i]);
		send_message(s_id, message);
		i++;
	}
	return (0);
}
