#include "cub3d.h"

static int	find(char *str, char *to_find)
{
	int	len1;
	int	len2;

	if (!str || !to_find)
		return (0);
	len1 = ft_strlen(str);
	len2 = ft_strlen(to_find);
	while (len2 >= 0 && len1 >= 0)
	{
		if (to_find[len2] != str[len1])
			return (0);
		len1--;
		len2--;
	}
	return (1);
}

void	check_file_is_valid(char *file_line)
{
	int		i;
	char	**file_name;

	file_name = ft_split(file_line, '/');
	if (file_name == NULL)
	{
		write(2, "\033[1;31m🛑ERROR\033[0m: \n", 24);
		exit(1);
	}
	i = 0;
	while (file_name[i])
		i++;
	i--;
	if (find(file_name[i], ".cub") == 1 && ft_strlen(file_name[i]) > 4)
	{
		free_double_pointer(file_name);
		return ;
	}
	free_double_pointer(file_name);
	write(2, "\033[1;31m🛑ERROR\033[0m: \nFormat File\n", 36);
	exit(1);
}