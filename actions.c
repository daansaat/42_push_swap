#include "push_swap.h"

void	sab(struct node *stack)
{
	int	temp;

	temp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = temp;
}

//void	pab(struct node stack_a, struct node stack_b)

// void	rab(struct node stack)

// void	rrab(struct node stack)