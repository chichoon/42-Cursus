/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linked_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:03:18 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/26 22:37:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dnode	*ps_lstadd_front(int key, t_dnode *dnode_next)
{
	t_dnode	*node;

	node = (t_dnode *)malloc(sizeof(t_dnode));
	if (!node)
		return (0);
	node->key = key;
	if (dnode_next->prev == 0)
	{
		node->prev = 0;
		dnode_next->prev = node;
		node->next = dnode_next;
	}
	else
	{
		dnode_next->prev->next = node;
		node->prev = dnode_next->prev;
		dnode_next->prev = node;
		node->next = dnode_next;
	}
	return (node);
}

void	ps_lstmove_front(t_dnode *dnode_tomove, t_dnode *dnode_next)
{
	if (dnode_next->prev == 0)
	{
		dnode_tomove->prev = 0;
		dnode_next->prev = dnode_tomove;
		dnode_tomove->next = dnode_next;
	}
	else
	{
		dnode_next->prev->next = dnode_tomove;
		dnode_tomove->prev = dnode_next->prev;
		dnode_next->prev = dnode_tomove;
		dnode_tomove->next = dnode_next;
	}
}

t_dnode	*ps_lstadd_back(int key, t_dnode *dnode_prev)
{
	t_dnode	*node;

	node = (t_dnode *)malloc(sizeof(t_dnode));
	if (!node)
		return (0);
	node->key = key;
	if (dnode_prev->next == 0)
	{
		node->prev = dnode_prev;
		node->next = 0;
		dnode_prev->next = node;
	}
	else
	{
		dnode_prev->next->prev = node;
		node->prev = dnode_prev;
		node->next = dnode_prev->next;
		dnode_prev->next = node;
	}
	return (node);
}

void	ps_lstmove_back(t_dnode *dnode_tomove, t_dnode *dnode_prev)
{
	if (dnode_prev->next == 0)
	{
		dnode_tomove->prev = dnode_prev;
		dnode_tomove->next = 0;
		dnode_prev->next = dnode_tomove;
	}
	else
	{
		dnode_prev->next->prev = dnode_tomove;
		dnode_tomove->prev = dnode_prev;
		dnode_tomove->next = dnode_prev->next;
		dnode_prev->next = dnode_tomove;
	}
}

void	ps_lstdel(t_dnode *dnode_del)
{
	if (dnode_del->prev == 0 && dnode_del->next == 0)
		free(dnode_del);
	else if (dnode_del->prev == 0 && dnode_del->next != 0)
	{
		dnode_del->prev->next = dnode_del->next;
		dnode_del->next->prev = 0;
		free(dnode_del);
	}
	else if (dnode_del->prev != 0 && dnode_del->next == 0)
	{
		dnode_del->prev->next = 0;
		dnode_del->next->prev = dnode_del->prev;
		free(dnode_del);
	}
	else
	{
		dnode_del->prev->next = dnode_del->next;
		dnode_del->next->prev = dnode_del->prev;
		free(dnode_del);
	}
}

void	ps_lstdel_all(t_dnode *dnode_start)
{
	t_dnode	*dnode_next;

	if (dnode_start->next == 0)
		free(dnode_start);
	else
	{
		dnode_next = dnode_start->next;
		free(dnode_start);
		ps_lstdell_all(dnode_next);
	}
}
