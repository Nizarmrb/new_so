NAME = so_long

CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c so_long.c ft_split.c map.c utils.c buttons.c the_checker.c

OBJ = ${SRC:.c=.o}

all : $(NAME)


$(NAME): $(OBJ)
		cc $(OBJ) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
