/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linked_list_1_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:03:18 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/18 23:02:23 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ps_lstdel(t_dnode *dnode_del)
{
	t_dnode	*dnode_prev;
	t_dnode	*dnode_next;

	dnode_prev = dnode_del->prev;
	dnode_next = dnode_del->next;
	dnode_prev->next = dnode_next;
	dnode_next->prev = dnode_prev;
	free(dnode_del);
}

void	ps_lstdel_all(t_dnode *dnode_head)
{
	t_dnode	*dnode_to_delete;
	t_dnode	*dnode_next;

	dnode_to_delete = dnode_head->next;
	while (dnode_to_delete->next != dnode_head)
	{
		dnode_next = dnode_to_delete->next;
		free(dnode_to_delete);
		dnode_to_delete = dnode_next;
	}
	if (dnode_to_delete == dnode_head)
		free(dnode_head);
}

int	ps_lstlen(t_dnode *dnode_head)
{
	int		length;
	t_dnode	*dnode_temp;

	length = 0;
	dnode_temp = dnode_head->next;
	while (dnode_temp != dnode_head)
	{
		length++;
		dnode_temp = dnode_temp->next;
	}
	return (length);
}
