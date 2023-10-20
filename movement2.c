/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 01:19:19 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 03:00:03 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left_exit(t_data *datas)
{
	datas->map[datas->p_l[0]][datas->p_l[1]] = '0';
	datas->map[datas->p_l[0]][datas->p_l[1] - 1] = 'P';
	datas->p_l[1] = datas->p_l[1] - 1;
	datas->p_step += 1;
}

void	ft_right_exit(t_data *datas)
{
	datas->map[datas->p_l[0]][datas->p_l[1]] = '0';
	datas->map[datas->p_l[0]][datas->p_l[1] + 1] = 'P';
	datas->p_l[1] = datas->p_l[1] + 1;
	datas->p_step += 1;
}

void	ft_up_exit(t_data *datas)
{
	datas->map[datas->p_l[0]][datas->p_l[1]] = '0';
	datas->map[datas->p_l[0] - 1][datas->p_l[1]] = 'P';
	datas->p_l[0] = datas->p_l[0] - 1;
	datas->p_step += 1;
}

void	ft_down_exit(t_data *datas)
{
	datas->map[datas->p_l[0]][datas->p_l[1]] = '0';
	datas->map[datas->p_l[0] + 1][datas->p_l[1]] = 'P';
	datas->p_l[0] = datas->p_l[0] + 1;
	datas->p_step += 1;
}
