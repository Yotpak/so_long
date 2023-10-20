/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:49:11 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 02:59:02 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_perimetercheck(t_data *datas)
{
	int	i;
	int	j;

	i = 0;
	while (datas->map[0][i])
	{
		if (datas->map[0][i] != '1')
			ft_printerror("Perimeter Check Failure!\n");
		i++;
	}
	i = 0;
	while (datas->map[datas->y - 1][i])
	{
		if (datas->map[datas->y - 1][i] != '1')
			ft_printerror("Perimeter Check Failure!\n");
		i++;
	}
	j = 1;
	while (j <= (datas->y - 2))
	{
		if (datas->map[j][0] != '1' || datas->map[j][(datas->x - 1)] != '1')
			ft_printerror("Perimeter Check Failure!\n");
		j++;
	}
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
				datas->p_l[0] = i;
				datas->p_l[1] = j;
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
