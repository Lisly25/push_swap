/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:40:03 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/15 11:35:46 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//if the status struct remains a thing, I need to free that, too - but it shouldn't
void	ft_ps_malloc_error(int **stack_1, int **stack_2)
{
	if (stack_1 != NULL)
		free_stack(stack_1);
	if (stack_2 != NULL)
		free_stack(stack_2);
	exit(1);
}

void	ft_swap(int **stack, int **other_stack)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int));
	if (temp == NULL)
		return (ft_ps_malloc_error(stack, other_stack));
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	free (temp);
}

static int	ft_push_src(int **src, size_t size)
{
	int	i;
	int	j;
	int	**new_src;

	i = 1;
	j = 0;
	new_src = (int **)malloc(sizeof(int *) * (size + 1));
	if (new_src == NULL)
		return (1);
	while (src[i] != NULL)
		new_src[j++] = src[i++];
	new_src[j] = NULL;
	free_stack(src);
	src = new_src;
	return (0);
}

void	ft_push(int	**src, int**dest, size_t size)
{
	int	i;
	int	j;
	int	**new_dest;

	i = 0;
	j = 1;
	new_dest = (int **)malloc(sizeof(int *) * (size + 1));
	if (new_dest == NULL)
		return (ft_ps_malloc_error(src, dest));
	new_dest[0] = src[0];
	if (ft_push_src(src, size) == 1)
	{
		free_stack(new_dest);
		return (ft_ps_malloc_error(src, dest));
	}
	while (dest[i] != NULL)
		new_dest[j++] = dest[i++];
	new_dest[j] = NULL;
	free_stack(dest);
	dest = new_dest;
}
//first becomes last: index decreases
void	ft_rev_rotate(int **stack, int **other_stack)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	temp = (int *)malloc(sizeof(int));
	if (temp == NULL)
		return (ft_ps_malloc_error(stack, other_stack));
	while (stack[i] != NULL)
		i++;
	i--;
	j = i - 1;
	temp = stack[i];
	while (j >= 0)
		stack[i--] = stack[j--];
	stack[i] = temp;
	free(temp);
}
//last becomes first, index increases
void	ft_rotate(int **stack, int **other_stack)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	j = 1;
	temp = (int *)malloc(sizeof(int));
	if (temp == NULL)
		return (ft_ps_malloc_error(stack, other_stack));
	temp = stack[0];
	while (stack[j] != NULL)
		stack[i++] = stack[j++];
	stack[i] = temp;
	free(temp);
}
