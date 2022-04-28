#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

struct node
{
	int			nb;
	struct node *next;
	struct node *prev;
};

struct node_ptr
{
	struct node	*head;
	struct node	*start;
	struct node	*end;
};

void	quick_sort(struct node_ptr *ptr, int lb, int ub);

#endif