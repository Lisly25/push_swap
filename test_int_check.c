#include "push_swap.h"
#include <stdio.h>

int	check_if_int(char *num)
{
	int		number;
	char	*num_2;

	number = ft_atoi(num);
	num_2 = ft_itoa(number);
	if (ft_strncmp(num, num_2, ft_strlen(num)) != 0)
		return (1);
	return (0);
}

int	main(void)
{
	char *str = "-2147483649";

	printf("%d\n", INT_MAX);
	if (check_if_int(str) == 1)
		ft_printf("This is not an integer\n");
	else
		ft_printf("This is an integer\n");
	return (0);
}
