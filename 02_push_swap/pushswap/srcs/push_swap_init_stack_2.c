/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_stack_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:49:55 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/18 19:50:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init_stack_b(t_dnode *b_head)
{
	b_head->key = KEY_B;
	b_head->prev = b_head;
	b_head->next = b_head;
}

void	ps_init_stack_oper(t_dnode *inst_head)
{
	inst_head->key = 0;
	inst_head->prev = inst_head;
	inst_head->next = inst_head;
}
