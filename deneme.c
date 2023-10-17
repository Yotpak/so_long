#include "so_long.h"

int	ft_close_window(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	return(0);
}

int main()
{
	t_data	*img;

	img = malloc(sizeof(t_data));
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 1920, 1080, "tk");
	mlx_key_hook(img->mlx_win, ft_close_window, img);
	mlx_loop(img->mlx);
}
