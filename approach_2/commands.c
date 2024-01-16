/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:40:03 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/16 17:41:57 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int ***stack, int ***other_stack)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int));
	if (temp == NULL)
		return (ft_ps_malloc_error(stack, other_stack));
	temp = *stack[0];
	*stack[0] = *stack[1];
	*stack[1] = temp;
	free (temp);
}

static int	**ft_push_src(int ***src, size_t size)
{
	size_t	i;
	size_t	j;
	int		**new_src;

	i = 1;
	j = 0;
	new_src = (int **)malloc(sizeof(int *) * (size + 1));
	if (new_src == NULL)
		return (NULL);
	while (i < size)
		new_src[j++] = (int *)(*src)[i++];
	new_src[j] = NULL;
	free(*src);
	return (new_src);
}

int	**ft_push(int ***src, int ***dest, size_t size)
{
	size_t	i;
	size_t	j;
	int		**new_dest;

	i = 0;
	j = 1;
	new_dest = (int **)malloc(sizeof(int *) * (size + 2));
	if (new_dest == NULL)
	{
		ft_ps_malloc_error(src, dest);
		return (NULL);
	}
	new_dest[0] = *src[0];
	*src = ft_push_src(src, size);
	if (*src == NULL)
	{
		free_stack(new_dest);
		ft_ps_malloc_error(src, dest);
		return (NULL);
	}
	while (i < size)
		new_dest[j++] = (int *)(*dest)[i++];
	new_dest[j] = NULL;
	free(*dest);
	return (new_dest);
}

int	**ft_rev_rotate(int ***stack, int ***other_stack)
{
	int		**new_stack;
	int		**a;
	size_t	i;
	size_t	j;
	size_t	size_of_a;

	a = *stack;
	i = 1;
	j = 0;
	size_of_a = get_arr_size(a);
	new_stack = malloc(sizeof(int *) * (size_of_a + 1));
	if (new_stack == NULL)
	{
		ft_ps_malloc_error(stack, other_stack);
		return (NULL);
	}
	while (i < size_of_a)
		new_stack[i++] = (int *)a[j++];
	new_stack[0] = (int *)a[j];
	new_stack[i] = NULL;
	//printf("Within rev rotate:\n");
	//print_int_arr(new_stack);
	return (new_stack);
}

int	**ft_rotate(int ***stack, int ***other_stack)
{
	int		**new_stack;
	int		**a;
	size_t	i;
	size_t	j;
	size_t	size_of_a;

	a = *stack;
	i = 0;
	j = 1;
	size_of_a = get_arr_size(a);
	new_stack = malloc(sizeof(int *) * (size_of_a + 1));
	if (new_stack == NULL)
	{
		ft_ps_malloc_error(stack, other_stack);
		return (NULL);
	}
	while (j < size_of_a)
		new_stack[i++] = (int *)a[j++];
	new_stack[i++] = (int *)a[0];
	new_stack[i] = NULL;
	//printf("Within rotate:\n");
	//print_int_arr(new_stack);
	return (new_stack);
}
