/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:30:36 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/12 13:25:13 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operate_two(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	ps_s(head);
	if (!head->key)
		ps_add_operation(head, head_other, inst_head, 1);
	else
		ps_add_operation(head, head_other, inst_head, 2);
}

void	ps_operate_three(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	if (head->next->key > head->next->next->key)
	{
		ps_s(head);
		if (!head->key)
			ps_add_operation(head, head_other, inst_head, 1);
		else
			ps_add_operation(head, head_other, inst_head, 2);
	}
	if (head->next->next->key > head->next->next->next->key)
	{
		ps_rr(head);
		if (!head->key)
			ps_add_operation(head, head_other, inst_head, 7);
		else
			ps_add_operation(head, head_other, inst_head, 8);
	}
	if (head->next->key > head->next->next->key)
	{
		ps_s(head);
		if (!head->key)
			ps_add_operation(head, head_other, inst_head, 1);
		else
			ps_add_operation(head, head_other, inst_head, 2);
	}
}
