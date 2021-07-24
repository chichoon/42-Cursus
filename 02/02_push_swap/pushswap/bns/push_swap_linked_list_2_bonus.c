/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linked_list_2_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:14:01 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/18 23:08:32 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ps_lstcheck_order(t_dnode *dnode_head, int length)
{
	t_dnode	*dnode_prev;
	t_dnode	*dnode_next;
	int		i;
	int		j;

	if (dnode_head->next == dnode_head)
		return (1);
	i = 0;
	dnode_prev = dnode_head->next;
	while (++i < length)
	{
		dnode_next = dnode_prev->next;
		j = i;
		while (j++ < length)
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
