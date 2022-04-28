NAME = push_swap
SRCS = \
	push_swap.c \
	quick_sort.c \
	actions.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
INC = -I . -I ./libft
LIB = -L ./libft -l ft

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(FLAGS) $(INC) $(LIB) $(SRCS) -o $(NAME)

%.o: %.c
	$(CC) -c $(INC) $< -o $@

libft/libft.a:
	$(MAKE) -C ./libft bonus

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: clean fclean all
