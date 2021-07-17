/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:44:16 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/18 01:12:08 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_ss(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	if (head->next != head && head_other->next != head_other)
	{
		ps_s(head, head_other, inst_head);
		ps_s(head_other, head, inst_head);
		return (1);
	}
	return (0);
}

int	ps_rarb(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	if (head->next != head && head_other->next != head_other)
	{
		ps_r(head, head_other, inst_head);
		ps_r(head_other, head, inst_head);
		return (1);
	}
	return (0);
}

int	ps_rrr(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	if (head->next != head && head_other->next != head_other)
	{
		ps_rr(head, head_other, inst_head);
		ps_rr(head_other, head, inst_head);
		return (1);
	}
	return (0);
}
