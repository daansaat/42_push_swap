#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	a[argc - 1];
	int	i = 0;

	while (argv[i + 1])
	{
		a[i] = atoi(argv[i + 1]);
		i++;
	}
	insert_sort(a, argc - 1);
	quick_sort(a, 0, argc - 2);
	i = 0;
	printf("%d\n", a[(argc - 1) / 2]);
	while (i != argc - 1)
	{
		printf("%d ", a[i]);
		i++;
	}
}