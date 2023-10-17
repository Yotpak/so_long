/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:48:30 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/17 14:38:29 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "./library/ft_printf/ft_printf.h"
# include "./library/gnl/get_next_line.h"
# include "./library/mlx_library/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**c_map;
	int		x;
	int		y;
	int		coll;
	int		p_step;
}			t_data;

char	*ft_strdup(const char *s);
void	ft_printerror(char *str);
void	ft_cmap(t_data *datas);
void	ft_map(t_data *datas, char *av1, int fd);
void	ft_y(t_data *datas, char *av1);
int		ft_argscontrol(char *str);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_perimetercheck(t_data *datas);
void	ft_perimetercheck(t_data *datas);


#endif