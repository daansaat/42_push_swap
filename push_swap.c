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
	struct node		*head_a;
	struct node		*head_b;
	struct node		*temp;
	
	(void) argc;
	head_a = NULL;
	head_b = NULL;
	head_a = create_dll(head_a, argv);
	while (head_a)
		insert_back_sort(&head_a, &head_b);
	//insert_back_sort(&head_b, &head_a);
	// insert_back_sort(&head_a, &head_b);
	// insert_back_sort(&head_a, &head_b);
	// insert_back_sort(&head_a, &head_b);
	// insert_back_sort(&head_a, &head_b);
	temp = head_a;
	while (temp)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
	}
	printf("\n");
	temp = head_b;
	while (temp)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
	}
	printf("\n");
	return (0);
}