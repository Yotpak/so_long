/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itomlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:04:34 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 02:58:20 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_imtomlx(t_data *datas) // free isteyebilir.
{
	int	v;

	v = 64;
	datas->img = ft_calloc(sizeof(void *), 5); 
	datas->img[0] = mlx_xpm_file_to_image(datas->mlx,
			"./img/exit2.xpm", &v, &v);
	datas->img[1] = mlx_xpm_file_to_image(datas->mlx,
			"./img/expo.xpm", &v, &v);
	datas->img[2] = mlx_xpm_file_to_image(datas->mlx,
			"./img/fall.XPM", &v, &v);
	datas->img[3] = mlx_xpm_file_to_image(datas->mlx,
			"./img/wall.XPM", &v, &v);
	datas->img[4] = mlx_xpm_file_to_image(datas->mlx,
			"./img/megumin.xpm", &v, &v);
}

void	ft_img(t_data *datas, int i, int j, int w)
{
	mlx_put_image_to_window(datas->mlx, datas->mlx_win,
		datas->img[w], j * 64, i * 64);
}

void	ft_transfertomap(t_data *datas)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < datas->x)
	{
		i = 0;
		while (i < datas->y)
		{
			if (datas->map[i][j] == '0')
				ft_img(datas, i, j, 2);
			else if (datas->map[i][j] == '1')
				ft_img(datas, i, j, 3);
			else if (datas->map[i][j] == 'P')
				ft_img(datas, i, j, 4);
			else if (datas->map[i][j] == 'E')
				ft_img(datas, i, j, 0);
			else if (datas->map[i][j] == 'C')
				ft_img(datas, i, j, 1);
			i++;
		}
		j++;
	}
}

