/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:34:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/01 14:07:52 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_dnode *a_top, t_dnode *a_end)
{
	t_dnode	*a_first;
	t_dnode	*a_second;

	if (a_top->next != a_end && a_top->next->next != a_end)
	{
		a_first = a_top->next;
		a_second = a_first->next;
		a_top->next = a_second;
		a_second->next->prev = a_first;
		a_first->prev = a_second;
		a_first->next = a_second->next;
		a_second->prev = a_top;
		a_second->next = a_first;
	}
}

void	ps_sb(t_dnode *b_top, t_dnode *b_end)
{
	t_dnode	*b_first;
	t_dnode	*b_second;

	if (b_top->next != b_end && b_top->next->next != b_end)
	{
		b_first = b_top->next;
		b_second = b_first->next;
		b_top->next = b_second;
		b_second->next->prev = b_first;
		b_first->prev = b_second;
		b_first->next = b_second->next;
		b_second->prev = b_top;
		b_second->next = b_first;
	}
}

void	ps_ss(t_dnode *a_top, t_dnode *a_end, t_dnode *b_top, t_dnode *b_end)
{
	ps_sa(a_top, a_end);
	ps_sb(b_top, b_end);
}
