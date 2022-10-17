/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:34:37 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/17 17:08:05 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./libft/libft.h"

void	send_message(pid_t s_id, int *message)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (message[i] == 0)
			kill(s_id, SIGUSR1);
		else if (message[i] == 1)
			kill(s_id, SIGUSR2);
		else	
			exit(EXIT_FAILURE);
	i++;
	usleep(500);
	}
	free (message);
}

int	*convert_to_binary(int nbr)
{
	int	*message;
	int	i;
	int	aux;

	//ft_printf("%d\n", nbr);
	aux = nbr;
	i = 7;
	message = (int *)malloc(sizeof(int) * 8);
	if (message == 0)
		exit(EXIT_FAILURE); 
	while (nbr > 0)
	{
		message[i] = (nbr % 2);
		nbr = nbr / 2;
		i--;
	}
	while (i > 0)
	{
		message[i] = 0;
		i--;
	}
	//while (i != 8)
		//ft_printf("%d", message[i++]);
	return (message);
}

int main (int argc, char **argv)
{
	pid_t	s_id;
	int		*message;
	int		i;
	
	i = 0;
	if (argc != 3)
		exit(EXIT_FAILURE);
	s_id = (pid_t)ft_atoi(argv[1]);
	//ft_printf("%d\n%s\n", s_id, argv[2]);
	while (argv[2][i] != '\0')
	{
		message = convert_to_binary((int)argv[2][i]);
		send_message(s_id, message);
		i++;
	}
	
	/*while (argv[2][i] != '\0')
	{
		if (argv[2][i] == '0')
			kill(s_id, SIGUSR1);
		else
			kill(s_id, SIGUSR2);
	i++;
	}*/
	return (0);
}