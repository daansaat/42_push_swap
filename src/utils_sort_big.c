#include "push_swap.h"

void    get_next_from_top_bottom(int ub, int lb, struct node **head, struct var *var)
{
	struct node	*temp;
	
	temp = *head;
	if (temp->nb < ub && temp->nb >= lb)
		var->max = temp;
	while (temp->next)
	{
		temp = temp->next;
		if (!var->max)
			if (temp->nb < ub && temp->nb >= lb)
				var->max = temp;
	}
	if (temp->nb < ub && temp->nb >= lb)
		var->min = temp;
	while (temp->prev)
	{
		temp = temp->prev;
		if (!var->min)
			if (temp->nb < ub && temp->nb >= lb)
				var->min = temp;
	}
}

void	get_min_max_num(struct node **head, struct var *var)
{
	struct node	*temp;

	var->max = var->min = temp = *head;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->nb > var->max->nb)
			var->max = temp;
		if (temp->nb < var->min->nb)
			var->min = temp;
	}
}

void	get_steps(struct node *node, struct steps *steps)
{
	struct node	*temp;

	temp = node;
	steps->next = 0;
	while (temp->next)
	{
		temp = temp->next;
		steps->next++;
	}
	temp = node;
	steps->prev = 0;
	while (temp->prev)
	{
		temp = temp->prev;
		steps->prev++;
	}
}

void	smart_rotate(struct node **head, struct var *var)
{
	if (var->steps_min.next <= var->steps_min.prev && var->steps_min.next <= var->steps_max.next && \
		var->steps_min.next <= var->steps_max.prev)
		while (*head != var->min)
			rrab(head);
	else if (var->steps_min.prev <= var->steps_min.next && var->steps_min.prev <= var->steps_max.next && \
		var->steps_min.prev <= var->steps_max.prev)
		while (*head != var->min)
			rab(head);
	else if (var->steps_max.next <= var->steps_max.prev && var->steps_max.next <= var->steps_min.next && \
		var->steps_max.next <= var->steps_min.prev)
		while (*head != var->max)
			rrab(head);
	else
		while (*head != var->max)
			rab(head);
}

void	smart_rotate_saved_min(struct node **head, struct var *var)
{
	while (*head != var->saved_min)
	{
		if (var->steps_min.next <= var->steps_min.prev)
			rrab(head);
		else
			rab(head);
	}
}
