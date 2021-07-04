/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:14:25 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/03 14:25:21 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_if_number(char *str)
{
	char	i;

	while (*str)
	{
		i = '0';
		while (i <= '9')
		{
			if (*str == i)
				break ;
			i++;
		}
		if (i == '9' + 1)
			return (0);
		str++;
	}
	return (1);
}

void	ps_make_list(int argc, char *argv[], t_dnode *a_head)
{
	int		index_argc;
	int		index_split;
	t_dnode	*dnode_now;
	char	**str_temp;

	index_argc = 0;
	dnode_now = a_head;
	while (++index_argc < argc)
	{
		index_split = -1;
		str_temp = ft_split(argv[index_argc], ' ');
		while (str_temp[++index_split])
		{
			if (ft_strlen(str_temp[index_split]) > 0
				&& ps_if_number(str_temp[index_split]))
			{
				ps_lstadd_back(ft_atoi(str_temp[index_split]), dnode_now);
				dnode_now = dnode_now->next;
			}
		}
		ps_free_char2d(str_temp);
	}
}

void	ps_validate_list(t_dnode *a_head, t_dnode *a_tail)
{
	if (!ps_lstcheck_dup(a_head, a_tail))
		ps_error_and_exit(a_head);
	ps_lstcheck_print(a_head, a_tail);
}
