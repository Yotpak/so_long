/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 01:45:07 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 03:12:59 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_unvalid_map(t_data *datas, int x, int y)
{
	int		i;

	i = 0;
	if (datas->v_map[y][x] == 'E')
	{
		datas->valid_exit = 1;
		datas->v_map[y][x] = '1';
	}
	if (datas->v_map[y][x] == 'C')
	{
		datas->valid_coll++;
		datas->v_map[y][x] = '0';
	}
	if (datas->v_map[y][x] == '0' || datas->v_map[y][x] == 'P')
	{
		datas->v_map[y][x] = '.';
		ft_unvalid_map(datas, x, y + 1);
		ft_unvalid_map(datas, x, y - 1);
		ft_unvalid_map(datas, x + 1, y);
		ft_unvalid_map(datas, x - 1, y);
	}
	return ;
}

void	ft_unvalidmap_checker(t_data *datas)
{
	ft_unvalid_map(datas, datas->p_l[1], datas->p_l[0]);
	if (datas->valid_coll != datas->coll)
		ft_printerror("The character cannot reach the coin\n");
	if (datas->valid_exit != 1)
		ft_printerror("Character cannot reach the exit\n");
}
