#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static void	insert_sort_back(struct node **head_b, struct node **head_a, struct var *var)
{
	get_min_max_num(head_b, var);
	if (!var->saved_min)
		var->saved_min = var->min;
	get_steps(var->min, &var->steps_min);
	get_steps(var->max, &var->steps_max);
	smart_rotate(head_b, var, 'b');	
	pab(head_b, head_a, 'a');
	if (*head_a == var->min && *head_a != var->max)
		rab(head_a, 'a');
}

static int	select_next_partition_member(int ub, int lb, struct node **head_a, struct var *var)
{
	var->max = NULL;
	var->min = NULL;
	get_next_from_top_bottom(ub, lb, head_a, var);
	if (!var->max)
		return (0);
	get_steps(var->max, &var->steps_max);
	get_steps(var->min, &var->steps_min);
	smart_rotate(head_a, var, 'a');
	return (1);
}

static void	sort_args_into_array(int argc, char **argv, int *a)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1])
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 1;
	while (i < argc - 1)
	{
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
		i++;
	}
}

static void	partition_args(int argc, int *partition, int *a)
{
	partition[0] = a[0];
	partition[1] = a[(argc - 2) / 5 * 1];
	partition[2] = a[(argc - 2) / 5 * 2];
	partition[3] = a[(argc - 2) / 5 * 3];
	partition[4] = a[(argc - 2) / 5 * 4];
	partition[5] = a[(argc - 2)];
}

void	sort_big(int argc, char **argv, struct node **head_a, struct node **head_b, struct var *var)
{
	int	a[argc - 1];
	int	partition[6];
	int	x;

	sort_args_into_array(argc, argv, a);
	partition_args(argc, partition, a);
	var->saved_min = NULL;
	x = 5;
	while (x > 0)
	{
		while (select_next_partition_member(partition[x], partition[x - 1], head_a, var))
			pab(head_a, head_b, 'b');
		if (var->saved_min)
		{
			get_steps(var->saved_min, &var->steps_min);
			smart_rotate_saved_min(head_a, var);
		}
		var->saved_min = NULL;
		while (*head_b)
			insert_sort_back(head_b, head_a, var);
		x--;
	}
	get_steps(var->saved_min, &var->steps_min);
	smart_rotate_saved_min(head_a, var);
}
