/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:01:56 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/06 14:05:30 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_r(t_dnode *head)
{
	t_dnode	*tomove;

	if (head->next != head)
	{
		tomove = head->next;
		head->next = tomove->next;
		tomove->next->prev = head;
		tomove->prev = head->prev;
		tomove->next = head;
		tomove->prev->next = tomove;
		head->prev = tomove;
	}
}

void	ps_p(t_dnode *head_dst, t_dnode *head_src)
{
	t_dnode	*tomove;

	if (head_src->next != head_src)
	{
		tomove = head_src->next;
		head_src->next = tomove->next;
		tomove->next->prev = head_src;
		tomove->next = head_dst->next;
		head_dst->next->prev = tomove;
		head_dst->next = tomove;
		tomove->prev = head_dst;
	}
}

void	ps_rr(t_dnode *head)
{
	t_dnode	*tomove;

	if (head->prev != head)
	{
		tomove = head->prev;
		head->prev = tomove->prev;
		tomove->prev->next = head;
		tomove->next = head->next;
		tomove->prev = head;
		tomove->next->prev = tomove;
		head->next = tomove;
	}
}

void	ps_s(t_dnode *head)
{
	t_dnode	*first;
	t_dnode	*second;

	if (head->next != head && head->next->next != head)
	{
		first = head->next;
		second = first->next;
		head->next = second;
		second->next->prev = first;
		first->prev = second;
		first->next = second->next;
		second->prev = head;
		second->next = first;
	}
}
