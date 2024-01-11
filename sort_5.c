/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:49:26 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/11 09:51:52 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*sort_last_3(int **a, int i)
{
	int	j;
	int	k;

	j = i + 1;
	k = i + 2;
	if (a[i][0] < a[j][0] && a[j][0] < a[k][0])
		return ("\n");
	if (a[i][0] < a[j][0] && a[j][0] > a[k][0] && a[i][0] < a[k][0])
		return ("rra\nsa\n");
	if (a[i][0] > a[j][0] && a[j][0] < a[k][0] && a[i][0] < a[k][0])
		return ("sa\n");
	if (a[i][0] < a[j][0] && a[j][0] > a[k][0] && a[i][0] > a[k][0])
		return ("rra\n");
	if (a[i][0] > a[j][0] && a[j][0] < a[k][0] && a[i][0] > a[k][0])
		return ("ra\n");
	if (a[i][0] > a[j][0] && a[j][0] > a[k][0] && a[i][0] > a[k][0])
		return ("ra\nsa\n");
	return ("");
}

char	*last_sort(int **a, size_t greater_than)
{
	char	*result;

	if (greater_than == 0)
		result = ft_strdup("pa\n");
	if (greater_than == 1)
		result = ft_strdup("pa\nsa\n");
	if (greater_than == 2)
		result = ft_strdup("pa\nsa\nra\nsa\nrra\n");
	if (greater_than == 3)
		result = ft_strdup("rra\npa\nra\nra\n");
	if (greater_than == 4)
		result = ft_strdup("pa\nra\n");
	return (result);
}

char	*sort_first_two(int **a, size_t count)
{
	size_t	first_greater_than;
	size_t	second_greater_than;
	char	*result;
	char	*temp;
	char	*sort_2_of_5;

	first_greater_than = range_count_of_g_t(a, a[0][0], 0, 4);
	second_greater_than = range_count_of_g_t(a, a[1][0], 1, 4);
	if (second_greater_than == 3)
		result = ft_strjoin("pa\n", "ra\n");
	if (second_greater_than == 0)
		result = ft_strdup("pa\n");
	if (second_greater_than == 1)
		result = ft_strjoin("pa\n", "sa\n");
	if (second_greater_than == 2)
		result = ft_strjoin("rra\npa\n", "ra\nra\n");
	temp = ft_strdup(result);
	sort_2_of_5 = last_sort(a, first_greater_than);
	result = ft_strjoin(temp, sort_2_of_5);
	free(temp);
	free(sort_2_of_5);
	return (result);
}

char	*sort_all(int **a, size_t count)
{
	char	*result;
	size_t	greater_than;

	if (count == 4)
	{
		greater_than = count_of_greater_than(a, a[0][0], count);
		if (greater_than == 3)
			result = ft_strjoin("pa\n", "ra\n");
		if (greater_than == 0)
			result = ft_strdup("pa\n");
		if (greater_than == 1)
			result = ft_strjoin("pa\n", "sa\n");
		if (greater_than == 2)
			result = ft_strjoin("rra\npa\n", "ra\nra\n");
	}
	if (count == 5)
	{
		result = sort_first_two(a, count);
	}
	return (result);
}

char	*sort_5(int **a, size_t count)
{
	char	*sort_3_result;
	char	*sort_all_result;
	char	*result;
	char	*temp;

	if (count == 4)
	{
		sort_3_result = sort_last_3(a, 1);
		result = ft_strjoin("pb\n", sort_3_result);
	}
	if (count == 5)
	{
		sort_3_result = sort_last_3(a, 2);
		result = ft_strjoin("pb\npb\n", sort_3_result);
	}
	temp = ft_strdup(result);
	sort_all_result = sort_all(a, count);
	result = ft_strjoin(temp, sort_all_result);
	free(temp);
	free(sort_all_result);
	return (result);
}
