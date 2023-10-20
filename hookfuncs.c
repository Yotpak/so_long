#include "so_long.h"

int	ft_mousehook(t_data *datas)
{
	(void)datas;
	exit(0);
	return (0);
}

int	ft_keyboardhook(int keycode, t_data *datas)
{
	char	*player_step;

	if (keycode == 0 || keycode == 123)
		ft_left(datas);
	else if (keycode == 2 || keycode == 124)
		ft_right(datas);
	else if (keycode == 13 || keycode == 126)
		ft_up(datas);
	else if (keycode == 1 || keycode == 125)
		ft_down(datas);
	mlx_clear_window(datas->mlx, datas->mlx_win);
	ft_transfertomap(datas);
	mlx_string_put(datas->mlx, datas->mlx_win, 32, 32,
		0x0000FF00, "Player Step Counter :");
	player_step = ft_itoa(datas->p_step);
	mlx_string_put(datas->mlx, datas->mlx_win, 182, 32,
		0x0000FF00, player_step);
	free(player_step);
	if (keycode == 53)
	{
		mlx_destroy_window(datas->mlx, datas->mlx_win);
		exit(0);
	}
	return (0);
}