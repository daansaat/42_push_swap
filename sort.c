#include "push_swap.h"
#include <unistd.h>

void	insert_sort_back(struct node **head_from, struct node **head_to)
{
	struct node	*biggest;
	struct node	*temp;
	int			next;
	int			len;

	if (!*head_from)
		return ;
	biggest = *head_from;
	temp = *head_from;
	len = 0;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->nb > biggest->nb)
			biggest = temp;
		len++;
	}
	temp = biggest;
	next = 0;
	while (temp->next)
	{
		temp = temp->next;
		next++;
	}
	while (*head_from != biggest)
	{
		if (next < len / 2)
			rrab(head_from);
		else
			rab(head_from);
	}
	pab(head_from, head_to);
}
