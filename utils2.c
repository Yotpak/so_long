/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:53:40 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 01:18:49 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	lencalculator(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (n <= 9)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	long	w;
	int		i;

	w = n;
	nlen = lencalculator(n);
	i = nlen;
	str = malloc(sizeof(char) * (nlen + 1));
	if (!str)
		return (NULL);
	while (nlen--)
	{
		if (w < 0)
			w = w * -1;
		str[nlen] = (w % 10) + '0';
		w = w / 10;
	}
	if (n < 0)
		str[0] = '-';
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	int		area;

	area = (nmemb * size);
	buffer = (char *)malloc(sizeof(char) * area);
	if (!buffer)
		return (NULL);
	while (--area >= 0)
		buffer[area] = '\0';
	return ((void *)buffer);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i[s] != '\0')
	{
		i[str] = i[s];
		i++;
	}
	i[str] = '\0';
	return (str);
}