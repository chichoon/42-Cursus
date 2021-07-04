/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linked_list_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:14:01 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/03 14:29:49 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_lstcheck_dup(t_dnode *dnode_head, t_dnode *dnode_tail)
{
	t_dnode	*dnode_prev;
	t_dnode	*dnode_next;

	if (dnode_head->next == dnode_tail || dnode_head->next->next == dnode_tail)
		return (0);
	dnode_prev = dnode_head->next;
	while (dnode_prev != dnode_tail->prev)
	{
		dnode_next = dnode_prev->next;
		while (dnode_next != dnode_tail)
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

	if (dnode_head->next == dnode_tail || dnode_head->next->next == dnode_tail)
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

void	ps_lstcheck_print(t_dnode *dnode_head, t_dnode *dnode_tail)
{
	t_dnode	*dnode_temp;

	if (dnode_head->next == dnode_tail || dnode_head->next->next == dnode_tail)
		return ;
	dnode_temp = dnode_head->next;
	while (dnode_temp != dnode_tail)
	{
		ft_putnbr_fd(dnode_temp->key, 1);
		ft_putchar_fd('\n', 1);
		dnode_temp = dnode_temp->next;
	}
}
