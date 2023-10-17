/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:32:52 by tbalci            #+#    #+#             */
/*   Updated: 2023/08/11 01:55:56 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_alline(int fd, char *buffer)
{
	char	*str;
	int		byte;

	byte = 1;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (!checknewline(buffer) && byte != 0)
	{
		byte = read(fd, str, BUFFER_SIZE);
		if (byte == -1)
		{
			free (buffer);
			free (str);
			return (NULL);
		}
		str[byte] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free (str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_alline(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = new_line(buffer);
	buffer = new_buffer(buffer);
	return (line);
}
