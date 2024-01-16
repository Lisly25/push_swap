/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:40:03 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/16 11:50:09 by skorbai          ###   ########.fr       */
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

void	ft_rev_rotate(int ***stack, int ***other_stack)
{
	int	*temp;
	int	i;
	int	j;
	int	**stack_a;

	i = 0;
	stack_a = *stack;
	temp = (int *)malloc(sizeof(int));
	if (temp == NULL)
		return (ft_ps_malloc_error(stack, other_stack));
	while (stack_a[i] != NULL)
		i++;
	i--;
	j = i - 1;
	temp = stack_a[i];
	while (j >= 0)
		stack_a[i--] = stack_a[j--];
	stack_a[i] = temp;
	free(temp);
}

void	ft_rotate(int ***stack, int ***other_stack)
{
	int	*temp;
	int	i;
	int	j;
	int	**stack_a;

	i = 0;
	j = 1;
	stack_a = *stack;
	temp = (int *)malloc(sizeof(int));
	if (temp == NULL)
		return (ft_ps_malloc_error(stack, other_stack));
	temp = stack_a[0];
	while (stack_a[j] != NULL)
	{
		stack_a[i] = stack_a[j];
		i++;
		j++;
	}
	stack_a[i] = temp;
	free(temp);
}
