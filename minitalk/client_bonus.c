/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:34:37 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/20 11:05:43 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#define DELAY 100 //cambio no importante

int	g_global;

void	handle_signal(int sig)
{
	g_global = 1;
	return ;
}

void	send_message(pid_t s_id, unsigned char *message)
{
	int					i;
	struct sigaction	sa;

	sa.sa_handler = &handle_signal;
	sa.sa_flags = 0; //SA_SIGINFO | SA_RESTART; cambio
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (i < 8)
	{
		if (message[i] == 0)
			kill(s_id, SIGUSR1);
		else if (message[i] == 1)
			kill(s_id, SIGUSR2);
		usleep(50);
		while (g_global != 1)
			usleep(5);
		g_global = 0;
		i++;
		usleep(DELAY); //cambio
	}
	free (message);
}

unsigned char	*convert_to_binary(unsigned char nbr)
{
	unsigned char	*message;
	int				i;
	unsigned char	aux;

	aux = nbr;
	i = 7;
	message = (unsigned char *)malloc(sizeof(unsigned char) * 8);
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
	pid_t				s_id;
	unsigned char		*message;
	int					i;

	i = 0;
	if (argc != 3)
		exit(EXIT_FAILURE);
	s_id = (pid_t)ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		message = convert_to_binary((unsigned char)argv[2][i]);
		send_message(s_id, message);
		i++;
	}
	return (0);
}
