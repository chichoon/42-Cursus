/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:34:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/03 13:57:00 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_dnode *a_head, t_dnode *a_tail)
{
	t_dnode	*a_first;
	t_dnode	*a_second;

	if (a_head->next != a_tail && a_head->next->next != a_tail)
	{
		a_first = a_head->next;
		a_second = a_first->next;
		a_head->next = a_second;
		a_second->next->prev = a_first;
		a_first->prev = a_second;
		a_first->next = a_second->next;
		a_second->prev = a_head;
		a_second->next = a_first;
	}
}

void	ps_sb(t_dnode *b_head, t_dnode *b_tail)
{
	t_dnode	*b_first;
	t_dnode	*b_second;

	if (b_head->next != b_tail && b_head->next->next != b_tail)
	{
		b_first = b_head->next;
		b_second = b_first->next;
		b_head->next = b_second;
		b_second->next->prev = b_first;
		b_first->prev = b_second;
		b_first->next = b_second->next;
		b_second->prev = b_head;
		b_second->next = b_first;
	}
}

void	ps_ss(t_dnode *a_head, t_dnode *a_tail,
		t_dnode *b_head, t_dnode *b_tail)
{
	ps_sa(a_head, a_tail);
	ps_sb(b_head, b_tail);
}
