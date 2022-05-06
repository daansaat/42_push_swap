#include "push_swap.h"
#include <stdio.h>

void	print_list(struct node *head_a, struct node *head_b)
{
	struct node		*temp;
	
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
}