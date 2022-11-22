NAME = ft_mini_ls
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = main.c ft_mini_ls.c ft_mini_ls_utils.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
