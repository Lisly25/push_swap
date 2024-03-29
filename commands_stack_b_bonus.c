/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_stack_b_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:31:25 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/25 11:05:24 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stacks	*ft_swap_b(t_stacks *stacks)
{
	int		temp;
	size_t	arr_size;

	arr_size = get_arr_size(stacks->b);
	if (arr_size < 2)
		return (stacks);
	temp = stacks->b[0][0];
	stacks->b[0][0] = stacks->b[1][0];
	stacks->b[1][0] = temp;
	return (stacks);
}

static t_stacks	*ft_push_to_b_src(t_stacks *stacks)
{
	size_t	i;
	size_t	j;
	size_t	size;
	int		**new_a;

	i = 1;
	j = 0;
	size = get_arr_size(stacks->a);
	new_a = (int **)malloc(sizeof(int *) * size);
	if (new_a == NULL)
		free_stacks_struct(stacks);
	while (i < size)
		new_a[j++] = (int *)stacks->a[i++];
	new_a[j] = NULL;
	free(stacks->a);
	stacks->a = new_a;
	return (stacks);
}

t_stacks	*ft_push_to_b(t_stacks *stacks)
{
	size_t	i;
	size_t	j;
	size_t	size;
	int		**new_b;

	i = 0;
	j = 1;
	size = get_arr_size(stacks->b);
	new_b = (int **)malloc(sizeof(int *) * (size + 2));
	if (new_b == NULL)
		free_stacks_struct(stacks);
	new_b[0] = stacks->a[0];
	stacks = ft_push_to_b_src(stacks);
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
