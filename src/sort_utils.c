/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 12:02:06 by dsaat         #+#    #+#                 */
/*   Updated: 2022/05/10 15:20:15 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_next_from_top_bottom(int ub, int lb, t_node **head, t_var *var)
{
	t_node	*temp;

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
	while (temp)
	{
		if (!var->min)
			if (temp->nb < ub && temp->nb >= lb)
				var->min = temp;
		temp = temp->prev;
	}
}

void	get_min_max_num(t_node **head, t_var *var)
{
	t_node	*temp;

	var->max = *head;
	var->min = *head;
	temp = *head;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->nb > var->max->nb)
			var->max = temp;
		if (temp->nb < var->min->nb)
			var->min = temp;
	}
}

void	get_steps(t_node *node, t_steps *steps)
{
	t_node	*temp;

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

void	smart_rotate(t_node **head, t_var *var, char stack)
{
	if (var->steps_min.next <= var->steps_min.prev && var->steps_min.next \
	<= var->steps_max.next && var->steps_min.next <= var->steps_max.prev)
		while (*head != var->min)
			rrab(head, stack);
	else if (var->steps_min.prev <= var->steps_min.next && var->steps_min.prev \
	<= var->steps_max.next && var->steps_min.prev <= var->steps_max.prev)
		while (*head != var->min)
			rab(head, stack);
	else if (var->steps_max.next <= var->steps_max.prev && var->steps_max.next \
	<= var->steps_min.next && var->steps_max.next <= var->steps_min.prev)
		while (*head != var->max)
			rrab(head, stack);
	else
		while (*head != var->max)
			rab(head, stack);
}

void	smart_rotate_saved_min(t_node **head, t_var *var)
{
	while (*head != var->saved_min)
	{
		if (var->steps_min.next <= var->steps_min.prev)
			rrab(head, 'a');
		else
			rab(head, 'a');
	}
}
