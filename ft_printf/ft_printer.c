/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:42:04 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/01/03 18:44:28 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += ft_print_nbr(n / 10);
		len += ft_print_nbr(n % 10);
	}
	if (n < 10)
		len += ft_print_char(n + 48);
	return (len);
}

int	print_adr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_adr(nb / 16);
		len += print_adr(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_print_char(nb + 48);
		else
			len += ft_print_char(nb + 87);
	}
	return (len);
}

int	print_unb(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += print_unb(nb / 10);
		len += print_unb(nb % 10);
	}
	if (nb < 10)
		len += ft_print_char(nb + 48);
	return (len);
}

int	print_hex(unsigned int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_hex(nb / 16, s);
		len += print_hex(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_print_char(nb + 48);
		else
		{
			if (s == 1)
				len += ft_print_char(nb + 87);
			else
				len += ft_print_char(nb + 55);
		}
	}
	return (len);
}

int	print_str(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}
