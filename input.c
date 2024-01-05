/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:49:45 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/05 11:56:55 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**get_str(char *str)
{
	char	**list;
	int		**stack_a;
	int		arr_len;

	arr_len = 0;
	if (check_if_num(str) == 1)
		return (NULL);
	list = ft_split(str, ' ');
	if (list == NULL)
		return (NULL);
	while (list[arr_len] != NULL)
	{
		if (check_if_int(list[arr_len]) == 1)
		{
			free_list(list);
			return (NULL);
		}
		arr_len++;
	}
	stack_a = get_list(arr_len, list, 0);
	free_list(list);
	if (stack_a == NULL)
		return (NULL);
	return (stack_a);
}

int	**get_list(int argnum, char **argv, size_t i)
{
	int		**stack_a;
	size_t	j;

	j = 0;
	stack_a = (int **)malloc(sizeof(int *) * (argnum + 1));
	if (stack_a == NULL)
		return (NULL);
	while (j < argnum)
	{
		stack_a[j] = (int *)malloc(sizeof(int));
		if (stack_a[j] == NULL)
		{
			free_stack(stack_a);
			return (NULL);
		}
		j++;
	}
	j = 0;
	if (i == 0)
		argnum--;
	while (i <= argnum)
		stack_a[j++][0] = ft_atoi(argv[i++]);
	stack_a[j] = NULL;
	return (stack_a);
}

size_t	get_arr_size(int **stack)
{
	size_t	i;

	i = 0;
	while (stack[i] != NULL)
		i++;
	return (i);
}

int	**init_stack_b(int **stack_a)
{
	size_t	i;
	size_t	j;
	int		**stack_b;

	i = get_arr_size(stack_a);
	j = 0;
	stack_b = (int **)malloc(sizeof(int *) * (i + 1));
	if (stack_b == NULL)
		return (NULL);
	while (i >= 0)
	{
		stack_b[j] = calloc(1, sizeof(int));
		if (stack_b == NULL)
		{
			free_stack(stack_a);
			return (NULL);
		}
		j++;
		i--;
	}
	stack_b[j] = NULL;
	return (stack_b);
}
