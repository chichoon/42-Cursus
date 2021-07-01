/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:22:27 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/01 15:40:20 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_dnode *a_top, t_dnode *b_top, t_dnode *b_end)
{
	t_dnode	*b_tomove;

	if (b_top->next != b_end)
	{
		b_tomove = b_top->next;
		b_top->next = b_tomove->next;
		b_tomove->next->prev = b_top;
		b_tomove->next = a_top->next;
		a_top->next->prev = b_tomove;
		a_top->next = b_tomove;
		b_tomove->prev = a_top;
	}
}

void	ps_pb(t_dnode *a_top, t_dnode *a_end, t_dnode *b_top)
{
	t_dnode	*a_tomove;

	if (a_top->next != a_end)
	{
		a_tomove = a_top->next;
		a_top->next = a_top->next->next;
		a_top->next->next->prev = a_top;
		a_tomove->next = b_top->next;
		b_top->next->prev = a_tomove;
		b_top->next = a_tomove;
		a_tomove->prev = b_top;
	}
}
