/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:59:24 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/19 00:59:52 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ps_init_stack_b(t_dnode *b_head)
{
	b_head->key = KEY_B;
	b_head->prev = b_head;
	b_head->next = b_head;
}

static int	ps_exec_cmd(t_dnode *a_head, t_dnode *b_head, char *cmd)
{
	if (ps_compare_str(cmd, "sa"))
		ps_s(a_head);
	else if (ps_compare_str(cmd, "sb"))
		ps_s(b_head);
	else if (ps_compare_str(cmd, "pa"))
		ps_p(a_head, b_head);
	else if (ps_compare_str(cmd, "pb"))
		ps_p(b_head, a_head);
	else if (ps_compare_str(cmd, "ra"))
		ps_r(a_head);
	else if (ps_compare_str(cmd, "rb"))
		ps_r(b_head);
	else if (ps_compare_str(cmd, "rra"))
		ps_rr(a_head);
	else if (ps_compare_str(cmd, "rrb"))
		ps_rr(b_head);
	else if (ps_compare_str(cmd, "ss"))
		ps_ss(a_head, b_head);
	else if (ps_compare_str(cmd, "rr"))
		ps_rarb(a_head, b_head);
	else if (ps_compare_str(cmd, "rrr"))
		ps_rrr(a_head, b_head);
	else
		return (0);
	return (1);
}

static void	ps_sort(t_dnode *a_head, t_dnode *b_head)
{
	char	*cmd;

	while (get_next_line(STDIN_FILENO, &cmd) > 0)
	{
		if (!cmd || !ps_exec_cmd(a_head, b_head, cmd))
		{
			free(cmd);
			ps_print_and_exit(a_head, b_head, "Error");
		}
		free(cmd);
	}
	if (ps_lstcheck_order(a_head, ps_lstlen(a_head)))
		ps_print_and_exit(a_head, b_head, "OK");
	else
		ps_print_and_exit(a_head, b_head, "KO");
}

void	push_swap_checker(t_dnode *a_head)
{
	t_dnode	*b_head;

	b_head = (t_dnode *)malloc(sizeof(t_dnode));
	if (!b_head)
		ps_print_and_exit(a_head, 0, "Error");
	ps_init_stack_b(b_head);
	ps_sort(a_head, b_head);
}

int	main(int argc, char *argv[])
{
	t_dnode	*a_head;

	a_head = (t_dnode *)malloc(sizeof(t_dnode));
	if (!a_head)
		ps_print_and_exit(0, 0, "Error");
	if (argc > 1)
	{
		ps_init_stack_a(argc, argv, a_head);
		if (!ps_lstcheck_dup(a_head))
			ps_print_and_exit(a_head, 0, "Error");
		push_swap_checker(a_head);
	}
	return (0);
}
