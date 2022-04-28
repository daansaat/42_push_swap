#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static struct node	*create_dll(struct node *head, char **argv)
{
	struct node	*newnode;
	struct node	*temp;
	int			i;

	i = 1;
	while (argv[i])
	{
		newnode = malloc(sizeof(struct node));
		if (head == 0)
		{
			head = temp = newnode;
			newnode->nb = atoi(argv[i]);
			newnode->prev = NULL;
		}
		else
		{
			temp->next = newnode;
			newnode->nb = atoi(argv[i]);
			newnode->prev = temp;
			temp = newnode;
		}
		i++;
	}
	newnode->next = NULL;
	head->prev = NULL;
	return (head);
}

int	main(int argc, char **argv)
{
	struct node		*stack_a;
	struct node		*stack_b;
	//struct stacks	*stacks;
	struct node_ptr	*ptr;
	struct node		*temp;

	(void)argc;
	stack_a = NULL;
	stack_b = NULL;
	ptr = NULL;
	stack_a = create_dll(stack_a, argv);
	ptr = malloc(sizeof(struct node_ptr));
	ptr->head = stack_a;
	ptr->start = NULL;
	ptr->end= NULL;
	//quick_sort(ptr, 0, argc - 2);
	pab(&stack_b, &stack_a);
	temp = stack_a;
	while (temp)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
	}
	printf("\n");
	temp = stack_b;
	while (temp)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
	}
	return (0);
}