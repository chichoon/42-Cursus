/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:24:10 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/03 13:56:56 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_dnode *a_head, t_dnode *a_tail)
{
	t_dnode	*a_tomove;

	if (a_tail->prev != a_head)
	{
		a_tomove = a_tail->prev;
		a_tail->prev = a_tomove->prev;
		a_tomove->next = a_head->next;
		a_tomove->prev->next = a_tail;
		a_tomove->prev = a_head;
		a_head->next->prev = a_tomove;
		a_head->next = a_tomove->prev;
	}
}

void	ps_rrb(t_dnode *b_head, t_dnode *b_tail)
{
	t_dnode	*b_tomove;

	if (b_tail->prev != b_head)
	{
		b_tomove = b_tail->prev;
		b_tail->prev = b_tomove->prev;
		b_tomove->next = b_head->next;
		b_tomove->prev->next = b_tail;
		b_tomove->prev = b_head;
		b_head->next->prev = b_tomove;
		b_head->next = b_tomove->prev;
	}
}

void	ps_rrr(t_dnode *a_head, t_dnode *a_tail,
		t_dnode *b_head, t_dnode *b_tail)
{
	ps_rra(a_head, a_tail);
	ps_rrb(b_head, b_tail);
}
