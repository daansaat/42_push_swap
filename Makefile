NAME = push_swap
SRCS = \
	push_swap.c \
	quick_sort.c 
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
INC = -I .

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INC) $(SRCS) -o $(NAME)

%.o: %.c
	$(CC) -c $(INC) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean fclean all
