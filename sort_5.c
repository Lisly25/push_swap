/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:49:26 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/04 09:06:20 by skorbai          ###   ########.fr       */
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
}

char	*sort_5(int **a, size_t count)
{
	char	*sort_3_result;

	if (count == 4)
		sort_3_result = sort_last_3(a, 1);
	if (count == 5)
		sort_3_result = sort_last_3(a, 2);
	return ("Nothing for now\n");
}
