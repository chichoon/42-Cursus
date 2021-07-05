/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:59:24 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/05 18:40:46 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	push_swap_exec_cmd

void	push_swap(t_dnode *a_head)
{
	t_dnode	*b_head;

	b_head = (t_dnode *)malloc(sizeof(t_dnode));
	if (!b_head)
		ps_print_and_exit(a_head, 0, "Error");
	b_head->key = 0;
	b_head->prev = b_head;
	b_head->next = b_head;
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
		ps_validate_stack_a(a_head, 0, IF_DUP);
		push_swap(a_head);
	}
	return (0);
}
