#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*img;
	void	*win;
	int		win_w;
	int		win_h;
	char	**map;
}			t_game;

void		check_file_is_valid(char *file_line);
char		**ft_split(char const *s, char c);
void		free_double_pointer(char **str);
void		ft_error(t_game **v, char *err);
int			isline_empty(char *line);
int			get_height(char **map);
char		*get_map(char **argv);
void		make_your_game(t_game *vars);

#endif