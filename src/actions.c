#include "push_swap.h"
#include "stdlib.h"

void	pab(struct node **head_from, struct node **head_to)
{
	struct node	*temp;

	if (!*head_from)
		return ;
	temp = *head_to;
	*head_to = *head_from;
	if ((*head_from)->next)
	{
		*head_from = (*head_from)->next;
		(*head_from)->prev = NULL;
	}
	else
		*head_from = (*head_from)->next;
	(*head_to)->next = temp;
	if (temp)
		temp->prev = *head_to;
}

void	rab(struct node **head)
{
	struct node	*temp;

	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	(*head)->prev = temp;
	*head = (*head)->next;
	(*head)->prev = NULL;
	temp->next->next = NULL;
}

void	rrab(struct node **head)
{
	struct node	*temp;

	temp = *head;
	while (temp->next)
		temp = temp->next;
	(*head)->prev = temp;
	temp->next = *head;
	*head = temp;
	temp->prev->next = NULL;
	(*head)->prev = NULL;
}
