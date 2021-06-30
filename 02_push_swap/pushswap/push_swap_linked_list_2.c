/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linked_list_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:37:11 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:46:40 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
