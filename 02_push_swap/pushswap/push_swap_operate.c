/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:30:36 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/10 13:46:45 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operate_two(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	ps_s(head);
	if (!head->key)
		ps_add_operation(head, head_other, inst_head, 1);
	else
		ps_add_operation(head, head_other, inst_head, 2);
}

void	ps_operate_three(t_dnode *head, t_dnode *head_other, t_dnode *inst_head)
{
	if (head->next->key > head->next->next->key)
	{
		ps_s(head);
		if (!head->key)
			ps_add_operation(head, head_other, inst_head, 1);
		else
			ps_add_operation(head, head_other, inst_head, 2);
	}
	if (head->next->next->key > head->next->next->next->key)
	{
		ps_rr(head);
		if (!head->key)
			ps_add_operation(head, head_other, inst_head, 7);
		else
			ps_add_operation(head, head_other, inst_head, 8);
	}
	if (head->next->key > head->next->next->key)
	{
		ps_s(head);
		if (!head->key)
			ps_add_operation(head, head_other, inst_head, 1);
		else
			ps_add_operation(head, head_other, inst_head, 2);
	}
}

static void	ps_operate(t_dnode *head, t_dnode *head_other,
			t_dnode *inst_head, int length)
{
	t_dnode	*pivot;
	t_dnode	*dnode_temp;

	pivot = ps_lstfind_key(head, ps_find_sorted_mid(head, length));
	dnode_temp = head->next;
	while (--length > -1)
	{
		dnode_temp = dnode_temp->next;
		if (dnode_temp->prev->key < pivot->key)
		{
			ps_p(head_other, head);
			if (!head->key)
				ps_add_operation(head, head_other, inst_head, 3);
			else
				ps_add_operation(head, head_other, inst_head, 4);
		}
		else
		{
			ps_r(head);
			if (head->key)
				ps_add_operation(head, head_other, inst_head, 5);
			else
				ps_add_operation(head, head_other, inst_head, 6);
		}
	}
}

void	ps_operate_a(t_dnode *a_head, t_dnode *a_tail,
			t_dnode *b_head, t_dnode *inst_head)
{
	int	length;

	length = ps_lstlen(a_head, a_tail);
	printf("---now operate a: %p %p, length: %d\n", a_head, a_tail, length);
	ps_lstcheck_print(a_head);
	ps_lstcheck_print(b_head);
	if (length < 2 || ps_lstcheck_order(a_head, a_tail))
		return ;
	if (length == 2)
		ps_operate_two(a_head, b_head, inst_head);
	else
	{
		ps_operate(a_head, b_head, inst_head, length);
		ps_operate_b(b_head, ps_lstfind_nth(b_head, length / 2 + 1),
			a_head, inst_head);
		printf("Command : %d\n", ps_lstlen(inst_head, inst_head));
	}
}

void	ps_operate_b(t_dnode *b_head, t_dnode *b_tail,
			t_dnode *a_head, t_dnode *inst_head)
{
	int	length;

	length = ps_lstlen(b_head, b_tail);
	printf("---now operate b: %p %p, length: %d\n", b_head, b_tail, length);
	ps_lstcheck_print(a_head);
	ps_lstcheck_print(b_head);
	if (length < 2 || ps_lstcheck_order(b_head, b_tail))
		return ;
	if (length == 2)
		ps_operate_two(b_head, a_head, inst_head);
	else
	{
		ps_operate(b_head, a_head, inst_head, length);
		ps_operate_a(a_head, ps_lstfind_nth(a_head, length / 2 + 1),
			b_head, inst_head);
		printf("Command : %d\n", ps_lstlen(inst_head, inst_head));
	}
}
