/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate_small_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:28:58 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/16 00:13:25 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operate_four_a(t_dnode *a_head, t_dnode *b_head, t_dnode *inst_head)
{
	t_dnode	*pivot;
	t_dnode	*dnode_temp;
	int		index;

	pivot = ps_lstfind_key(a_head, ps_find_mid(a_head, 4));
	dnode_temp = a_head->next;
	index = -1;
	while (++index < 4)
	{
		dnode_temp = dnode_temp->next;
		if (dnode_temp->prev->key > pivot->key)
			ps_r(a_head, b_head, inst_head);
		else
			ps_p(b_head, a_head, inst_head);
	}
	if (ps_lstlen(a_head) != 2)
		ps_iterate_rr(a_head, b_head, inst_head, 2);
	ps_operate_two_a(a_head, b_head, inst_head, 2);
	ps_operate_two_b(b_head, a_head, inst_head, 2);
}

void	ps_operate_four_b(t_dnode *b_head, t_dnode *a_head, t_dnode *inst_head)
{
	t_dnode	*pivot;
	t_dnode	*dnode_temp;
	int		index;

	pivot = ps_lstfind_key(b_head, ps_find_mid(b_head, 4));
	dnode_temp = b_head->next;
	index = -1;
	while (++index < 4)
	{
		dnode_temp = dnode_temp->next;
		if (dnode_temp->prev->key <= pivot->key)
			ps_r(b_head, a_head, inst_head);
		else
			ps_p(a_head, b_head, inst_head);
	}
	if (ps_lstlen(b_head) != 2)
		ps_iterate_rr(b_head, a_head, inst_head, 2);
	ps_operate_two_a(a_head, b_head, inst_head, 2);
	ps_operate_two_b(b_head, a_head, inst_head, 2);
}

void	ps_operate_five_a(t_dnode *a_head, t_dnode *b_head, t_dnode *inst_head)
{
	t_dnode	*pivot;
	t_dnode	*dnode_temp;
	int		index;

	pivot = ps_lstfind_key(a_head, ps_find_mid(a_head, 5));
	dnode_temp = a_head->next;
	index = -1;
	while (++index < 5)
	{
		dnode_temp = dnode_temp->next;
		if (dnode_temp->prev->key > pivot->key)
			ps_r(a_head, b_head, inst_head);
		else
			ps_p(b_head, a_head, inst_head);
	}
	if (ps_lstlen(a_head) != 2)
		ps_iterate_rr(a_head, b_head, inst_head, 2);
	ps_operate_two_a(a_head, b_head, inst_head, 2);
	ps_operate_three_b(b_head, a_head, inst_head);
}

void	ps_operate_five_b(t_dnode *b_head, t_dnode *a_head, t_dnode *inst_head)
{
	t_dnode	*pivot;
	t_dnode	*dnode_temp;
	int		index;

	pivot = ps_lstfind_key(b_head, ps_find_mid(b_head, 5));
	dnode_temp = b_head->next;
	index = -1;
	while (++index < 5)
	{
		dnode_temp = dnode_temp->next;
		if (dnode_temp->prev->key < pivot->key)
			ps_r(b_head, a_head, inst_head);
		else
			ps_p(a_head, b_head, inst_head);
	}
	if (ps_lstlen(b_head) != 2)
		ps_iterate_rr(b_head, a_head, inst_head, 2);
	ps_operate_three_a(a_head, b_head, inst_head);
	ps_operate_two_b(b_head, a_head, inst_head, 2);
}
