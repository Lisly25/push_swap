/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:49:26 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/04 09:55:19 by skorbai          ###   ########.fr       */
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

char	*sort_all(int **a, size_t count)
{
	char	*result;
	char	*temp;

	if (count == 4)
	{
		if (a[0][0] > a[1][0] && a[0][0] > a[2][0] && a[0][0] > a[3][0])
			result = ft_strjoin("pa\n", "ra\n");
	}
	if (count == 5)
	{
		
	}
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
	return (result);
}
