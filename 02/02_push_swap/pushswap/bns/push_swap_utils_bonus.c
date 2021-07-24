/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:42:43 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/19 17:22:04 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	if (str)
	{
		if (ps_compare_str(str, "Error"))
			ft_putstr_fd(str, 2);
		else
			ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	exit(0);
}

int	ps_compare_str(char *str1, char *str2)
{
	int	index;

	index = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (str1[index])
	{
		if (str1[index] != str2[index])
			return (0);
		index++;
	}
	return (1);
}
