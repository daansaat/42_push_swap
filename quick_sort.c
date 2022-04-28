#include "push_swap.h"
#include <stdio.h>

static void	swap(struct node *x, struct node *y)
{
	int	temp;

	temp = x->nb;
	x->nb = y->nb;
	y->nb = temp;
}

static int	partition(struct node_ptr *ptr, int start, int end)
{
	struct node *temp;
	int			pivot;

	pivot = ptr->start->nb;
	temp = ptr->start;
	while (start < end)
	{
		while (ptr->start->next && ptr->start->nb <= pivot)
		{
			ptr->start = ptr->start->next;
			start++;
		}
		while (ptr->end->prev && ptr->end->nb > pivot)
		{
			ptr->end = ptr->end->prev;
			end--;
		}
		if (start < end)
			swap(ptr->start, ptr->end);
	}
	swap(temp, ptr->end);
	return (end);
}

void	quick_sort(struct node_ptr *ptr, int lb, int ub)
{
	int 		loc;
	int			i;
	
	ptr->start = ptr->head;
	ptr->end = ptr->head;
	i = 0;
	while (i < lb)
	{
		ptr->start = ptr->start->next;
		i++;
	}
	i = 0;
	while (i < ub)
	{
		ptr->end = ptr->end->next;
		i++;
	}
	if (lb < ub)
	{
		loc = partition(ptr, lb, ub);
		quick_sort(ptr, lb, loc - 1);
		quick_sort(ptr, loc + 1, ub);
	}
}