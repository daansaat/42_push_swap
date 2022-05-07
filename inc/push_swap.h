#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

struct node
{
	int			nb;
	struct node *next;
	struct node *prev;
};

struct steps
{
	int	next;
	int	prev;
};

struct var
{
	struct node		*max;
	struct node		*min;
	struct node		*saved_min;
	struct steps	steps_max;
	struct steps	steps_min;
};

void	sab(struct node **head, char stack);
void	pab(struct node **head_from, struct node **head_to, char stack);
void	rab(struct node **head, char stack);
void	rrab(struct node **head, char stack);

void    sort_2(struct node **head_a);
void    sort_3(struct node **head_a);
void    sort_4_5(struct node **head_a, struct node **head_b, struct var *var, int argc);
void	sort_big(int argc, char **argv, struct node **head_a, struct node **head_b, struct var *var);

void	get_min_max_num(struct node **head, struct var *var);
void    get_next_from_top_bottom(int ub, int lb, struct node **head, struct var *var);
void	get_steps(struct node *node, struct steps *steps);
void	smart_rotate(struct node **head, struct var *var, char stack);
void	smart_rotate_saved_min(struct node **head, struct var *var);

void    check_is_number(char **argv);
void    check_is_integer(char *nb);
void    check_is_sorted(struct node *head);
void    check_is_double(struct node *head);
//
void	print_list(struct node *head_a, struct node *head_b);
//
#endif