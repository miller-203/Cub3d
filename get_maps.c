#include "cub3d.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	res = malloc((len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

static void	put_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}

static void	check_file_empty(char *file, char *line)
{
	if (file[0] == '\0')
	{
		free(file);
		free(line);
		put_error("\033[1;31m🛑ERROR\033[0m:\nMap is empty\n");
	}
}

char	*get_map(char **argv)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*file;

	file = ft_strdup("");
	line = "";
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free(file);
		put_error("\033[1;31m🛑ERROR\033[0m:\nNo such file or directory\n");
	}
	while (line)
	{
		line = get_next_line(fd);
		tmp = file;
		file = ft_strjoin(tmp, line);
		free(line);
	}
	close(fd);
	check_file_empty(file, line);
	return (file);
}