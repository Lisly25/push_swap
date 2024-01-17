/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:39:22 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 10:59:26 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(int **stack)
{
	size_t	i;

	i = 0;
	if (stack != NULL)
	{
		while (stack[i] != NULL)
			free(stack[i++]);
		free(stack);
	}
}

void	free_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

/*void	ft_ps_malloc_error(int **stack_1, int **stack_2)
{
	if (*stack_1 != NULL)
		free_stack(*stack_1);
	if (*stack_2 != NULL)
		free_stack(*stack_2);
	exit(1);
}*/

void	free_stacks_struct(t_stacks *stacks)
{
	if (stacks->a != NULL)
		free_stack(stacks->a);
	if (stacks->b != NULL)
		free_stack(stacks->b);
	free(stacks);
	exit(1);
}
