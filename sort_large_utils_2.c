/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:49:07 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/11 11:46:39 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	count_larger_outside(int **a, ssize_t index, ssize_t prev_index)
{
	size_t	count;
	ssize_t	j;

	j = index;
	count = 0;
	if (prev_index > index)
	{
		j = prev_index;
		while (a[j])
		{
			if (a[index][0] > a[j][0])
				count++;
			j++;
		}
		j = 0;
		while (j < index)
		{
			if (a[index][0] > a[j][0])
				count++;
			j++;
		}
	}
	return (-1);
}

static ssize_t	count_larger_inside(int **a, ssize_t index, ssize_t prev_index)
{
	ssize_t	j;
	size_t	count;

	j = index;
	count = 0;
	if (index > prev_index)
	{
		while (j != prev_index)
		{
			if (a[index][0] > a[j][0])
				count++;
			j++;
		}
		return (count);
	}
	return (-1);
}

static ssize_t	count_larger_inside_rev(int **a, ssize_t index, t_sort_status *status)
{
	ssize_t	j;
	size_t	count;

	j = index;
	count = 0;
	if (index > prev_index)
	{
		while (j != prev_index)
		{
			if (a[index][0] > a[j][0] && a[j][0] != status->prev_high)
				count++;
			j++;
		}
		return (count);
	}
	return (-1);
}

ssize_t	get_real_i(int **a, ssize_t index, t_sort_status *status)
{
	ssize_t	real_index;
	//ssize_t	real_index_2;

	if (status->prev_low == -1)
		return (index);
	if (status->prev_method == 'o')
	{
		if (index > status->prev_high)
			real_index = count_larger_inside(a, index, status->prev_high);
		else
			real_index = count_larger_outside(a, index, status->prev_high);
	}
	else
	{
		if (index > status->prev_low)
			real_index = count_larger_inside_rev(a, index, status);
		else
			real_index = count_larger_outside_rev(a, index, status);
	}
	return (real_index);
}
