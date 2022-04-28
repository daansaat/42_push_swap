// #include "push_swap.h"
// #include <stdlib.h>

// struct node	*del_node(struct node stack)
// {
// 	struct node	*temp;

// 	if (!stack)
// 		return (NULL);
// 	if (!stack->next)
// 	{
// 		free(stack)
// 		return (NULL);
// 	}
// 	temp = stack->next;
// 	temp->prev = NULL;
// 	free(stack);
// 	return (temp);
// }

// struct node	*add_front(struct node **stack1, struct node **stack2)
// {
// 	struct node	*newnode;

// 	if (stack1)
// 	{
// 		newnode = malloc(sizeof(struct node));
// 		newnode->nb = stack1->nb;
// 		if (stack2 != NULL)
// 			newnode->next = stack2->next;
// 		stack2 = newnode;
// 		return (stack2);
// 	}
// 	else
// 		return (NULL);
// }

// int	pab(struct node **head_to, struct node **head_from)
// {
// 	struct node	*temp;
	
// 	if (!*head_from)
// 		return (0);
// 	temp = *head_to;
// 	*head_to = *head_from;
// 	*head_from = *head_from->next;
// 	*head_to->next = temp;
	// temp = *head_from;
	// *head_from = *head_from->next;
	// if (!*head_to)

	

	// //struct node	*newnode;
	// struct node	*temp;

	// if (!*head_from)
	// 	return ;
	// if (*head_from)
	// {
	// 	newnode = malloc(sizeof(struct node));
	// 	newnode->nb = *head_from->nb;
	// 	if (*head_to != NULL)
	// 		newnode->next = *head_to->next;
	// 	*head_to = newnode;
	// }
	// if (!stack->next)
	// {
	// 	free(stack)
	// 	return (NULL);
	// }
	// temp = stack->next;
	// temp->prev = NULL;
	// free(stack);
	// return (temp);

// }