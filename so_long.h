/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:48:30 by tbalci            #+#    #+#             */
/*   Updated: 2023/10/20 02:18:19 by tbalci           ###   ########.fr       */
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
	void	**img;
	char	**map;
	char	**v_map;
	int		x;
	int		y;
	int		coll;
	int		c_c;
	int		p;
	int		ex;
	int		valid_coll;
	int		valid_exit;
	int		p_step;
	int		*p_l;
}			t_data;

void	ft_printerror(char *str);
void	ft_mapinsidecontrol(t_data *datas);
void	ft_cmap(t_data *datas);
void	ft_map(t_data *datas, char *av1, int fd);
void	ft_y(t_data *datas, char *av1);
void	ft_perimetercheck(t_data *datas);
void	ft_perimetercheck(t_data *datas);
void	ft_mapdatascontrol(t_data *datas);
void	ft_collcount(t_data *datas);
void	ft_opencontrol(int fd);
void	ft_mlxinit(t_data *datas);
void	ft_imtomlx(t_data *datas);
void	ft_left(t_data *datas);
void	ft_right(t_data *datas);
void	ft_up(t_data *datas);
void	ft_unvalidmap_checker(t_data *datas);
void	ft_identification(t_data *datas);
void	ft_down(t_data *datas);
void	ft_transfertomap(t_data *datas);
void	ft_left_exit(t_data *datas);
void	ft_right_exit(t_data *datas);
void	ft_up_exit(t_data *datas);
void	ft_down_exit(t_data *datas);
void	ft_unvalid_map(t_data *data, int x, int y);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		ft_argscontrol(char *str);
int		ft_keyboardhook(int keycode, t_data *datas);
int	ft_mousehook(t_data *datas);

#endif