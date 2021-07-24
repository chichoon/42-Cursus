/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate_small_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:28:58 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/19 14:16:47 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operate_four_a(t_dnode *a_head, t_dnode *b_head, t_dnode *inst_head)
{
	t_dnode	*pivot;
	int		index;

	pivot = ps_lstfind_key(a_head, ps_find_mid(a_head, 4));
	index = -1;
	while (++index < 4)
	{
		if (a_head->next->key > pivot->key)
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
	int		index;

	pivot = ps_lstfind_key(b_head, ps_find_mid(b_head, 4));
	index = -1;
	while (++index < 4)
	{
		if (b_head->next->key <= pivot->key)
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
	int		index;

	pivot = ps_lstfind_key(a_head, ps_find_mid(a_head, 5));
	index = -1;
	while (++index < 5)
	{
		if (a_head->next->key > pivot->key)
			ps_r(a_head, b_head, inst_head);
		else
			ps_p(b_head, a_head, inst_head);
	}
	if (ps_lstlen(a_head) != 2)
		ps_iterate_rr(a_head, b_head, inst_head, 2);
	ps_operate_two_a(a_head, b_head, inst_head, 2);
	ps_operate_three_b(b_head, a_head, inst_head);
}

static void	ps_oper_five_b(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, int lstlen)
{
	if (lstlen == 1 || ps_lstlen(b_head) == 1)
		ps_p(a_head, b_head, inst_head);
	else
		if (b_head->next->key < b_head->next->next->key)
			ps_s(b_head, a_head, inst_head);
	ps_operate_three_a(a_head, b_head, inst_head);
	ps_iterate_p(a_head, b_head, inst_head, 2);
}

void	ps_operate_five_b(t_dnode *b_head, t_dnode *a_head, t_dnode *inst_head)
{
	t_dnode	*pivot;
	int		index;

	pivot = ps_lstfind_key(b_head, ps_find_mid(b_head, 5));
	index = -1;
	while (++index < 5)
	{
		if (b_head->next->key < pivot->key)
			ps_r(b_head, a_head, inst_head);
		else
			ps_p(a_head, b_head, inst_head);
	}
	if (ps_lstlen(b_head) != 2)
		ps_iterate_rr(b_head, a_head, inst_head, 2);
	ps_oper_five_b(a_head, b_head, inst_head, 2);
}
