#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void error_exit(void)
{
    ft_putstr_fd("Error\n", 1);
    exit(EXIT_FAILURE);
}

void    check_is_number(char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (argv[i])
    {
        if (argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                error_exit();
            j++;
        }
        j = 0;
        i++;
    }
}

void    check_is_double(struct node *head)
{
    struct node *temp;
    int         nb;

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

void    check_is_integer(char *nb)
{
	char	digit;
    int		nbr;
	int		len;

    nbr = ft_atoi(nb);
    len = ft_strlen(nb) - 1;
	while (len >= 0)
	{
		digit = nbr % 10;
        if (digit < 0 && nb[0] == '-')
            digit *= -1;
        digit += '0';
		if (digit != nb[len])
            error_exit();
		nbr /= 10;
		len--;
		if (nb[len] == '-' || nb[len] == '+')
			break;
	}
}

void    check_is_sorted(struct node *head)
{
    while (head->next)
    {
        if (head->next->nb < head->nb)
            return ;
        head = head->next;
    }
    ft_putstr_fd("Already sorted\n", 1);
    exit(EXIT_SUCCESS);
}