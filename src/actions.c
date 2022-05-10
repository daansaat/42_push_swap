/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 12:01:48 by dsaat         #+#    #+#                 */
/*   Updated: 2022/05/10 14:55:31 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	sab(t_node **head, char stack)
{
	int	temp;

	if (!*head || !(*head)->next)
		return ;
	temp = (*head)->nb;
	(*head)->nb = (*head)->next->nb;
	(*head)->next->nb = temp;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	pab(t_node **head_from, t_node **head_to, char stack)
{
	t_node	*temp;

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
	if (stack == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	rab(t_node **head, char stack)
{
	t_node	*temp;

	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	(*head)->prev = temp;
	*head = (*head)->next;
	(*head)->prev = NULL;
	temp->next->next = NULL;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rrab(t_node **head, char stack)
{
	t_node	*temp;

	temp = *head;
	while (temp->next)
		temp = temp->next;
	(*head)->prev = temp;
	temp->next = *head;
	*head = temp;
	temp->prev->next = NULL;
	(*head)->prev = NULL;
	if (stack == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
