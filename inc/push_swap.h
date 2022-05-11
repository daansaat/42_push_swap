/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 14:45:47 by dsaat         #+#    #+#                 */
/*   Updated: 2022/05/11 17:22:13 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	struct s_node	*prev;
	int				nb;
	struct s_node	*next;
}	t_node;

typedef struct s_steps
{
	int	next;
	int	prev;
}	t_steps;

typedef struct s_var
{
	t_node	*max;
	t_node	*min;
	t_node	*saved_min;
	t_steps	steps_max;
	t_steps	steps_min;
	int		arg;
}	t_var;

void	sab(t_node **head, char stack);
void	pab(t_node **head_from, t_node **head_to, char stack);
void	rab(t_node **head, char stack);
void	rrab(t_node **head, char stack);

void	sort_2(t_node **head_a);
void	sort_3(t_node **head_a);
void	sort_4_5(t_node **head_a, t_node **head_b, t_var *var);
void	sort_big(char **argv, t_node **head_a, t_node **head_b, t_var *var);

void	get_min_max_num(t_node **head, t_var *var);
void	get_next_from_top_bottom(int ub, int lb, t_node **head, t_var *var);
void	get_steps(t_node *node, t_steps *steps);
void	smart_rotate(t_node **head, t_var *var, char stack);
void	smart_rotate_saved_min(t_node **head, t_var *var);

void	check_malloc(void *ptr);
void	check_is_number_integer(char **argv);
void	check_is_double(t_node *head);
void	check_is_sorted(t_node *head);

#endif
