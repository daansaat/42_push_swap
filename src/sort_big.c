/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 12:01:57 by dsaat         #+#    #+#                 */
/*   Updated: 2022/05/10 15:43:07 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static void	insert_sort_back(t_node **head_b, t_node **head_a, t_var *var)
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

static int	select_next_partition_member(int ub, int lb, t_node **head_a, \
t_var *var)
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

static void	partition_args(int arg, int *partition, int *args)
{
	partition[0] = args[0];
	partition[1] = args[(arg - 1) / 5 * 1];
	partition[2] = args[(arg - 1) / 5 * 2];
	partition[3] = args[(arg - 1) / 5 * 3];
	partition[4] = args[(arg - 1) / 5 * 4];
	partition[5] = args[(arg - 1)];
	free(args);
}

static void	sort_args_into_array(int arg, char **argv, int *args)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1])
	{
		args[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 1;
	while (i < arg)
	{
		temp = args[i];
		j = i - 1;
		while (j >= 0 && args[j] > temp)
		{
			args[j + 1] = args[j];
			j--;
		}
		args[j + 1] = temp;
		i++;
	}
}

void	sort_big(char **argv, t_node **head_a, t_node **head_b, t_var *var)
{
	int	*args;
	int	partition[6];
	int	x;

	check_malloc(args = malloc(sizeof(int) * var->arg));
	sort_args_into_array(var->arg, argv, args);
	partition_args(var->arg, partition, args);
	x = 5;
	while (x > 0)
	{
		while (select_next_partition_member(partition[x], partition[x - 1], \
		head_a, var))
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
