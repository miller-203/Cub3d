/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolaidi- <yolaidi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:30:43 by yolaidi-          #+#    #+#             */
/*   Updated: 2025/03/27 00:41:20 by yolaidi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*continue_cpy(char *str)
{
	int		i;
	int		k;
	char	*buf;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	buf = malloc(ft_strlen(&str[i]) + 1);
	if (!buf)
		return (free(str), NULL);
	k = 0;
	while (str[i])
		buf[k++] = str[i++];
	buf[k] = '\0';
	free(str);
	return (buf);
}

char	*get_lline(char *str)
{
	int		len_newline;
	char	*next_str;

	if (!str || !*str)
		return (NULL);
	len_newline = len_to_newline(str);
	next_str = malloc(len_newline + 1);
	if (!next_str)
		return (NULL);
	cpy_to_newline(next_str, str);
	return (next_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (free(s1), NULL);
	ft_strcpy(res, s1);
	ft_strcpy(res + len1, s2);
	free(s1);
	return (res);
}

char	*read_stock(char *str, int fd)
{
	int		char_read;
	char	*buf;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((long)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	char_read = 1;
	while (!found_newline(str) && char_read > 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[char_read] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (free(buf), NULL);
	}
	return (free(buf), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (fd >= 0)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	str = read_stock(str, fd);
	if (!str)
		return (NULL);
	line = get_lline(str);
	str = continue_cpy(str);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d->%s", lines++, line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
