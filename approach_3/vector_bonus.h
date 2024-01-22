/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:12 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/22 14:48:36 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

# include <stdlib.h>

typedef struct s_vector_array
{
	char	**array;
	size_t	used_nodes;
	size_t	max_nodes;
}	t_vector;

t_vector	*vector_new(size_t size);

int			vector_add_back(t_vector *old, char *new_data);

char		**vector_array_realloc(char ***old_array, size_t node_max);

int			expand_vector(t_vector *old);

void		vector_free(t_vector *vector);

#endif