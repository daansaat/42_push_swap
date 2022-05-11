/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 12:01:51 by dsaat         #+#    #+#                 */
/*   Updated: 2022/05/11 17:18:06 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static int	check_plus_min(char **argv, int i, int j)
{
	if (argv[i][j] == '-' || argv[i][j] == '+')
	{
		if (argv[i][j - 1] && (argv[i][j - 1] == '-' || argv[i][j - 1] == '+'))
			error_exit();
		else
			return (1);
	}
	return (0);
}

void	check_is_number_integer(char **argv)
{
	char	digit;
	int		nbr;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		j = ft_strlen(argv[i]) - 1;
		while (j >= 0)
		{
			digit = nbr % 10;
			if (digit < 0 && argv[i][0] == '-')
				digit *= -1;
			digit += '0';
			if (digit != argv[i][j])
				error_exit();
			nbr /= 10;
			j--;
			if (check_plus_min(argv, i, j))
				break ;
		}
		i++;
	}
}

void	check_is_double(t_node *head)
{
	t_node	*temp;
	int		nb;

	temp = head;
	while (temp)
	{
		nb = head->nb;
		while (head->next)
		{
			head = head->next;
			if (nb == head->nb)
				error_exit();
		}
		temp = temp->next;
		head = temp;
	}
}

int	check_is_sorted(t_node *head)
{
	while (head->next)
	{
		if (head->next->nb < head->nb)
			return (0);
		head = head->next;
	}
	return (1);
}
