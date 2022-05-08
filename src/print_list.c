#include "push_swap.h"
#include <stdio.h>

void	print_list(struct node *head_a, struct node *head_b)
{
	struct node		*temp;
	
	temp = head_a;
	while (temp)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
	}
	printf("\n");
	temp = head_b;
	while (temp)
	{
		printf("%d ", temp->nb);
		temp = temp->next;
	}
	printf("\n");
}

// void    sort_3(struct node **head_a)
// {
//     int a;
//     int b;
//     int c;

//     a = (*head_a)->nb;
//     b = (*head_a)->next->nb;
//     c = (*head_a)->next->next->nb;
//     if (a > b && b < c && a < c)
//         sab(head_a, 'a');
//     else if (a > b && b < c)
//         rab(head_a, 'a');
//     else if (a > b && b > c)
//     {
//         sab(head_a, 'a');
//         rrab(head_a, 'a');
//     }
//     else if (a < b && b > c && a < c)
//     {
//         sab(head_a, 'a');
//         rab(head_a, 'a');
//     }
//     else
//         rrab(head_a, 'a');
// }