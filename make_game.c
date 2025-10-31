#include "cub3d.h"

static void	prepare_vars(t_game *vars)
{
	(vars)->win_w = ft_strlen((vars)->map.content[0]);
	(vars)->win_h = get_height((vars)->map.content);
}

static void	init_game(t_game *vars)
{
	(vars)->mlx = mlx_init();
	if (!(vars)->mlx)
	{
		ft_error(&vars, "\033[1;31m🛑ERROR:\033[0m\nmlx is null\n");
		exit(1);
	}
	(vars)->win = mlx_new_window((vars)->mlx, (vars)->win_w * 64, (vars)->win_h
			* 64, "cub3d");
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
	while (v->map.content[x])
	{
		free(v->map.content[x]);
		x++;
	}
	free(v->map.content);
	mlx_destroy_window((v)->mlx, (v)->win);
	mlx_destroy_display((v)->mlx);
	free((v)->mlx);
	exit(1);
	return (0);
}

void load_image_to_map(char tile, int x, int y, t_game *vars)
{
	int	img_w;
	int	img_h;

	(*vars).img = mlx_xpm_file_to_image((*vars).mlx, "./textures/wall.xpm", &img_w, &img_h);
	if (!(*vars).img)
	{
		// ft_error(v, "Error: mlx_xpm_file_to_image failed");
		exit(1);
	}
	mlx_put_image_to_window((*vars).mlx, (*vars).win, (*vars).img, x, y);
	mlx_destroy_image((*vars).mlx, (*vars).img);
}

void render_map(t_game *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map.content[i])
	{
		j = 0;
		while (vars->map.content[i][j])
		{
			load_image_to_map(vars->map.content[i][j], j * 64, i * 64, vars);
			j++;
		}
		i++;
	}
}

void	make_your_game(t_game *vars)
{
	prepare_vars(vars);
	init_game(vars);
	render_map(vars);
	// mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 17, 0, close_game, vars);
	mlx_loop(vars->mlx);
}