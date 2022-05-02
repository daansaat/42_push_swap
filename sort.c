#include "push_swap.h"

void	insert_back_sort(struct node **head_from, struct node **head_to)
{
	struct node	*biggest;
	struct node	*temp;
	int			next;
	int			prev;

	if (!*head_from)
		return ;
	biggest = *head_from;
	temp = *head_from;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->nb > biggest->nb)
			biggest = temp;
	}
	temp = biggest;
	next = 0;
	while (temp->next)
	{
		temp = temp->next;
		next++;
	}
	temp = biggest;
	prev = 0;
	while (temp->prev)
	{
		temp = temp->prev;
		prev++;
	}
	while (*head_from != biggest)
	{
		if (next > prev)
			rrab(head_from);
		if (prev > next)
			rab(head_from);
	}
	pab(head_from, head_to);
}
