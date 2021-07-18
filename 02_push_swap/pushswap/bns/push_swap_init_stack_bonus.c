/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_stack_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:14:25 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/19 00:05:00 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static int	is_space(char str)
{
	if (str == ' ' || (str >= 9 && str <= 13))
		return (1);
	else
		return (0);
}

static void	ps_init_a_head(t_dnode *a_head)
{
	a_head->key = KEY_A;
	a_head->prev = a_head;
	a_head->next = a_head;
}

static void	ps_check_overflow(t_dnode *a_head, char *str, char **str_to_free)
{
	unsigned long long	absol;

	absol = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
		absol = absol * 10 + (*str++ - '0');
	if (absol >= 2147483648)
	{
		ps_free_char2d(str_to_free);
		ps_print_and_exit(a_head, 0, "Error");
	}
}

void	ps_init_stack_a(int argc, char *argv[], t_dnode *a_head)
{
	int		index_argc;
	int		index_split;
	t_dnode	*dnode_now;
	char	**str_temp;

	ps_init_a_head(a_head);
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
				ps_check_overflow(a_head, str_temp[index_split], str_temp);
				ps_lstadd_back(ft_atoi(str_temp[index_split]), dnode_now);
				dnode_now = dnode_now->next;
			}
		}
		ps_free_char2d(str_temp);
	}
}
