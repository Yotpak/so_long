/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:40:04 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 03:00:50 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*datas;
	int		fd;

	datas = malloc(sizeof(t_data));
	if (ac == 2)
	{
		if (ft_argscontrol(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			ft_map(datas, av[1], fd);
			ft_perimetercheck(datas);
			ft_collcount(datas);
			ft_unvalidmap_checker(datas);
			ft_mlxinit(datas);
		}
		else
			ft_printerror("Second Argument Error!\n");
	}
	else
		ft_printerror("The Argument Error!\n");
}
