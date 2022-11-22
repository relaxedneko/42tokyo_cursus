NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c\
	ft_printf_utils.c\
	catch_formats.c\
	cases_d_x.c\
	cases_p.c\
	cases_s_c.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $^

$(OBJS): %.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean all
