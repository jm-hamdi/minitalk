/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 03:25:41 by jm-hamdi          #+#    #+#             */
/*   Updated: 2021/12/12 04:06:41 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_print_nbr(int nb);
int	ft_print_char(char c);
int	ft_checker(char c, va_list *ptr);
int	ft_printf(const char *format, ...);
int	print_adr(unsigned long int nb);
int	print_unb(unsigned int nb);
int	print_hex(unsigned int nb, int s);
int	print_str(char	*str);
#endif
