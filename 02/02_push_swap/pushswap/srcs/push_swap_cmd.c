/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:01:56 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/13 21:13:58 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_p(t_dnode *head_dst, t_dnode *head_src, t_dnode *inst_head)
{
	t_dnode	*tomove;

	if (head_src->next != head_src)
	{
		tomove = head_src->next;
		head_src->next = tomove->next;
		tomove->next->prev = head_src;
		tomove->next = head_dst->next;
		head_dst->next->prev = tomove;
		head_dst->next = tomove;
		tomove->prev = head_dst;
		if (head_dst->key == KEY_A)
			ps_add_operation(head_dst, head_src, inst_head, CMD_PA);
		else if (head_dst->key == KEY_B)
			ps_add_operation(head_dst, head_src, inst_head, CMD_PB);
		return (1);
	}
	return (0);
}

int	ps_s(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	t_dnode	*first;
	t_dnode	*second;

	if (head->next != head && head->next->next != head)
	{
		first = head->next;
		second = first->next;
		head->next = second;
		second->next->prev = first;
		first->prev = second;
		first->next = second->next;
		second->prev = head;
		second->next = first;
		if (head->key == KEY_A)
			ps_add_operation(head, head_other, inst_head, CMD_SA);
		else if (head->key == KEY_B)
			ps_add_operation(head, head_other, inst_head, CMD_SB);
		return (1);
	}
	return (0);
}

int	ps_r(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	t_dnode	*tomove;

	if (head->next != head)
	{
		tomove = head->next;
		head->next = tomove->next;
		tomove->next->prev = head;
		tomove->prev = head->prev;
		tomove->next = head;
		tomove->prev->next = tomove;
		head->prev = tomove;
		if (head->key == KEY_A)
			ps_add_operation(head, head_other, inst_head, CMD_RA);
		else if (head->key == KEY_B)
			ps_add_operation(head, head_other, inst_head, CMD_RB);
		return (1);
	}
	return (0);
}

int	ps_rr(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	t_dnode	*tomove;

	if (head->prev != head)
	{
		tomove = head->prev;
		head->prev = tomove->prev;
		tomove->prev->next = head;
		tomove->next = head->next;
		tomove->prev = head;
		tomove->next->prev = tomove;
		head->next = tomove;
		if (head->key == KEY_A)
			ps_add_operation(head, head_other, inst_head, CMD_RRA);
		else if (head->key == KEY_B)
			ps_add_operation(head, head_other, inst_head, CMD_RRB);
		return (1);
	}
	return (0);
}
