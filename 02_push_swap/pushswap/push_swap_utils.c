/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:42:43 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/05 17:04:45 by jiychoi          ###   ########.fr       */
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

void	ps_print_and_exit(t_dnode *a_head, t_dnode *b_head, char *str)
{
	if (a_head)
		ps_lstdel_all(a_head);
	if (b_head)
		ps_lstdel_all(b_head);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
}
