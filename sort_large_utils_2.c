/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:49:07 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/12 15:53:49 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	count_larger_outside(int **a, ssize_t index, ssize_t prev_index)
{
	size_t	count;
	ssize_t	j;

	count = 0;
	if (prev_index > index)
	{
		j = prev_index;
		while (a[j] != NULL)
		{
			if (a[index][0] < a[j][0])
				count++;
			j++;
		}
		j = 0;
		while (j < index)
		{
			if (a[index][0] < a[j][0])
				count++;
			j++;
		}
		//printf("We used c_l_outside\n");
		return (count);
	}
	return (-1);
}

static ssize_t	count_larger_outside_rev(int **a, ssize_t index, t_sort_status *status)
{
	size_t	count;
	ssize_t	j;

	j = index;
	count = 0;
	if (status->prev_low > index)
	{
		//printf("In count larger outside, prev_low: %zd\n prev_high: %zd\n", status->prev_low, status->prev_high);
		j = status->prev_low;
		while (a[j] != NULL)
		{
			if (a[index][0] < a[j][0] && j != status->prev_high && j != status->prev_low)
				count++;
			j++;
		}
		j = 0;
		while (j < index)
		{
			if (a[index][0] < a[j][0] && j != status->prev_high && j != status->prev_low)
				count++;
			j++;
		}
		//printf("We used c_l_rev\n");
		return (count);
	}
	return (-1);
}

static ssize_t	count_larger_inside(int **a, ssize_t index, ssize_t prev_index)
{
	ssize_t	j;
	size_t	count;

	j = prev_index;
	count = 0;
	if (index > prev_index)
	{
		while (j != index)
		{
			if (a[index][0] < a[j][0])
				count++;
			j++;
		}
		//printf("We used cl_inside\n");
		return (count);
	}
	return (-1);
}

static ssize_t	count_larger_inside_rev(int **a, ssize_t index, t_sort_status *status)
{
	ssize_t	j;
	size_t	count;

	j = status->prev_low;
	count = 0;
	if (index > status->prev_low)
	{
		//printf("We got here. J is %zu, index is %zu, prev_low is %zu\n", j, index, status->prev_low);
		while (j != index)
		{
			if (a[index][0] < a[j][0] && j != status->prev_high && j != status->prev_low)
				count++;
			j++;
		}
		//printf("We used cl_inside_rev, count is %zu\n", count);
		return (count);
	}
	return (-1);
}

ssize_t	get_real_i(int **a, ssize_t index, t_sort_status *status)
{
	ssize_t	real_index;

	if (status->prev_method == 'n' && status->real_size == status->og_size)
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
