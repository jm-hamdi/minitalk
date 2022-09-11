/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:37:35 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/06/09 00:00:28 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H 

# include <unistd.h>
# include <sys/signal.h>
# include <signal.h>
# include <stdlib.h>

void	send_char(char c, int pid);
int		ft_atoi(const char *str);
void	client_message(char *str, int pid);
void	sig_h(int signum);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
#endif