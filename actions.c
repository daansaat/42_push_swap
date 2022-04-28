#include "push_swap.h"

void	sab(struct node *stack)
{
	int	temp;

	if (stack->next)
	{
		temp = stack->nb;
		stack->nb = stack->next->nb;
		stack->next->nb = temp;
	}
}

void	pab(struct node **head_to, struct node **head_from)
{
	struct node	*temp;
	
	if (!head_from)
		return;
	temp = *head_to;
	head_to = head_from;
	head_from = &(*head_from)->next;
	(*head_to)->next = temp;
}

// void	rab(struct node stack)

// void	rrab(struct node stack)