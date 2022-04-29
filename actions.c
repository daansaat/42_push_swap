#include "push_swap.h"
#include <stdio.h>

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

// void	pab(struct node **head_to, struct node **head_from)
// {
// 	struct node	*temp;
	
// 	//(void) head_to;

// 	//**head_from = *(*head_from)->next;
	
// 	// if (!head_from)
// 	// 	return;
// 	//temp = *head_to;
// 	**head_to = *(*head_from);
// 	**head_from = *(*head_from)->next;
// 	*(*head_to)->next = NULL;
// }

void	pab(struct node_ptr *ptr)
{
	struct node	*temp;

	if (!)
	temp = ptr->stack_b;
	ptr->stack_b = ptr->stack_a;
	ptr->stack_a = ptr->stack_a->next;
	ptr->stack_b->next = temp;
}

// void	rab(struct node stack)

// void	rrab(struct node stack)