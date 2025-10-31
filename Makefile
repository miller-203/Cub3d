NAME = cub3d
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
FRAMEWORKS = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext
SRCS = get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       main.c \
       utils.c \
       ft_split.c \
       free_array.c \
       check_file.c \
	get_maps.c \
       make_game.c \

OBJS = ${SRCS:.c=.o}

.SECONDARY:

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) ${FRAMEWORKS} -o  $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re