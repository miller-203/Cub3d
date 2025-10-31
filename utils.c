#include "cub3d.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	isline_empty(char *line)
{
	int	i;

	i = 0;
	if (line == NULL || ft_strlen(line) == 0)
	{
		return (1);
	}
	while (line[i] != '\0')
	{
		if (line[0] == '\n' || (line[i] == '\n' && line[i + 1] == '\n'
				&& line[i] != '\0') || (line[i] == '\n' && line[i + 1] == '\0'))
		{
			return (1);
		}
		i++;
	}
	return (0);
}