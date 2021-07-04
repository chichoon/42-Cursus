/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:42:43 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/03 13:46:20 by jiychoi          ###   ########.fr       */
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

void	ps_error_and_exit(t_dnode *a_head)
{
	if (a_head)
		ps_lstdel_all(a_head);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
