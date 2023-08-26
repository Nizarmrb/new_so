NAME = so_long

SRC = get_next_line.c get_next_line_utils.c so_long.c ft_split.c map.c tools.c key_codes.c map_checker.c

CFLAGS = -Wall -Wextra -Werror -Imlx

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all : $(NAME)


$(NAME): $(OBJ)
		$(CC) $(OBJ) -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
				cc $(CFLAGS) $^ -o $(NAME_BONUS)

clean : 
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all
