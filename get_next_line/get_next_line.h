/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolaidi- <yolaidi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:34:07 by yolaidi-          #+#    #+#             */
/*   Updated: 2025/04/02 16:07:58 by yolaidi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# if BUFFER_SIZE <= 0
#  error "BUFFER_SIZE must be greater than 0"
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_stock(char *str, int fd);
int		found_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_lline(char *str);
int		len_to_newline(char *str);
char	*cpy_to_newline(char *dest, char *src);
char	*continue_cpy(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);

#endif
