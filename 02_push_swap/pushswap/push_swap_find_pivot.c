/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_find_pivot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:58:11 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/13 17:30:27 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_find_sorted_mid(int *num_arr, int length)
{
	int	index_i;
	int	index_j;
	int	num_temp;
	int	num_to_return;

	index_i = -1;
	while (++index_i + 1 < length)
	{
		index_j = index_i;
		while (++index_j < length)
		{
			if (num_arr[index_i] > num_arr[index_j])
			{
				num_temp = num_arr[index_j];
				num_arr[index_j] = num_arr[index_i];
				num_arr[index_i] = num_temp;
			}
		}
	}
	num_to_return = num_arr[length / 2 - !(length % 2)];
	free(num_arr);
	return (num_to_return);
}

int	ps_find_mid(t_dnode *dnode_head, int length)
{
	int		*num_arr;
	int		index;
	t_dnode	*dnode_temp;
	int		length_temp;

	num_arr = (int *)malloc(sizeof(int) * length);
	index = 0;
	dnode_temp = dnode_head->next;
	length_temp = length;
	while (length_temp > 0)
	{
		num_arr[index++] = dnode_temp->key;
		dnode_temp = dnode_temp->next;
		length_temp--;
	}
	return (ps_find_sorted_mid(num_arr, length));
}
