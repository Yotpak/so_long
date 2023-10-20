#include "so_long.h"

void	ft_perimetercheck(t_data *datas)
{
	int	i;
	int	j;

	i = 0;
	while (datas->map[0][i])
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
	while (j <= (datas->y - 2))
	{
		if (datas->map[j][0] != '1' || datas->map[j][(datas->x - 1)] != '1')
			ft_printerror("Perimeter Check Failure!\n");
		j++;
	}
}

int	ft_argscontrol(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	i = i - 1;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.')
		return (1);
	return (0);
}

void	ft_mapdatascontrol(t_data *datas)
{
	if (datas->p == 0 || datas->p > 1)
		ft_printerror("Player Count Error\n");
	if (datas->ex == 0 || datas->ex > 1)
		ft_printerror("Exit Count Error\n");
	if (datas->coll == 0)
		ft_printerror("Nothing to collect on the map!\n");
}

void	ft_mapinsidecontrol(t_data *datas)
{
	int	i;
	int	j;

	i = 1;
	while (i < (datas->y - 1))
	{
		j = 1;
		while (j < (datas->x - 1))
		{
			if (datas->map[i][j] == '1' || datas->map[i][j] == '0' ||
				datas->map[i][j] == 'P' || datas->map[i][j] == 'E' ||
				datas->map[i][j] == 'C')
			{
				j++;
			}
			else
				ft_printerror("Inside Map Checker Failed\n");
		}
		i++;
	}
}

void	ft_opencontrol(int fd)
{
	if (fd == -1)
	{
		printf("Open Function Failure!\n");
		exit (1);
	}
}
