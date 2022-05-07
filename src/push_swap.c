#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	check_malloc(void *ptr)
{
	if (ptr == NULL)
		exit(EXIT_FAILURE);
}

static void	create_dll(struct node **head, char **argv)
{
	struct node	*newnode;
	struct node	*temp;
	int			i;

	i = 1;
	while (argv[i])
	{
		check_is_integer(argv[i]);
		check_malloc(newnode = malloc(sizeof(struct node)));
		if (*head == 0)
		{
			*head = temp = newnode;
			newnode->nb = ft_atoi(argv[i]);
			newnode->prev = NULL;
		}
		else
		{
			temp->next = newnode;
			newnode->nb = ft_atoi(argv[i]);
			newnode->prev = temp;
			temp = newnode;
		}
		i++;
	}
	newnode->next = NULL;
}

int	main(int argc, char **argv)
{
	struct node		*head_a;
	struct node		*head_b;
	struct var		*var;

	head_a = NULL;
	head_b = NULL;
	if (argc <= 2)
		exit (EXIT_FAILURE);
	check_is_number(argv);
	create_dll(&head_a, argv);
	check_is_sorted(head_a);
	check_is_double(head_a);
	if (argc >= 5)
		check_malloc(var = malloc(sizeof(struct var)));
	if (argc == 3)
		sort_2(&head_a);
	else if (argc == 4)
		sort_3(&head_a);
	else if (argc == 5 || argc == 6)
		sort_4_5(&head_a, &head_b, var, argc);
	else
		sort_big(argc, argv, &head_a, &head_b, var);
	print_list(head_a, head_b);
	return (0);
}