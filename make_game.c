#include "cub3d.h"

static void	prepare_vars(t_vars *vars)
{
	(vars)->win_w = ft_strlen((vars)->map[0]);
	(vars)->win_h = get_height((vars)->map);
}

static void	init_game(t_vars *vars)
{
	(vars)->mlx = mlx_init();
	if (!(vars)->mlx)
	{
		ft_error(&vars, "\033[1;31m🛑ERROR:\033[0m\nmlx is null\n");
		exit(1);
	}
	(vars)->win = mlx_new_window((vars)->mlx, (vars)->win_w * 32, (vars)->win_h
			* 32, "cub3d");
	if (!(vars)->win)
	{
		ft_error(&vars, "\033[1;31m🛑ERROR:\033[0m\nwin is null\n");
		exit(1);
	}
}

void	make_your_game(t_vars *vars)
{
	prepare_vars(vars);
	init_game(vars);
	mlx_loop(vars->mlx);
}