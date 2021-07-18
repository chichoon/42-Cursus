/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:42:43 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/18 02:00:46 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_char2d(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

void	ps_print_and_exit(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, char *str)
{
	if (a_head)
		ps_lstdel_all(a_head);
	if (b_head)
		ps_lstdel_all(b_head);
	if (inst_head)
		ps_lstdel_all(inst_head);
	if (str)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	exit(0);
}

void	ps_add_operation(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, int inst_code)
{
	t_dnode	*inst_next;

	inst_next = (t_dnode *)malloc(sizeof(t_dnode));
	if (!inst_next)
		ps_print_and_exit(a_head, b_head, 0, "Error");
	ps_lstadd_front(inst_code, inst_head);
}

void	ps_iterate_rr(t_dnode *head, t_dnode *head_other,
			t_dnode *inst_head, int iter)
{
	int	index;

	index = -1;
	while (++index < iter)
		ps_rr(head, head_other, inst_head);
}

void	ps_iterate_p(t_dnode *head_dst, t_dnode *head_src,
			t_dnode *inst_head, int iter)
{
	int	index;

	index = -1;
	while (++index < iter)
		ps_p(head_dst, head_src, inst_head);
}
