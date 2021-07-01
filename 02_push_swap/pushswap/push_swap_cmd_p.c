/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:22:27 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/01 14:13:32 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_dnode *a_top, t_dnode *a_end, t_dnode *b_top)
{
	t_dnode *a_tomove;

	if (a_top->next != a_end)
	{
		a_tomove = a_top->next;
		a_top->next = a_top->next->next;
		a_top->next->next->prev = a_top;
		a_tomove->next = b_top->next->next;
		b_top->next->next->prev = a_tomove;
		b_top->next = a_tomove;
		a_tomove->prev = b_top;
	}

}

void	ps_pb(t_dnode *ps_top_a, t_dnode *ps_top_b)
{
	ps_lstmove_front(ps_top_b->next, ps_top_a->next);
}
