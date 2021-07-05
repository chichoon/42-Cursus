/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linked_list_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:14:01 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/05 18:18:46 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_lstcheck_dup(t_dnode *dnode_head)
{
	t_dnode	*dnode_prev;
	t_dnode	*dnode_next;

	if (dnode_head->next == dnode_head)
		return (0);
	dnode_prev = dnode_head->next;
	while (dnode_prev != dnode_head->prev)
	{
		dnode_next = dnode_prev->next;
		while (dnode_next != dnode_head)
		{
			if (dnode_prev->key == dnode_next->key)
				return (0);
			dnode_next = dnode_next->next;
		}
		dnode_prev = dnode_prev->next;
	}
	return (1);
}

int	ps_lstcheck_order(t_dnode *dnode_head, t_dnode *dnode_tail)
{
	t_dnode	*dnode_prev;
	t_dnode	*dnode_next;

	if (dnode_head->next == dnode_tail)
		return (0);
	dnode_prev = dnode_head->next;
	while (dnode_prev != dnode_tail->prev)
	{
		dnode_next = dnode_prev->next;
		while (dnode_next != dnode_tail)
		{
			if (dnode_prev->key > dnode_next->key)
				return (0);
			dnode_next = dnode_next->next;
		}
		dnode_prev = dnode_prev->next;
	}
	return (1);
}

void	ps_lstcheck_print(t_dnode *dnode_head)
{
	t_dnode	*dnode_temp;

	if (dnode_head->next == dnode_head)
		return ;
	dnode_temp = dnode_head->next;
	while (dnode_temp != dnode_head)
	{
		ft_putnbr_fd(dnode_temp->key, 1);
		ft_putchar_fd(' ', 1);
		dnode_temp = dnode_temp->next;
	}
	ft_putchar_fd('\n', 1);
}

t_dnode	*ps_lstfind_nth(t_dnode *dnode_head, int n)
{
	t_dnode	*dnode_temp;
	int		index;

	index = 0;
	if (dnode_head->next == dnode_head)
		return ((t_dnode *)0);
	dnode_temp = dnode_head->next;
	while (dnode_temp != dnode_head)
	{
		if (index + 1 == n)
			return (dnode_temp);
		index++;
		dnode_temp = dnode_temp->next;
	}
	return ((t_dnode *)0);
}

t_dnode	*ps_lstfind_key(t_dnode *dnode_head, int key)
{
	t_dnode	*dnode_temp;

	if (dnode_head->next == dnode_head)
		return ((t_dnode *)0);
	dnode_temp = dnode_head->next;
	while (dnode_temp->next != 0)
	{
		if (dnode_temp->key == key)
			return (dnode_temp);
		dnode_temp = dnode_temp->next;
	}
	return ((t_dnode *)0);
}
