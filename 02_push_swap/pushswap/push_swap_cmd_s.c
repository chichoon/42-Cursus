/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:34:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/05 17:48:04 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_dnode *a_head)
{
	t_dnode	*a_first;
	t_dnode	*a_second;

	if (a_head->next != a_head && a_head->next->next != a_head)
	{
		a_first = a_head->next;
		a_second = a_first->next;
		a_head->next = a_second;
		a_second->next->prev = a_first;
		a_first->prev = a_second;
		a_first->next = a_second->next;
		a_second->prev = a_head;
		a_second->next = a_first;
	}
}

void	ps_sb(t_dnode *b_head)
{
	t_dnode	*b_first;
	t_dnode	*b_second;

	if (b_head->next != b_head && b_head->next->next != b_head)
	{
		b_first = b_head->next;
		b_second = b_first->next;
		b_head->next = b_second;
		b_second->next->prev = b_first;
		b_first->prev = b_second;
		b_first->next = b_second->next;
		b_second->prev = b_head;
		b_second->next = b_first;
	}
}

void	ps_ss(t_dnode *a_head, t_dnode *b_head)
{
	ps_sa(a_head);
	ps_sb(b_head);
}
