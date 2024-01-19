/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:39:22 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/19 14:41:39 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_stack(int **stack)
{
	size_t	i;

	i = 0;
	if (stack != NULL)
	{
		while (stack[i] != NULL)
		{
			stack[i][0] = 0;
			free(stack[i]);
			i++;
		}
		free(stack);
	}
}

void	free_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	free_stacks_struct(t_stacks *stacks)
{
	if (stacks->a != NULL)
		free_stack(stacks->a);
	if (stacks->b != NULL)
		free_stack(stacks->b);
	free(stacks);
	exit(1);
}
