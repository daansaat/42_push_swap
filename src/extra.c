void	sab(struct node *head)
{
	int	temp;

	if (!head || !head->next)
		return ;
	temp = head->nb;
	head->nb = head->next->nb;
	head->next->nb = temp;
}

void	ss(struct node *head_a, struct node *head_b)
{
	if (!head_a || !head_b || !head_a->next || !head_b->next)
		return ;
	sab(head_a);
	sab(head_b);
}

void	rr(struct node **head_a, struct node **head_b)
{
	rab(head_a);
	rab(head_b);
}

void	rrr(struct node **head_a, struct node **head_b)
{
	rrab(head_a);
	rrab(head_b);
}