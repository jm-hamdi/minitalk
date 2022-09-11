/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:37:48 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/06/09 00:52:25 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i != -1)
	{
		if (1 & (c >> i))
		{
			if (kill(pid, SIGUSR1) == -1)
				write(1, "Failed to setuo signal", 23);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				write(1, "Failed to setup signal", 23);
		}
		usleep(600);
	i--;
	}
}

void	recieved(void)
{
	write(1, "signal is recieved succesfully\n", 32);
}

void	client_message(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_char(str[i], pid);
	recieved();
}

int	send(int pid, char *str)
{
	if (kill(pid, 0) == -1)
	{
		ft_putstr("Invalid PID\n");
		return (1);
	}
	else
	{
		if (pid == 0)
		{	
			ft_putstr("Invalid PID\n");
			return (1);
		}
		client_message(str, pid);
		return (0);
	}
}

void	invalid(void)
{
	write(1, "Invalide parametrs\n", 19);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*our_msg;

	if (argc != 3)
		invalid();
	pid = ft_atoi(argv[1]);
	our_msg = argv[2];
	send(pid, our_msg);
}
