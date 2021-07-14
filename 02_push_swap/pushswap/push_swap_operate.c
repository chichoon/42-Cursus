/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:24:35 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/14 16:19:03 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operate_a(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, int lstlen)
{
	t_dnode	*dnode_arr[2];
	int		num_oper_arr[3];

	num_oper_arr[OPERATION_R] = 0;
	num_oper_arr[OPERATION_P] = 0;
	num_oper_arr[OPERATION_INDEX] = -1;
	if (lstlen <= 2 || ps_lstcheck_order(a_head, a_head))
		return (ps_operate_two_a(a_head, b_head, inst_head, lstlen));
	dnode_arr[NODE_PIVOT] = ps_lstfind_key(a_head, ps_find_mid(a_head, lstlen));
	dnode_arr[NODE_TEMP] = a_head->next;
	while (++num_oper_arr[OPERATION_INDEX] < lstlen)
	{
		dnode_arr[NODE_TEMP] = dnode_arr[NODE_TEMP]->next;
		if (dnode_arr[NODE_TEMP]->prev->key > dnode_arr[NODE_PIVOT]->key)
			num_oper_arr[OPERATION_R] += ps_r(a_head, b_head, inst_head);
		else
			num_oper_arr[OPERATION_P] += ps_p(b_head, a_head, inst_head);
	}
	num_oper_arr[OPERATION_INDEX] = -1;
	while (++num_oper_arr[OPERATION_INDEX] < num_oper_arr[OPERATION_R])
		ps_rr(a_head, b_head, inst_head);
	ps_operate_a(a_head, b_head, inst_head, num_oper_arr[OPERATION_R]);
	ps_operate_b(b_head, a_head, inst_head, num_oper_arr[OPERATION_P]);
}

void	ps_operate_b(t_dnode *b_head, t_dnode *a_head,
			t_dnode *inst_head, int lstlen)
{
	t_dnode	*dnode_arr[2];
	int		num_oper_arr[3];

	num_oper_arr[OPERATION_P] = 0;
	num_oper_arr[OPERATION_R] = 0;
	num_oper_arr[OPERATION_INDEX] = -1;
	if (lstlen <= 2)
		return ((void) ps_operate_two_b(b_head, a_head, inst_head, lstlen));
	dnode_arr[NODE_PIVOT] = ps_lstfind_key(b_head, ps_find_mid(b_head, lstlen));
	dnode_arr[NODE_TEMP] = b_head->next;
	while (++num_oper_arr[OPERATION_INDEX] < lstlen)
	{
		dnode_arr[NODE_TEMP] = dnode_arr[NODE_TEMP]->next;
		if (dnode_arr[NODE_TEMP]->prev->key <= dnode_arr[NODE_PIVOT]->key)
			num_oper_arr[OPERATION_R] += ps_r(b_head, a_head, inst_head);
		else
			num_oper_arr[OPERATION_P] += ps_p(a_head, b_head, inst_head);
	}
	num_oper_arr[OPERATION_INDEX] = -1;
	while (++num_oper_arr[OPERATION_INDEX] < num_oper_arr[OPERATION_R])
		ps_rr(b_head, a_head, inst_head);
	ps_operate_a(a_head, b_head, inst_head, num_oper_arr[OPERATION_P]);
	ps_operate_b(b_head, a_head, inst_head, num_oper_arr[OPERATION_R]);
}

static void	ps_replace_inst(t_dnode **dnode_prev, t_dnode **dnode_next,
			int inst_num)
{
	t_dnode	*dnode_temp;

	if (inst_num)
	{
		ps_lstadd_front(inst_num, *dnode_prev);
		dnode_temp = (*dnode_prev)->prev;
		ps_lstdel(*dnode_prev);
		ps_lstdel(*dnode_next);
		*dnode_prev = dnode_temp;
		*dnode_next = dnode_temp->next;
	}
	else
	{
		dnode_temp = (*dnode_next)->next;
		ps_lstdel(*dnode_prev);
		ps_lstdel(*dnode_next);
		*dnode_prev = dnode_temp;
		*dnode_next = dnode_temp->next;
	}
}

void	ps_optimize_inst(t_dnode *inst_head)
{
	t_dnode	*dnode_prev;
	t_dnode	*dnode_next;

	dnode_prev = inst_head->next;
	while (dnode_prev != inst_head->prev)
	{
		dnode_next = dnode_prev->next;
		if (dnode_prev->key == CMD_SA && dnode_next->key == CMD_SB)
			ps_replace_inst(&dnode_prev, &dnode_next, CMD_SS);
		if (dnode_prev->key == CMD_RA && dnode_next->key == CMD_RB)
			ps_replace_inst(&dnode_prev, &dnode_next, CMD_RR);
		if (dnode_prev->key == CMD_RRA && dnode_next->key == CMD_RRB)
			ps_replace_inst(&dnode_prev, &dnode_next, CMD_RRR);
		if (dnode_prev->key == CMD_PA && dnode_next->key == CMD_PB)
			ps_replace_inst(&dnode_prev, &dnode_next, 0);
		dnode_prev = dnode_prev->next;
	}
}
