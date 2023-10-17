/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:12:53 by tbalci            #+#    #+#             */
/*   Updated: 2023/08/02 22:48:50 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i = i + write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
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

int	ft_unsignedputnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i = i + ft_putnbr(n / 10);
	i = i + ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_hex(char c, unsigned int w)
{
	int			i;

	i = 0;
	if (w == 0)
		return (ft_putchar('0'));
	if (w >= 16)
		i = i + ft_hex(c, w / 16);
	if (c == 'x')
		i = i + ft_putchar("0123456789abcdef"[w % 16]);
	if (c == 'X')
		i = i + ft_putchar("0123456789ABCDEF"[w % 16]);
	return (i);
}
