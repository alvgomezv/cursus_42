/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:55:55 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/17 16:53:26 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./libft/libft.h"

char	convert_to_decimal(int *message)
{
	int	i;
	int	c;
	int	b;
	
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

void handle_signal(int sig)
{
	static int	i;
	//int a = 0;
	char		ch;
	static int	message[8];

	if (sig == SIGUSR1)
	{
		message[i] = 0;
		//write(1, "cero\n", 5);
		i++;
	}
	else if (sig == SIGUSR2)
	{
		message[i] = 1;
		//write(1, "uno\n", 4);
		i++;
	}
	if (i == 8)
	{
		//while (a != 8)
		//	ft_printf("%d", message[a++]);
		ch = convert_to_decimal(message);
		write(1, &ch, 1);
		i = 0;
		usleep(500);
	}
}

int main (void)
{
	pid_t	id;
	//int mess[8] = {0,1,1,0,0,0,0,1};

	id = getpid();
	ft_printf("%d\n", (int)id);
	//ft_printf("%c\n", convert_to_decimal(mess));
	while (1)
	{
		signal (SIGUSR1, &handle_signal);
		signal (SIGUSR2, &handle_signal);
		usleep (50);
	}
	return (0);
}
