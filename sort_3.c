/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:41:55 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 14:49:01 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sort_3(int **a, size_t count)
{
	if (count == 1)
		return ("\n");
	if (count == 2)
	{
		if (a[0][0] > a[1][0])
			return ("sa\n");
		else
			return ("\n");
	}
	if (a[0][0] < a[1][0] && a[1][0] < a[2][0])
		return ("\n");
	if (a[0][0] < a[1][0] && a[1][0] > a[2][0] && a[0][0] < a[2][0])
		return ("rra\nsa\n");
	if (a[0][0] > a[1][0] && a[1][0] < a[2][0] && a[0][0] < a[2][0])
		return ("sa\n");
	if (a[0][0] < a[1][0] && a[1][0] > a[2][0] && a[0][0] > a[2][0])
		return ("rra\n");
	if (a[0][0] > a[1][0] && a[1][0] < a[2][0] && a[0][0] > a[2][0])
		return ("ra\n");
	if (a[0][0] > a[1][0] && a[1][0] > a[2][0] && a[0][0] > a[2][0])
		return ("ra\nsa\n");
}
