/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:59:24 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/10 13:41:44 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(t_dnode *a_head, t_dnode *b_head, t_dnode *inst_head)
{
	if (ps_lstlen(a_head, a_head) == 2)
		ps_operate_two(a_head, b_head, inst_head);
	else if (ps_lstlen(a_head, a_head) == 3)
		ps_operate_three(a_head, b_head, inst_head);
	else
		ps_operate_a(a_head, a_head, b_head, inst_head);
	ps_lstcheck_print(a_head);
	ps_lstcheck_print(b_head);
}

void	push_swap(t_dnode *a_head)
{
	t_dnode	*b_head;
	t_dnode	*inst_head;

	if (ps_lstcheck_order(a_head, a_head))
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
