/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:24:35 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/18 18:02:34 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_lstcheck_rev_order(t_dnode *dnode_head, int length)
{
	t_dnode	*dnode_prev;
	t_dnode	*dnode_next;
	int		i;
	int		j;

	if (dnode_head->next == dnode_head)
		return (1);
	i = 0;
	dnode_prev = dnode_head->next;
	while (++i < length)
	{
		dnode_next = dnode_prev->next;
		j = i;
		while (j++ < length)
		{
			if (dnode_prev->key < dnode_next->key)
				return (0);
			dnode_next = dnode_next->next;
		}
		dnode_prev = dnode_prev->next;
	}
	return (1);
}

static void	ps_operation_a(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, int lstlen)
{
	t_dnode	*dnode_arr[2];
	int		num_oper_arr[3];

	num_oper_arr[OPERATION_R] = 0;
	num_oper_arr[OPERATION_P] = 0;
	num_oper_arr[OPERATION_INDEX] = -1;
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
	if (num_oper_arr[OPERATION_R] != ps_lstlen(a_head))
		ps_iterate_rr(a_head, b_head, inst_head, num_oper_arr[OPERATION_R]);
	ps_operate_a(a_head, b_head, inst_head, num_oper_arr[OPERATION_R]);
	ps_operate_b(b_head, a_head, inst_head, num_oper_arr[OPERATION_P]);
}

void	ps_operate_a(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, int lstlen)
{
	if (lstlen <= 2 || ps_lstcheck_order(a_head, ps_lstlen(a_head)))
		return (ps_operate_two_a(a_head, b_head, inst_head, lstlen));
	else if (lstlen == 3)
		return (ps_operate_three_a(a_head, b_head, inst_head));
	else if (lstlen == 4)
		return (ps_operate_four_a(a_head, b_head, inst_head));
	else if (lstlen == 5)
		return (ps_operate_five_a(a_head, b_head, inst_head));
	else if (lstlen == 6)
		return (ps_operate_six_a(a_head, b_head, inst_head));
	else
		return (ps_operation_a(a_head, b_head, inst_head, lstlen));
}

static void	ps_operation_b(t_dnode *b_head, t_dnode *a_head,
			t_dnode *inst_head, int lstlen)
{
	t_dnode	*dnode_arr[2];
	int		num_oper_arr[3];

	num_oper_arr[OPERATION_P] = 0;
	num_oper_arr[OPERATION_R] = 0;
	num_oper_arr[OPERATION_INDEX] = -1;
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
	if (num_oper_arr[OPERATION_R] != ps_lstlen(b_head))
		ps_iterate_rr(b_head, a_head, inst_head, num_oper_arr[OPERATION_R]);
	ps_operate_a(a_head, b_head, inst_head, num_oper_arr[OPERATION_P]);
	ps_operate_b(b_head, a_head, inst_head, num_oper_arr[OPERATION_R]);
}

void	ps_operate_b(t_dnode *b_head, t_dnode *a_head,
			t_dnode *inst_head, int lstlen)
{
	if (ps_lstcheck_rev_order(b_head, lstlen))
		return (ps_iterate_p(a_head, b_head, inst_head, lstlen));
	else if (lstlen <= 2)
		return (ps_operate_two_b(b_head, a_head, inst_head, lstlen));
	else if (lstlen == 3)
		return (ps_operate_three_b(b_head, a_head, inst_head));
	else if (lstlen == 4)
		return (ps_operate_four_b(b_head, a_head, inst_head));
	else if (lstlen == 5)
		return (ps_operate_five_b(b_head, a_head, inst_head));
	else if (lstlen == 6)
		return (ps_operate_six_b(b_head, a_head, inst_head));
	else
		return (ps_operation_b(b_head, a_head, inst_head, lstlen));
}
