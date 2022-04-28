#include "push_swap.h"

void	insert_sort(int *a, int n)
{
	int i;
	int j;
	int temp;

	i = 1;
	while (i < n)
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
