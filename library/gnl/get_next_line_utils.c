/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:36:21 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/17 13:32:50 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checknewline(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	len = -1;
	i = 0;
	while (s1[++len])
		str[len] = s1[len];
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	free (s1);
	return (str);
}

char	*new_line(char *buffer)
{
	char	*line;
	int		a;
	int		nl;

	nl = checknewline(buffer);
	a = 0;
	if (!buffer[a])
		return (NULL);
	while (buffer[a] && buffer[a] != '\n')
		a++;
	line = malloc(sizeof(char) * (a + nl + 1));
	a = 0;
	while (buffer[a] && buffer[a] != '\n')
	{
		line[a] = buffer[a];
		a++;
	}
	line[a] = '\0';
	return (line);
}

char	*new_buffer(char *buffer)
{
	char	*n_buffer;
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (buffer[a] && buffer[a] != '\n')
		a++;
	if (!buffer[a])
	{
		free (buffer);
		return (NULL);
	}
	n_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - a + 1));
	if (!n_buffer)
		return (NULL);
	a++;
	while (buffer[a])
		n_buffer[b++] = buffer[a++];
	n_buffer[b] = '\0'; 
	free (buffer);
	return (n_buffer);
}
