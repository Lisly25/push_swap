/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:36:00 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/23 11:23:52 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	**get_list(int argnum, char **argv, int i)
{
	int	**stack_a;
	int	j;

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

static int	**get_str(char *str)
{
	char	**list;
	int		**stack_a;
	int		arr_len;

	arr_len = 0;
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
	stack_b = (int **)malloc(sizeof(int *));
	if (stack_b == NULL)
	{
		free_stack(stack_a);
		exit(1);
	}
	stack_b[0] = NULL;
	return (stack_b);
}

int	**init_stack_a(int argc, char **argv)
{
	int	**stack_a;
	int	i;

	i = 1;
	if (argc < 1)
		exit (1);
	if (argc == 2)
	{
		if (is_empty_string(argv[1]) != 1)
			stack_a = get_str(argv[1]);
		else
			return (NULL);
	}
	else
	{
		while (argv[i])
		{
			if (check_if_int(argv[i]) == 1)
				return (NULL);
			i++;
		}
		stack_a = get_list((argc - 1), argv, 1);
	}
	return (stack_a);
}
