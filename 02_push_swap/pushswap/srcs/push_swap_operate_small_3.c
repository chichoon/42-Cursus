/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate_small_3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:33:59 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/19 14:15:05 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_rs(t_dnode *head, t_dnode *head_other,
			t_dnode *inst_head, int flag)
{
	if (flag)
	{
		ps_r(head, head_other, inst_head);
		ps_r(head_other, head, inst_head);
		ps_s(head, head_other, inst_head);
		ps_s(head_other, head, inst_head);
	}
	else
	{
		ps_r(head, head_other, inst_head);
		ps_s(head, head_other, inst_head);
	}
}

static void	ps_oper_three_mid(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head)
{
	if ((a_head->next->next->key > a_head->next->next->next->key)
		&& (b_head->next->next->key < b_head->next->next->next->key))
	{
		if (ps_lstlen(a_head) != 3 && ps_lstlen(b_head) != 3)
			ps_rs(a_head, b_head, inst_head, 1);
		else if (ps_lstlen(a_head) != 3)
			ps_rs(a_head, b_head, inst_head, 0);
		else if (ps_lstlen(b_head) != 3)
			ps_rs(b_head, a_head, inst_head, 0);
		ps_rr(a_head, b_head, inst_head);
		ps_rr(b_head, a_head, inst_head);
	}
	else if (a_head->next->next->key > a_head->next->next->next->key)
	{
		if (ps_lstlen(a_head) != 3)
			ps_rs(a_head, b_head, inst_head, 0);
		ps_rr(a_head, b_head, inst_head);
	}
	else if (b_head->next->next->key < b_head->next->next->next->key)
	{
		if (ps_lstlen(b_head) != 3)
			ps_rs(b_head, a_head, inst_head, 0);
		ps_rr(b_head, a_head, inst_head);
	}
}

static void	ps_oper_three_ab(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head)
{
	if (a_head->next->key > a_head->next->next->key)
		ps_s(a_head, b_head, inst_head);
	if (b_head->next->key < b_head->next->next->key)
		ps_s(b_head, a_head, inst_head);
	ps_oper_three_mid(a_head, b_head, inst_head);
	if (a_head->next->key > a_head->next->next->key)
		ps_s(a_head, b_head, inst_head);
	if (b_head->next->key < b_head->next->next->key)
		ps_s(b_head, a_head, inst_head);
}

void	ps_operate_six_a(t_dnode *a_head, t_dnode *b_head, t_dnode *inst_head)
{
	t_dnode	*pivot;
	int		index;

	pivot = ps_lstfind_key(a_head, ps_find_mid(a_head, 6));
	index = -1;
	while (++index < 6)
	{
		if (a_head->next->key > pivot->key)
			ps_r(a_head, b_head, inst_head);
		else
			ps_p(b_head, a_head, inst_head);
	}
	if (ps_lstlen(a_head) != 3)
		ps_iterate_rr(a_head, b_head, inst_head, 3);
	ps_oper_three_ab(a_head, b_head, inst_head);
	ps_iterate_p(a_head, b_head, inst_head, 3);
}

void	ps_operate_six_b(t_dnode *b_head, t_dnode *a_head, t_dnode *inst_head)
{
	t_dnode	*pivot;
	int		index;

	pivot = ps_lstfind_key(b_head, ps_find_mid(b_head, 6));
	index = -1;
	while (++index < 6)
	{
		if (b_head->next->key <= pivot->key)
			ps_r(b_head, a_head, inst_head);
		else
			ps_p(a_head, b_head, inst_head);
	}
	if (ps_lstlen(b_head) != 3)
		ps_iterate_rr(b_head, a_head, inst_head, 3);
	ps_oper_three_ab(a_head, b_head, inst_head);
	ps_iterate_p(a_head, b_head, inst_head, 3);
}
