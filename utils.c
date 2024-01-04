/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:45:01 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/04 15:28:33 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_of_greater_than(int **a, int num, size_t count)
{
	size_t	i;
	size_t	greater_than;

	i = 0;
	greater_than = 0;
	while (i < count)
	{
		if (a[i][0] < num)
			greater_than++;
		i++;
	}
	return (greater_than);
}

size_t	range_count_of_greater_than(int **a, int num, int start, int end)
{
	size_t	greater_than;

	greater_than = 0;
	while (start <= end)
	{
		if (a[start][0] < num)
			greater_than++;
		start++;
	}
	return (greater_than);
}
