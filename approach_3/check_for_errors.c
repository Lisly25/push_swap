/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:24:40 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/19 14:38:13 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_for_duplicates(int **a, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (i < count)
	{
		while (j < count)
		{
			if (a[i][0] == a[j][0])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

static int	check_if_already_sorted(int **a, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (j < count)
	{
		if (a[i][0] > a[j][0])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	check_if_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_if_int(char *num)
{
	int		number;
	char	*num_2;

	number = ft_atoi(num);
	num_2 = ft_itoa(number);
	if (ft_strncmp(num, num_2, ft_strlen(num)) != 0)
	{
		free(num_2);
		return (1);
	}
	free(num_2);
	return (0);
}

int	check_for_errors(int **a)
{
	size_t	stack_size;

	stack_size = get_arr_size(a);
	if (check_for_duplicates(a, stack_size) == 1)
	{
		ft_putendl_fd("Error", 2);
		free_stack(a);
		return (1);
	}
	if (check_if_already_sorted(a, stack_size) == 1)
	{
		free_stack(a);
		return (1);
	}
	return (0);
}
