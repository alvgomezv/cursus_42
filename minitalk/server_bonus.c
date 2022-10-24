/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:55:55 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/20 11:06:13 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

unsigned char	convert_to_decimal(unsigned char *message)
{
	int				i;
	unsigned char	c;
	unsigned char	b;

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

void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	static int				i;
	unsigned char			ch;
	static unsigned char	message[8]; // cambio, posiblemente el decisivo

	if (sig == SIGUSR1)
		message[i++] = 0;
	else if (sig == SIGUSR2)
		message[i++] = 1;
	else
		exit(EXIT_FAILURE);
	//usleep(50);
	if (i == 8)
	{
		ch = convert_to_decimal(message);
		write(1, &ch, sizeof(ch));
		i = 0;
		//free (message);
		//usleep(50);
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				id;
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO; //| SA_NODEFER | SA_RESTART; cambio
	id = getpid();
	ft_printf("%d\n", (int)id);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
