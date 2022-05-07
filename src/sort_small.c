#include "push_swap.h"

void    sort_2(struct node **head_a)
{
    if ((*head_a)->nb > (*head_a)->next->nb)
        sab(head_a, 'a');
}

void    sort_3(struct node **head_a)
{
    if ((*head_a)->nb > (*head_a)->next->nb \
    && (*head_a)->next->nb < (*head_a)->next->next->nb \
    && (*head_a)->nb < (*head_a)->next->next->nb)
        sab(head_a, 'a');
    else if ((*head_a)->nb > (*head_a)->next->nb \
    && (*head_a)->next->nb < (*head_a)->next->next->nb)
        rab(head_a, 'a');
    else if ((*head_a)->nb > (*head_a)->next->nb \
    && (*head_a)->next->nb > (*head_a)->next->next->nb)
    {
        sab(head_a, 'a');
        rrab(head_a, 'a');
    }
    else if ((*head_a)->nb < (*head_a)->next->nb \
    && (*head_a)->next->nb > (*head_a)->next->next->nb \
    && (*head_a)->nb < (*head_a)->next->next->nb)
    {
        sab(head_a, 'a');
        rab(head_a, 'a');
    }
    else if ((*head_a)->nb < (*head_a)->next->nb \
    && (*head_a)->next->nb < (*head_a)->next->next->nb)
        return ;
    else
        rrab(head_a, 'a');
}

void    sort_4_5(struct node **head_a, struct node **head_b, struct var *var, int argc)
{
	(void) argc;
    get_min_max_num(head_a, var);
	var->saved_min = var->min;
    get_steps(var->min, &var->steps_min);
	smart_rotate_saved_min(head_a, var);
	pab(head_a, head_b, 'b');
    if (argc == 6)
    {
        get_min_max_num(head_a, var);
        var->saved_min = var->min;
        get_steps(var->min, &var->steps_min);
        smart_rotate_saved_min(head_a, var);
        pab(head_a, head_b, 'b');
    }
    sort_3(head_a);
    while (*head_b)
	    pab(head_b, head_a, 'a');
}
