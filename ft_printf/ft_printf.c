/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 03:24:52 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/06/08 22:15:36 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_checker(char c, va_list *ptr)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(*ptr, int));
	if (c == '%')
		len += write(1, "%", 1);
	if (c == 'd' || c == 'i')
		len += ft_print_nbr(va_arg(*ptr, int));
	if (c == 'u')
		len += print_unb(va_arg(*ptr, unsigned int));
	if (c == 'x')
		len += print_hex(va_arg(*ptr, unsigned int), 1);
	if (c == 'X')
		len += print_hex(va_arg(*ptr, unsigned int), 2);
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += print_adr(va_arg(*ptr, unsigned long int));
	}
	if (c == 's')
		len += print_str(va_arg(*ptr, char *));
	else if (c == '%')
		len += ft_print_char(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ptr;

	len = 0;
	i = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		if (format[i] == '%')
		{
			len += ft_checker(format[i + 1], &ptr);
			i++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
