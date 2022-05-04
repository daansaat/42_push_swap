#include "push_swap.h"
#include <stdio.h>

void	sab(struct node *head)
{
	int	temp;

	if (!head || !head->next)
		return ;
	temp = head->nb;
	head->nb = head->next->nb;
	head->next->nb = temp;
}

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
	//temp->prev = NULL;
	//(*head_to)->prev = NULL;
}

void	rab(struct node **head)
{
	struct node	*tail;
	struct node	*temp;

	// if (!*head || !(*head)->next)
	// 	return ;
	tail = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = tail;
	tail->prev = temp;
	tail->next = NULL;
}

void	rrab(struct node **head)
{
	struct node	*temp;

	// if (!*head || !(*head)->next)
	// 	return ;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	*head = temp;
	temp = temp->prev;
	temp->next = NULL;
	(*head)->prev = NULL;
}
