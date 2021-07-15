/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:59:24 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/16 01:18:56 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_putinst(t_dnode *dnode)
{
	if (dnode->key == CMD_SA)
		ft_putstr_fd("sa", 1);
	else if (dnode->key == CMD_SB)
		ft_putstr_fd("sb", 1);
	else if (dnode->key == CMD_SS)
		ft_putstr_fd("ss", 1);
	else if (dnode->key == CMD_PA)
		ft_putstr_fd("pa", 1);
	else if (dnode->key == CMD_PB)
		ft_putstr_fd("pb", 1);
	else if (dnode->key == CMD_RA)
		ft_putstr_fd("ra", 1);
	else if (dnode->key == CMD_RB)
		ft_putstr_fd("rb", 1);
	else if (dnode->key == CMD_RR)
		ft_putstr_fd("rr", 1);
	else if (dnode->key == CMD_RRA)
		ft_putstr_fd("rra", 1);
	else if (dnode->key == CMD_RRB)
		ft_putstr_fd("rrb", 1);
	else if (dnode->key == CMD_RRR)
		ft_putstr_fd("rrr", 1);
}

void	ps_print_inst(t_dnode *inst_head)
{
	t_dnode	*dnode_temp;

	dnode_temp = inst_head->next;
	while (dnode_temp != inst_head)
	{
		ps_putinst(dnode_temp);
		ft_putchar_fd('\n', 1);
		dnode_temp = dnode_temp->next;
	}
}

void	ps_sort(t_dnode *a_head, t_dnode *b_head, t_dnode *inst_head)
{
	int	lstlen;

	lstlen = ps_lstlen(a_head);
	if (lstlen == 2)
		ps_operate_two_a(a_head, b_head, inst_head, lstlen);
	else if (lstlen == 3)
		ps_operate_three_a(a_head, b_head, inst_head);
	else if (lstlen == 5)
		ps_operate_five_a(a_head, b_head, inst_head);
	else
		ps_operate_a(a_head, b_head, inst_head, lstlen);
	ps_optimize_inst(inst_head);
	ps_print_inst(inst_head);
}

void	push_swap(t_dnode *a_head)
{
	t_dnode	*b_head;
	t_dnode	*inst_head;

	if (ps_lstcheck_order(a_head, ps_lstlen(a_head)))
		ps_print_and_exit(a_head, 0, 0, "OK");
	b_head = (t_dnode *)malloc(sizeof(t_dnode));
	if (!b_head)
		ps_print_and_exit(a_head, 0, 0, "Error");
	inst_head = (t_dnode *)malloc(sizeof(t_dnode));
	if (!inst_head)
		ps_print_and_exit(a_head, b_head, 0, "Error");
	ps_init_stack_b(b_head);
	ps_init_stack_oper(inst_head);
	ps_sort(a_head, b_head, inst_head);
}

int	main(int argc, char *argv[])
{
	t_dnode	*a_head;

	a_head = (t_dnode *)malloc(sizeof(t_dnode));
	if (!a_head)
		ps_print_and_exit(0, 0, 0, "Error");
	if (argc > 1)
	{
		ps_init_stack_a(argc, argv, a_head);
		ps_validate_stack_a(a_head, 0, 0, IF_DUP);
		push_swap(a_head);
	}
	return (0);
}
