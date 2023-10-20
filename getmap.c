/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:46:55 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 02:51:30 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_y(t_data *datas, char *av1)
{
	char	*str;
	int		fd;
	int		y;

	y = 0;
	fd = open(av1, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		y++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	datas->y = y;
}

void	ft_map(t_data *datas, char *av1, int fd)
{
	int		i;

	i = 0;
	ft_y(datas, av1);
	ft_opencontrol(fd);
	datas->map = malloc(sizeof(char *) * datas->y + 1);
	datas->map[i] = get_next_line(fd);
	while (datas->map[i])
	{
		i++;
		datas->map[i] = get_next_line(fd);
	}
	i = 0;
	datas->x = ft_strlen(datas->map[i]);
	while (datas->map[i])
	{
		if (datas->x != ft_strlen(datas->map[i]))
			ft_printerror("X lenght error!");
		i++;
	}
	ft_cmap(datas);
	close(fd);
}

void	ft_cmap(t_data *datas)
{
	int	i;

	i = 0;
	datas->v_map = malloc(sizeof(char *) * (datas->y + 1));
	while (i < datas->y)
	{
		datas->v_map[i] = ft_strdup(datas->map[i]);
		i++;
	}
	datas->v_map[i] = NULL;
}
