#include "cub3d.h"

void	free_double_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_error(t_game **v, char *err)
{
	int	i;

	i = 0;
	while ((*v)->map.content[i])
	{
		free((*v)->map.content[i]);
		i++;
	}
	free((*v)->map.content);
	if ((*v)->mlx)
	{
		if ((*v)->win)
		{
			mlx_destroy_window((*v)->mlx, (*v)->win);
		}
		mlx_destroy_display((*v)->mlx);
		free((*v)->mlx);
	}
	write(2, err, ft_strlen(err));
	exit(1);
}