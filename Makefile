NAME = libftprintf.a
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = ft_printf.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) $(LIBFT_PATH) all
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc -c -Wall -Werror -Wextra -I. $< -o $@

clean:
	$(MAKE) $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) $(LIBFT_PATH) clean
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re