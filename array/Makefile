NAME = push_swap
SRCS_DIR = ./src/
SRCS_LIST = \
	push_swap.c\
	quick_sort.c\
	insert_sort.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)
FLAGS =	-Wall -Werror -Wextra
INC = -I ./inc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INC) $(SRCS) -o $(NAME)

%.o: %.c
	$(CC) -c $(INC) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all