#include "cub3d.h"

static void	prepare_vars(t_game *vars)
{
	(vars)->win_w = ft_strlen((vars)->map[0]);
	(vars)->win_h = get_height((vars)->map);
}

static void	init_game(t_game *vars)
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

int	close_game(t_game *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_destroy_window((v)->mlx, (v)->win);
	mlx_destroy_display((v)->mlx);
	free((v)->mlx);
	exit(1);
	return (0);
}

void	make_your_game(t_game *vars)
{
	prepare_vars(vars);
	init_game(vars);
	// mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 17, 0, close_game, vars);
	mlx_loop(vars->mlx);
}