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
	// struct node		*stack_a;
	// struct node		*stack_b;
	//struct stacks	*stacks;
	struct node_ptr	*ptr;
	struct node		*temp;

	(void)argc;
	ptr = NULL;
	ptr = malloc(sizeof(struct node_ptr));
	ptr->stack_a = NULL;
	ptr->stack_b = NULL;
	ptr->stack_a = create_dll(ptr->stack_a, argv);
	//stack_b = create_dll(stack_b, argv);
	ptr->head = ptr->stack_a;
	ptr->start = NULL;
	ptr->end= NULL;
	//quick_sort(ptr, 0, argc - 2);
	//pab(&stack_b, &stack_a);
	pab(ptr);
	temp = ptr->stack_a;
	while (temp)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
	}
	printf("\n");
	temp = ptr->stack_b;
	while (temp)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
	}
	return (0);
}