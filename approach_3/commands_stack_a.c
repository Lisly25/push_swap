/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:40:03 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 14:40:11 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_swap_a(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[0][0];
	stacks->a[0][0] = stacks->a[1][0];
	stacks->a[1][0] = temp;
	return (stacks);
}

static t_stacks	*ft_push_to_a_src(t_stacks *stacks, size_t size)
{
	size_t	i;
	size_t	j;
	int		**new_b;

	i = 1;
	j = 0;
	new_b = (int **)malloc(sizeof(int *) * (size + 1));
	if (new_b == NULL)
		free_stacks_struct(stacks);
	while (i < size)
		new_b[j++] = (int *)stacks->b[i++];
	new_b[j] = NULL;
	free(stacks->b);
	stacks->b = new_b;
	return (stacks);
}

t_stacks	*ft_push_to_a(t_stacks *stacks, size_t size)
{
	size_t	i;
	size_t	j;
	int		**new_a;

	i = 0;
	j = 1;
	new_a = (int **)malloc(sizeof(int *) * (size + 2));
	if (new_a == NULL)
		free_stacks_struct(stacks);
	new_a[0] = stacks->b[0];
	stacks = ft_push_to_a_src(stacks, size);
	while (i < size)
		new_a[j++] = (int *)stacks->a[i++];
	new_a[j] = NULL;
	free(stacks->a);
	stacks->a = new_a;
	return (stacks);
}

t_stacks	*ft_rev_rotate_a(t_stacks *stacks)
{
	int		**new_stack;
	size_t	i;
	size_t	j;
	size_t	size_of_a;

	i = 1;
	j = 0;
	size_of_a = get_arr_size(stacks->a);
	new_stack = (int **)malloc(sizeof(int *) * (size_of_a + 1));
	if (new_stack == NULL)
		free_stacks_struct(stacks);
	while (i < size_of_a)
		new_stack[i++] = (int *)stacks->a[j++];
	new_stack[0] = (int *)stacks->a[j];
	new_stack[i] = NULL;
	free(stacks->a);
	stacks->a = new_stack;
	return (stacks);
}

t_stacks	*ft_rotate_a(t_stacks *stacks)
{
	int			**new_stack;
	size_t		i;
	size_t		j;
	size_t		size_of_a;

	i = 0;
	j = 1;
	size_of_a = get_arr_size(stacks->a);
	new_stack = (int **)malloc(sizeof(int *) * (size_of_a + 1));
	if (new_stack == NULL)
		free_stacks_struct(stacks);
	while (j < size_of_a)
		new_stack[i++] = (int *)stacks->a[j++];
	new_stack[i++] = (int *)stacks->a[0];
	new_stack[i] = NULL;
	free(stacks->a);
	stacks->a = new_stack;
	return (stacks);
}
