/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:59:24 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/03 14:30:47 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_swap()
// {
// 	//
// }

void	ps_init_stack(t_dnode *head, t_dnode *tail)
{
	head->key = 0;
	tail->key = 0;
	head->prev = 0;
	head->next = tail;
	tail->prev = head;
}

int	main(int argc, char *argv[])
{
	t_dnode	*a_head;
	t_dnode	*a_tail;

	a_head = (t_dnode *)malloc(sizeof(t_dnode));
	a_tail = (t_dnode *)malloc(sizeof(t_dnode));
	if (!a_head || !a_tail)
		ps_error_and_exit(0);
	if (argc > 1)
	{
		ps_init_stack(a_head, a_tail);
		ps_make_list(argc, argv, a_head);
		ps_validate_list(a_head, a_tail);
		//push_swap();
	}
	return (0);
}
