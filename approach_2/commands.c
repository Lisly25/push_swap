/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:40:03 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 13:15:33 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_swap_b(t_stacks *stacks)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int));
	if (temp == NULL)
		free_stacks_struct(stacks);
	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
	if (temp != NULL)
		free(temp);
	return (stacks);
}

static t_stacks	*ft_push_src(t_stacks *stacks, size_t size)
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
	stacks = ft_push_src(stacks, size);
	while (i < size)
		new_b[j++] = (int *)stacks->b[i++];
	new_b[j] = NULL;
	free(stacks->b);
	stacks->b = new_b;
	return (stacks);
}

t_stacks	*ft_rev_rotate(t_stacks *stacks)
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
	//printf("Within rev rotate:\n");
	//print_int_arr(new_stack);
	free(stacks->a);
	stacks->a = new_stack;
	return (stacks);
}

t_stacks	*ft_rotate(t_stacks *stacks)
{
	int			**new_stack;
	size_t		i;
	size_t		j;
	size_t		size_of_a;

	i = 0;
	j = 1;
	//printf("Start of ft_rotate\n");
	//print_int_arr(stacks->a);
	size_of_a = get_arr_size(stacks->a);
	new_stack = (int **)malloc(sizeof(int *) * (size_of_a + 1));
	if (new_stack == NULL)
		free_stacks_struct(stacks);
	while (j < size_of_a)
		new_stack[i++] = (int *)stacks->a[j++];
	new_stack[i++] = (int *)stacks->a[0];
	new_stack[i] = NULL;
	//printf("New stack:\n");
	//print_int_arr(new_stack);
	free(stacks->a);
	stacks->a = new_stack;
	//print_int_arr(stacks->a);
	return (stacks);
}
