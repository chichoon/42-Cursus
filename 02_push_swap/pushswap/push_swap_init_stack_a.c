/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_stack_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:14:25 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/05 18:21:50 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_if_number(char *str, char *str_to_compare)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (str_to_compare[i])
		{
			if (*str == str_to_compare[i])
				break ;
			i++;
		}
		if (!str_to_compare[i])
			return (0);
		str++;
	}
	return (1);
}

void	ps_make_stack_a(int argc, char *argv[], t_dnode *a_head)
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
				&& ps_if_number(str_temp[index_split], "0123456789-+"))
			{
				ps_lstadd_back(ft_atoi(str_temp[index_split]), dnode_now);
				dnode_now = dnode_now->next;
			}
		}
		ps_free_char2d(str_temp);
	}
}

void	ps_init_stack_a(int argc, char *argv[], t_dnode *head)
{
	head->key = 0;
	head->prev = head;
	head->next = head;
	ps_make_stack_a(argc, argv, head);
}

void	ps_validate_stack_a(t_dnode *a_head, t_dnode *b_head, int flag)
{
	if (flag == IF_DUP)
		if (!ps_lstcheck_dup(a_head))
			ps_print_and_exit(a_head, b_head, "Error");
	if (flag == IF_ORDERED)
	{
		if (!ps_lstcheck_order(a_head, a_head))
			ps_print_and_exit(a_head, b_head, "KO");
		ps_print_and_exit(a_head, b_head, "OK");
	}
}
