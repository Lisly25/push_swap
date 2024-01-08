#include <stdio.h>

void	print_arr(int **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%d. element is %d\n", i, arr[i][0]);
		i++;
	}
}