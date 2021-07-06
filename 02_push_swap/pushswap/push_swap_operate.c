/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:30:36 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/06 14:24:55 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_quick_sort(t_dnode *head, t_dnode *tail, t_dnode *head_other)
{
	int		pivot_key;
	int		len;
	t_dnode	*pivot;
	t_dnode	*dnode_temp;

	pivot_key = ps_find_sorted_mid(head, tail);
	pivot = ps_lstfind_key(head, pivot_key);
	dnode_temp = head->next;
	len = ps_lstlen(head, tail);
	printf("pivot : %d\n", pivot_key);
	while (len > 0)
	{
		printf("dnode : %d\n", dnode_temp->key);
		if (dnode_temp->key > pivot_key)
		{
			dnode_temp = dnode_temp->next;
			ps_p(head_other, head);
			if (head_other->key)
				printf("pb\n");
			else
				printf("pa\n");
		}
		else
		{
			dnode_temp = dnode_temp->next;
			ps_r(head);
			if (head->key)
				printf("ra\n");
			else
				printf("rb\n");
		}
		len--;
	}
	ps_lstcheck_print(head);
	ps_lstcheck_print(head_other);
}
