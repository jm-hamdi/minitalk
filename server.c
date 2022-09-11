/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:37:17 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/06/08 20:45:08 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	g_pid;

void	res1(char *c, int *j)
{
	*j = 0;
	*c = 0;
}

void	res2(int pid)
{
	g_pid = pid;
}

void	sig_handler(int signum, siginfo_t *sig_info, void *b)
{
	static char	shift;
	static int	j;

	b = NULL;
	if (g_pid != sig_info->si_pid)
	{
		res1(&shift, &j);
		res2(sig_info->si_pid);
	}
	if (signum == SIGUSR1)
	{
		shift = (shift << 1) | 1;
		j++;
	}
	if (signum == SIGUSR2)
	{
		shift = (shift << 1);
		j++;
	}	
	if (j >= 8)
	{
		ft_putchar(shift);
		res1(&shift, &j);
	}	
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	pid = getpid();
	write(1, "SERVER PID : ", 14);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
