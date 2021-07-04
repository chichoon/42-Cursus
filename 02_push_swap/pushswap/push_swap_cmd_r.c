/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:43:08 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/03 13:56:50 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_dnode *a_head, t_dnode *a_tail)
{
	t_dnode	*a_tomove;

	if (a_head->next != a_tail)
	{
		a_tomove = a_head->next;
		a_head->next = a_tomove->next;
		a_tomove->prev = a_tail->prev;
		a_tomove->next->prev = a_head;
		a_tomove->next = a_tail;
		a_tail->prev->next = a_tomove;
		a_tail->prev = a_tomove->next;
	}
}

void	ps_rb(t_dnode *b_head, t_dnode *b_tail)
{
	t_dnode	*b_tomove;

	if (b_head->next != b_tail)
	{
		b_tomove = b_head->next;
		b_head->next = b_tomove->next;
		b_tomove->prev = b_tail->prev;
		b_tomove->next->prev = b_head;
		b_tomove->next = b_tail;
		b_tail->prev->next = b_tomove;
		b_tail->prev = b_tomove->next;
	}
}

void	ps_rr(t_dnode *a_head, t_dnode *a_tail,
		t_dnode *b_head, t_dnode *b_tail)
{
	ps_ra(a_head, a_tail);
	ps_rb(b_head, b_tail);
}
