/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:24:10 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/05 18:37:32 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_dnode *a_head)
{
	t_dnode	*a_tomove;

	if (a_head->prev != a_head)
	{
		a_tomove = a_head->prev;
		a_head->prev = a_tomove->prev;
		a_tomove->prev->next = a_head;
		a_tomove->next = a_head->next;
		a_tomove->prev = a_head;
		a_tomove->next->prev = a_tomove;
		a_head->next = a_tomove;
	}
}

void	ps_rrb(t_dnode *b_head)
{
	t_dnode	*b_tomove;

	if (b_head->prev != b_head)
	{
		b_tomove = b_head->prev;
		b_head->prev = b_tomove->prev;
		b_tomove->prev->next = b_head;
		b_tomove->next = b_head->next;
		b_tomove->prev = b_head;
		b_tomove->next->prev = b_tomove;
		b_head->next = b_tomove;
	}
}

void	ps_rrr(t_dnode *a_head, t_dnode *b_head)
{
	ps_rra(a_head);
	ps_rrb(b_head);
}
