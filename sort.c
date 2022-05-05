#include "push_swap.h"
#include <unistd.h>

static void	smart_rotate(struct node **head, struct var *var)
{

}

static void	get_steps_max(struct node **head, struct var *var)
{
	struct node	*temp;

	temp = var->max;
	max_next = 0;
	while (temp->next)
	{
		temp = temp->next;
		max_next++;
	}
	temp = var->max;
	max_prev = 0;
	while (temp->prev)
	{
		temp = temp->prev;
		max_prev++;
	}
}

static void	get_steps_min(struct node **head, struct var *var)
{
	struct node	*temp;

	temp = var->min;
	min_next = 0;
	while (temp->next)
	{
		temp = temp->next;
		min_next++;
	}
	temp = var->min;
	min_prev = 0;
	while (temp->prev)
	{
		temp = temp->prev;
		min_prev++;
	}
}

static void	get_steps(struct node **head, struct var *var)
{
	struct node	*temp;
	int			next;
	int			prev;

	temp = *head;
	next = 0;
	while (temp->next)
	{
		temp = temp->next;
		next++;
	}
	temp = *head;
	prev = 0;
	while (temp->prev)
	{
		temp = temp->prev;
		prev++;
	}
	if (*head == var->max)
	{


	}
	else
	{

		
	}
}

static void	get_min_max(struct node **head_from, struct var *var)
{
	struct node	*temp;

	var->max = var->min = temp = *head_from;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->nb > var->max->nb)
			var->max = temp;
		if (temp->nb < var->min->nb)
			var->min = temp;
	}
}

void	insert_sort_back(struct node **head_from, struct node **head_to)
{
	struct var	*var;
	struct node	*temp;

	get_min_max(head_from, var);
	get_steps_min(head_from, var);
	get_steps_max(head_from, var);
	smart_rotate(head_from, var);	
	temp = max;
	next = 0;
	while (temp->next)
	{
		temp = temp->next;
		next++;
	}
	while (*head_from != max)
	{
		if (next < len / 2)
			rrab(head_from);
		else
			rab(head_from);
	}
	pab(head_from, head_to);
}
