/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:58:01 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/16 18:55:38 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_i(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i = i + ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n = n * -1;
			i = i + ft_putchar('-');
		}
		if (n > 9)
			i = i + ft_putnbr(n / 10);
		i = i + ft_putchar(n % 10 + '0');
	}
	return (i);
}

int	ft_p(unsigned long int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_p(n / 16);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_type(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'i')
		return (ft_putnbr_i(va_arg(arg, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'u')
		return (ft_unsignedputnbr(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_hex(c, va_arg(arg, unsigned int)));
	else if (c == 'X')
		return (ft_hex(c, va_arg(arg, unsigned int)));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_p(va_arg(arg, unsigned long int)) + 2);
	}
	else 
		write(1, &c, 1);
	return (0);
}

int	ft_printf(const char *sign, ...)
{
	va_list	arg;
	int		i;
	int		j;

	va_start(arg, sign);
	i = 0;
	j = 0;
	while (sign[i])
	{
		if (sign[i] == '%')
		{
			while (sign[i + 1] == ' ')
				i++;
			if (sign[i + 1] == 'i' && sign[i] == ' ')
				j = j + write(1, " ", 1);
			j = j + ft_type(sign[i + 1], arg);
			i++;
		}
		else
			j = j + write(1, &sign[i], 1);
		i++;
	}
	va_end(arg);
	return (j);
}