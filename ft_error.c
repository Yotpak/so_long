/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:40:40 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/17 11:37:37 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printerror(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	exit (1);
}

int	ft_argscontrol(char *str) //.ber
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	i = i - 1;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b' && str[i - 3] == '.')
		return (1);
	return (0);
}