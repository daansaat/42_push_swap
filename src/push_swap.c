#include "push_swap.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	check(void *ptr)
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
		check(newnode = malloc(sizeof(struct node)));
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
	(*head)->prev = NULL;
}

int	main(int argc, char **argv)
{
	struct node		*head_a;
	struct node		*head_b;
	struct var		*var;

	head_a = NULL;
	head_b = NULL;
	create_dll(&head_a, argv);
	check(var = malloc(sizeof(struct var)));
	big_sort(argc, argv, &head_a, &head_b, var);
	print_list(head_a, head_b);
	return (0);
}