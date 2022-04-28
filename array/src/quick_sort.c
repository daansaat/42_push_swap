#include "push_swap.h"

static void	swap(int *x, int *y)
{
	int	temp;
	
	temp = *x;
	*x = *y;
	*y = temp;
}

static int	partition(int *a, int lb, int ub)
{
	int	pivot = a[lb];
	int start = lb;
	int end = ub;
	while (start < end)
	{
		while (a[start] <= pivot)
			start++;
		while (a[end] > pivot)
			end--;
		if (start < end)
			swap(&a[start], &a[end]);
	}
	swap(&a[lb], &a[end]);
	return (end);
}

void	quick_sort(int *a, int lb, int ub)
{
	int loc;

	if (lb < ub)
	{
		loc = partition(a, lb, ub);
		quick_sort(a, lb, loc - 1);
		quick_sort(a, loc + 1, ub);
	}
}