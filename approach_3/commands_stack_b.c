/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:32:01 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 14:37:11 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_swap_b(t_stacks *stacks)
{
	int	temp;

	temp = stacks->b[0][0];
	stacks->b[0][0] = stacks->b[1][0];
	stacks->b[1][0] = temp;
	return (stacks);
}

static t_stacks	*ft_push_to_b_src(t_stacks *stacks, size_t size)
{
	size_t	i;
	size_t	j;
	int		**new_a;

	i = 1;
	j = 0;
	new_a = (int **)malloc(sizeof(int *) * (size + 1));
	if (new_a == NULL)
		free_stacks_struct(stacks);
	while (i < size)
		new_a[j++] = (int *)stacks->a[i++];
	new_a[j] = NULL;
	free(stacks->a);
	stacks->a = new_a;
	return (stacks);
}

t_stacks	*ft_push_to_b(t_stacks *stacks, size_t size)
{
	size_t	i;
	size_t	j;
	int		**new_b;

	i = 0;
	j = 1;
	new_b = (int **)malloc(sizeof(int *) * (size + 2));
	if (new_b == NULL)
		free_stacks_struct(stacks);
	new_b[0] = stacks->a[0];
	stacks = ft_push_to_b_src(stacks, size);
	while (i < size)
		new_b[j++] = (int *)stacks->b[i++];
	new_b[j] = NULL;
	free(stacks->b);
	stacks->b = new_b;
	return (stacks);
}

t_stacks	*ft_rev_rotate_b(t_stacks *stacks)
{
	int		**new_stack;
	size_t	i;
	size_t	j;
	size_t	size_of_b;

	i = 1;
	j = 0;
	size_of_b = get_arr_size(stacks->b);
	new_stack = (int **)malloc(sizeof(int *) * (size_of_b + 1));
	if (new_stack == NULL)
		free_stacks_struct(stacks);
	while (i < size_of_b)
		new_stack[i++] = (int *)stacks->b[j++];
	new_stack[0] = (int *)stacks->b[j];
	new_stack[i] = NULL;
	free(stacks->b);
	stacks->b = new_stack;
	return (stacks);
}

t_stacks	*ft_rotate_b(t_stacks *stacks)
{
	int			**new_stack;
	size_t		i;
	size_t		j;
	size_t		size_of_b;

	i = 0;
	j = 1;
	size_of_b = get_arr_size(stacks->b);
	new_stack = (int **)malloc(sizeof(int *) * (size_of_b + 1));
	if (new_stack == NULL)
		free_stacks_struct(stacks);
	while (j < size_of_b)
		new_stack[i++] = (int *)stacks->b[j++];
	new_stack[i++] = (int *)stacks->b[0];
	new_stack[i] = NULL;
	free(stacks->b);
	stacks->b = new_stack;
	return (stacks);
}
