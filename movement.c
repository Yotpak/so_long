/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:31:04 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 03:04:37 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left(t_data *datas)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (datas->map[datas->p_l[0]][datas->p_l[1] - 1] == 'E')
	{
		if (datas->c_c == datas->coll)
			exit (1);
	}
	else if (datas->map[datas->p_l[0]][datas->p_l[1] - 1] == 'C')
	{
		datas->map[datas->p_l[0]][datas->p_l[1]] = '0';
		datas->map[datas->p_l[0]][datas->p_l[1] - 1] = 'P';
		datas->p_l[1] = datas->p_l[1] - 1;
		datas->c_c += 1;
		datas->p_step += 1;
		ft_printf("Player Step Counter : %d\n", datas->p_step);
	}
	else if (datas->map[datas->p_l[0]][datas->p_l[1] - 1] != '1')
	{
		ft_left_exit(datas);
		ft_printf("Player Step Counter : %d\n", datas->p_step);
	}
}

void	ft_right(t_data *datas)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (datas->map[datas->p_l[0]][datas->p_l[1] + 1] == 'E')
	{
		if (datas->c_c == datas->coll)
			exit (1);
	}
	else if (datas->map[datas->p_l[0]][datas->p_l[1] + 1] == 'C')
	{
		datas->map[datas->p_l[0]][datas->p_l[1]] = '0';
		datas->map[datas->p_l[0]][datas->p_l[1] + 1] = 'P';
		datas->p_l[1] = datas->p_l[1] + 1;
		datas->c_c += 1;
		datas->p_step += 1;
		ft_printf("Player Step Counter : %d\n", datas->p_step);
	}
	else if (datas->map[datas->p_l[0]][datas->p_l[1] + 1] != '1')
	{
		ft_right_exit(datas);
		ft_printf("Player Step Counter : %d\n", datas->p_step);
	}
}

void	ft_up(t_data *datas)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (datas->map[datas->p_l[0] - 1][datas->p_l[1]] == 'E')
	{
		if (datas->c_c == datas->coll)
			exit (1);
	}
	else if (datas->map[datas->p_l[0] - 1][datas->p_l[1]] == 'C')
	{
		datas->map[datas->p_l[0]][datas->p_l[1]] = '0';
		datas->map[datas->p_l[0] - 1][datas->p_l[1]] = 'P';
		datas->p_l[0] = datas->p_l[0] - 1;
		datas->c_c += 1;
		datas->p_step += 1;
		ft_printf("Player Step Counter : %d\n", datas->p_step);
	}
	else if (datas->map[datas->p_l[0] - 1][datas->p_l[1]] != '1')
	{
		ft_up_exit(datas);
		ft_printf("Player Step Counter : %d\n", datas->p_step);
	}
}

void	ft_down(t_data *datas)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (datas->map[datas->p_l[0] + 1][datas->p_l[1]] == 'E')
	{
		if (datas->c_c == datas->coll)
			exit (1);
	}
	else if (datas->map[datas->p_l[0] + 1][datas->p_l[1]] == 'C')
	{
		datas->map[datas->p_l[0]][datas->p_l[1]] = '0';
		datas->map[datas->p_l[0] + 1][datas->p_l[1]] = 'P';
		datas->p_l[0] = datas->p_l[0] + 1;
		datas->c_c += 1;
		datas->p_step += 1;
		ft_printf("Player Step Counter : %d\n", datas->p_step);
	}
	else if (datas->map[datas->p_l[0] + 1][datas->p_l[1]] != '1')
	{
		ft_down_exit(datas);
		ft_printf("Player Step Counter : %d\n", datas->p_step);
	}
}
