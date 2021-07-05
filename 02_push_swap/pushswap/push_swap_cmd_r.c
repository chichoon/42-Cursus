/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:43:08 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/05 18:37:23 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_dnode *a_head)
{
	t_dnode	*a_tomove;

	if (a_head->next != a_head)
	{
		a_tomove = a_head->next;
		a_head->next = a_tomove->next;
		a_tomove->next->prev = a_head;
		a_tomove->prev = a_head->prev;
		a_tomove->next = a_head;
		a_tomove->prev->next = a_tomove;
		a_head->prev = a_tomove;
	}
}

void	ps_rb(t_dnode *b_head)
{
	t_dnode	*b_tomove;

	if (b_head->next != b_head)
	{
		b_tomove = b_head->next;
		b_head->next = b_tomove->next;
		b_tomove->next->prev = b_head;
		b_tomove->prev = b_head->prev;
		b_tomove->next = b_head;
		b_tomove->prev->next = b_tomove;
		b_head->prev = b_tomove;
	}
}

void	ps_rr(t_dnode *a_head, t_dnode *b_head)
{
	ps_ra(a_head);
	ps_rb(b_head);
}
