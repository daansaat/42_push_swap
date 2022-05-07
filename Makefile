NAME = push_swap
SRCS_DIR = src/
SRCS_LIST = \
	actions.c \
	push_swap.c \
	sort_big.c \
	sort_small.c \
	utils_sort.c \
	print_list.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
INC = -I ./inc -I ./libft
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
