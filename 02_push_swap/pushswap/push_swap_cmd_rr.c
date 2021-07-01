/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:24:10 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/01 20:50:32 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_dnode *a_top, t_dnode *a_end)
{
	t_dnode	*a_tomove;

	if (a_end->prev != a_top)
	{
		a_tomove = a_end->prev;
		a_end->prev = a_tomove->prev;
		a_tomove->next = a_top->next;
		a_tomove->prev->next = a_end;
		a_tomove->prev = a_top;
		a_top->next->prev = a_tomove;
		a_top->next = a_tomove->prev;
	}
}

void	ps_rrb(t_dnode *b_top, t_dnode *b_end)
{
	t_dnode	*b_tomove;

	if (b_end->prev != b_top)
	{
		b_tomove = b_end->prev;
		b_end->prev = b_tomove->prev;
		b_tomove->next = b_top->next;
		b_tomove->prev->next = b_end;
		b_tomove->prev = b_top;
		b_top->next->prev = b_tomove;
		b_top->next = b_tomove->prev;
	}
}

void	ps_rrr(t_dnode *a_top, t_dnode *a_end, t_dnode *b_top, t_dnode *b_end)
{
	ps_rra(a_top, a_end);
	ps_rrb(b_top, b_end);
}
