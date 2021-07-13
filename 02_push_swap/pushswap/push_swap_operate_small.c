/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate_small.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:30:36 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/13 15:37:20 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operate_two(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	ps_s(head, head_other, inst_head);
}

void	ps_operate_three(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	if (head->next->key > head->next->next->key)
		ps_s(head, head_other, inst_head);
	if (head->next->next->key > head->next->next->next->key)
		ps_rr(head, head_other, inst_head);
	if (head->next->key > head->next->next->key)
		ps_s(head, head_other, inst_head);
}
