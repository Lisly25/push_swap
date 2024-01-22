/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:18:23 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/22 14:49:30 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"
#include "push_swap_bonus.h"

void	vector_free(t_vector *vector)
{
	int	i;

	i = 0;
	while (vector->array[i] != NULL)
	{
		free(vector->array[i]);
		i++;
	}
	free(vector->array);
	free(vector);
}

t_vector	*vector_new(size_t size)
{
	t_vector	*new_vector;

	new_vector = (t_vector *)malloc(sizeof(t_vector));
	if (new_vector == NULL)
		return (NULL);
	new_vector->array = (char **)malloc(size * sizeof(char *));
	if (new_vector->array == NULL)
		return (NULL);
	new_vector->max_nodes = size;
	new_vector->used_nodes = 0;
	return (new_vector);
}

char	**vector_array_realloc(char ***old_array, size_t node_max)
{
	char	**new_array;
	size_t	i;

	i = 0;
	new_array = (char **)malloc(sizeof(char *) * node_max * 2);
	if (new_array == NULL)
		return (NULL);
	while (i < node_max)
	{
		new_array[i] = (char *)(*old_array)[i];
		i++;
	}
	free(*old_array);
	return (new_array);
}

int	expand_vector(t_vector *old)
{
	old->array = vector_array_realloc(&old->array, old->max_nodes);
	if (old->array == NULL)
	{
		return (1);
	}
	old->max_nodes *= 2;
	return (0);
}

int	vector_add_back(t_vector *old, char *new_data)
{
	if (old->used_nodes == old->max_nodes)
	{
		if (expand_vector(old) == 1)
		{
			vector_free(old);
			free(new_data);
			ft_putendl_fd("Error", 2);
		}
	}
	old->array[old->used_nodes] = new_data;
	old->used_nodes++;
	return (0);
}
