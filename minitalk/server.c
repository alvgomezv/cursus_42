/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:55:55 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/19 18:27:40 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

char	convert_to_decimal(char *message)
{
	int		i;
	char	c;
	int		b;

	i = 0;
	c = 0;
	b = 128;
	while (i < 8)
	{
		c = c + (message[i] * b);
		b = b / 2;
		i++;
	}
	return (c);
}

void	handle_signal(int sig)
{
	static int		i;
	char			ch;
	static char		*message;

	if (i == 0)
	{
		message = (char *)malloc(sizeof(int) * 8);
		if (message == 0)
			exit(EXIT_FAILURE);
	}
	if (sig == SIGUSR1)
		message[i++] = 0;
	else if (sig == SIGUSR2)
		message[i++] = 1;
	else
		exit(EXIT_FAILURE);
	if (i == 8)
	{
		ch = convert_to_decimal(message);
		write(1, &ch, sizeof(ch));
		i = 0;
		free (message);
		usleep(150);
	}
}

int	main(void)
{
	pid_t				id;
	struct sigaction	sa;

	sa.sa_handler = &handle_signal;
	sa.sa_flags = SA_NODEFER | SA_RESTART;
	id = getpid();
	ft_printf("%d\n", (int)id);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
