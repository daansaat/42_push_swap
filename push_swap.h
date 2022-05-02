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

void	sab(struct node *head);
void	pab(struct node **head_to, struct node **head_from);
void	rab(struct node **head);
void	rrab(struct node **head);
void	ss(struct node *head_a, struct node *head_b)
void	rr(struct node **head_a, struct node **head_b)
void	rrr(struct node **head_a, struct node **head_b)

//void	add_front(struct node **head_to, struct node **head_from);

#endif