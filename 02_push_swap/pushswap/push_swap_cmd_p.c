/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:22:27 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/03 13:48:04 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_dnode *a_head, t_dnode *b_head, t_dnode *b_tail)
{
	t_dnode	*b_tomove;

	if (b_head->next != b_tail)
	{
		b_tomove = b_head->next;
		b_head->next = b_tomove->next;
		b_tomove->next->prev = b_head;
		b_tomove->next = a_head->next;
		a_head->next->prev = b_tomove;
		a_head->next = b_tomove;
		b_tomove->prev = a_head;
	}
}

void	ps_pb(t_dnode *a_head, t_dnode *a_tail, t_dnode *b_head)
{
	t_dnode	*a_tomove;

	if (a_head->next != a_tail)
	{
		a_tomove = a_head->next;
		a_head->next = a_head->next->next;
		a_head->next->next->prev = a_head;
		a_tomove->next = b_head->next;
		b_head->next->prev = a_tomove;
		b_head->next = a_tomove;
		a_tomove->prev = b_head;
	}
}
