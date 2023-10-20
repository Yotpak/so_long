/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:26:41 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 03:02:34 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_closeclose(t_data *datas)
{
	(void)datas;
	exit(0);
	return (0);
}

int	ft_close_window(int keycode, t_data *datas)
{
	char	*player_step;

	if (keycode == 0 || keycode == 123)
		ft_left(datas);
	else if (keycode == 2 || keycode == 124)
		ft_right(datas);
	else if (keycode == 13 || keycode == 126)
		ft_up(datas);
	else if (keycode == 1 || keycode == 125)
		ft_down(datas);
	mlx_clear_window(datas->mlx, datas->mlx_win);
	ft_transfertomap(datas);
	mlx_string_put(datas->mlx, datas->mlx_win, 32, 32,
		0x0000FF00, "Player Step Counter :");
	player_step = ft_itoa(datas->p_step);
	mlx_string_put(datas->mlx, datas->mlx_win, 182, 32,
		0x0000FF00, player_step);
	free(player_step);
	if (keycode == 53)
	{
		mlx_destroy_window(datas->mlx, datas->mlx_win);
		exit(0);
	}
	return (0);
}

void	ft_identification(t_data *datas)
{
	datas->p = 0;
	datas->coll = 0;
	datas->ex = 0;
	datas->c_c = 0;
	datas->p_step = 0;
	datas->valid_coll = 0;
	datas->valid_exit = 0;
}
