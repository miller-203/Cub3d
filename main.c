#include "cub3d.h"

static void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->img = NULL;
	vars->win = NULL;
	vars->map = NULL;
}

static void	start_project(char **argv)
{
	char	*map;
	t_vars	vars;

	init_vars(&vars);
	check_file_is_valid(argv[1]);
	map = get_map(argv);
	if (map != NULL)
	{
		if (isline_empty(map))
		{
			free(map);
			write(2, "\033[1;31m🛑ERROR:\033[0m\nline is empty in map\n", 44);
			exit(1);
		}
		vars.map = ft_split(map, '\n');
		free(map);
		make_your_game(&vars);
	}
	free(map);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "\033[1;31m🛑ERROR:\033[0m\nInvalid number argument\n", 46);
		return (1);
	}
	start_project(argv);
	return (0);
}