/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate_small.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:30:36 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/14 20:25:33 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operate_two_a(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, int lstlen)
{
	if (ps_lstcheck_order(a_head, a_head))
		return ;
	if (lstlen == 2)
		if (a_head->next->key > a_head->next->next->key)
			ps_s(a_head, b_head, inst_head);
}

void	ps_operate_two_b(t_dnode *b_head, t_dnode *a_head,
			t_dnode *inst_head, int lstlen)
{
	if (lstlen == 1)
		ps_p(a_head, b_head, inst_head);
	else
	{
		if (b_head->next->key < b_head->next->next->key)
			ps_s(b_head, a_head, inst_head);
		ps_p(a_head, b_head, inst_head);
		ps_p(a_head, b_head, inst_head);
	}
}

void	ps_operate_three(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	if (head->next->key > head->next->next->key)
		ps_s(head, head_other, inst_head);
	if (head->next->next->key > head->next->next->next->key)
		ps_rr(head, head_other, inst_head);
	if (head->next->key > head->next->next->key)
		ps_s(head, head_other, inst_head);
}

void	ps_operate_three_b(t_dnode *b_head, t_dnode *a_head, t_dnode *inst_head)
{
	if (ps_lstlen(b_head) == 3)
		ps_operate_three(b_head, a_head, inst_head);
	else
	{
		if (b_head->next->key < b_head->next->next->key)
			ps_s(b_head, a_head, inst_head);
		if (b_head->next->next->key < b_head->next->next->next->key)
		{
			ps_r(b_head, a_head, inst_head);
			ps_s(b_head, a_head, inst_head);
			ps_rr(b_head, a_head, inst_head);
		}
		if (b_head->next->key < b_head->next->next->key)
			ps_s(b_head, a_head, inst_head);
	}
}
