/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 12:01:54 by dsaat         #+#    #+#                 */
/*   Updated: 2022/05/11 12:44:23 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	check_malloc(void *ptr)
{
	if (!ptr)
		exit(EXIT_FAILURE);
}

static void	init_var(t_var **var, int argc)
{	
	check_malloc(*var = malloc(sizeof(t_var)));
	(*var)->arg = argc - 1;
	(*var)->saved_min = NULL;
}

static void	create_dll(t_node **head, char **argv)
{
	t_node	*newnode;
	t_node	*temp;
	int		i;

	i = 1;
	while (argv[i])
	{
		check_malloc(newnode = malloc(sizeof(t_node)));
		if (*head == 0)
		{
			*head = newnode;
			temp = newnode;
			newnode->nb = ft_atoi(argv[i]);
			newnode->prev = NULL;
		}
		else
		{
			temp->next = newnode;
			newnode->nb = ft_atoi(argv[i]);
			newnode->prev = temp;
			temp = newnode;
		}
		i++;
	}
	newnode->next = NULL;
}

static void	parse_input(char **argv, t_node **head_a)
{
	check_is_number_integer(argv);
	create_dll(head_a, argv);
	check_is_double(*head_a);
	if (check_is_sorted(*head_a))
		exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	t_var	*var;

	head_a = NULL;
	head_b = NULL;
	var = NULL;
	if (argc < 2)
		exit (EXIT_FAILURE);
	parse_input(argv, &head_a);
	init_var(&var, argc);
	if (var->arg == 2)
		sort_2(&head_a);
	else if (var->arg == 3)
		sort_3(&head_a);
	else if (var->arg == 4 || var->arg == 5)
		sort_4_5(&head_a, &head_b, var);
	else
		sort_big(argv, &head_a, &head_b, var);
	return (0);
}
