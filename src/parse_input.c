#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

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
            {
                write(1, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
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
            {
                write(1, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
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
	if (nbr == -2147483648 && nb[0] == '-')
		return ;
	if (nbr < 0)
		nbr *= -1;
	while (len >= 0)
	{
		digit = nbr % 10 + '0';
		if (digit != nb[len])
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
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
    exit(EXIT_SUCCESS);
}