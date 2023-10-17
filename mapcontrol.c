/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:49:11 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/17 14:39:32 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_perimetercheck(t_data *datas)
{
	int	i;
	int	j;

	i = 0;
	while (datas->map[0][i] != '\0')
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
	while (j < (datas->y - 2))
	{
		if (datas->map[j][0] != '1' && datas->map[j][(datas->x - 1)])
			ft_printerror("Perimeter Check Failure\n");
		j++;
	}
}
