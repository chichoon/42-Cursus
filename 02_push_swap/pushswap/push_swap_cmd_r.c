/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:43:08 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/01 15:51:05 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_dnode *a_top, t_dnode *a_end)
{
	t_dnode	*a_tomove;

	if (a_top->next != a_end)
	{
		a_tomove = a_top->next;
		a_top->next = a_tomove->next;
		a_tomove->prev = a_end->prev;
		a_tomove->next = a_end;
		a_end->prev = a_tomove->next;
	}
}

void	ps_rb(t_dnode *b_top, t_dnode *b_end)
{
	t_dnode	*b_tomove;

	if (b_top->next != b_end)
	{
		b_tomove = b_top->next;
		b_top->next = b_tomove->next;
		b_tomove->prev = b_end->prev;
		b_tomove->next = b_end;
		b_end->prev = b_tomove->next;
	}
}

void	ps_rr(t_dnode *a_top, t_dnode *a_end, t_dnode *b_top, t_dnode *b_end)
{
	ps_ra(a_top, a_end);
	ps_rb(b_top, b_end);
}
