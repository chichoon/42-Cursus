/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:22:27 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/01 00:22:36 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_dnode *ps_top_a, t_dnode *ps_top_b)
{
	ps_lstmove_front(ps_top_a->next, ps_top_b->next);
}

void	ps_pb(t_dnode *ps_top_a, t_dnode *ps_top_b)
{
	ps_lstmove_front(ps_top_b->next, ps_top_a->next);
}
