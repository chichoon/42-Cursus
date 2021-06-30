/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:34:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/01 00:24:28 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_dnode *ps_top_a, t_dnode *ps_end_a)
{
	if (ps_top_a->next != ps_end_a && ps_top_a->next->next != ps_end_a)
	{
		ps_lstmove_front(ps_top_a->next->next, ps_top_a->next);
	}
}

void	ps_sb(t_dnode *ps_top_a, t_dnode *ps_end_b)
{
	ps_lstmove_front(ps_top_b->next, ps_top_a->next);
}
