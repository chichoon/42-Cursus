/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optimize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:54:51 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/16 01:17:28 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dnode	*ps_replace_inst(t_dnode *dnode_prev, t_dnode *dnode_next,
			int inst_num)
{
	t_dnode	*dnode_temp;

	if (inst_num)
		ps_lstadd_back(inst_num, dnode_next);
	dnode_temp = dnode_next->next;
	ps_lstdel(dnode_prev);
	ps_lstdel(dnode_next);
	return (dnode_temp->prev);
}

void	ps_optimize_inst(t_dnode *inst_head)
{
	t_dnode	*dnode_prev;
	t_dnode	*dnode_next;

	dnode_prev = inst_head->next;
	while (dnode_prev != inst_head->prev)
	{
		dnode_next = dnode_prev->next;
		if ((dnode_prev->key == CMD_SA && dnode_next->key == CMD_SB)
			|| (dnode_prev->key == CMD_SB && dnode_next->key == CMD_SA))
			dnode_prev = ps_replace_inst(dnode_prev, dnode_next, CMD_SS);
		else if ((dnode_prev->key == CMD_RA && dnode_next->key == CMD_RB)
			|| (dnode_prev->key == CMD_RB && dnode_next->key == CMD_RA))
			dnode_prev = ps_replace_inst(dnode_prev, dnode_next, CMD_RR);
		else if ((dnode_prev->key == CMD_RRA && dnode_next->key == CMD_RRB)
			|| (dnode_prev->key == CMD_RRB && dnode_next->key == CMD_RRA))
			dnode_prev = ps_replace_inst(dnode_prev, dnode_next, CMD_RRR);
		else if ((dnode_prev->key == CMD_PA && dnode_next->key == CMD_PB)
			|| (dnode_prev->key == CMD_PB && dnode_next->key == CMD_PA)
			|| (dnode_prev->key == CMD_RA && dnode_next->key == CMD_RRA)
			|| (dnode_prev->key == CMD_RB && dnode_next->key == CMD_RRB)
			|| (dnode_prev->key == CMD_RRA && dnode_next->key == CMD_RA)
			|| (dnode_prev->key == CMD_RRB && dnode_next->key == CMD_RB))
			dnode_prev = ps_replace_inst(dnode_prev, dnode_next, 0);
		dnode_prev = dnode_prev->next;
	}
}
