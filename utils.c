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

void	ft_findplayer(t_data *datas, int x, int y)
{
	datas->p_l = malloc(sizeof(int) * 2);
	datas->p_l[0] = y;
	datas->p_l[1] = x;
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

void	ft_collcount(t_data *datas)
{
	int	j;
	int	i;

	i = 1;
	ft_identification(datas);
	while (i < (datas->y - 1))
	{
		j = 0;
		while (datas->map[i][j])
		{
			if (datas->map[i][j] == 'P')
			{
				datas->p += 1;
				ft_findplayer(datas, j, i);
			}
			else if (datas->map[i][j] == 'C')
				datas->coll += 1;
			else if (datas->map[i][j] == 'E')
				datas->ex += 1;
			j++;
		}
		i++;
	}
	ft_mapdatascontrol(datas);
}