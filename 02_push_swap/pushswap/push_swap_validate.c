/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:22:57 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/01 21:25:25 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	ps_if_in_arr(int n, int arr_num, int *arr)
{
	int i;

	i = 0;
	while (i < arr_num)
	{
		if (n == arr[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ps_if_number(char *str)
{
	char	i;

	while (*str)
	{
		i = '0';
		while (i <= '9')
		{
			if (str == i)
				break;
			i++;
		}
		if (i == '9' + 1)
			return (0);
		str++;
	}
	return (1);
}

int	*ps_validate_arg(int argc, char *argv)
{
	int	index_argv;
	int	index_numarr;
	int	*temp_num;

	index_argv = 1;
	index_numarr = 0;
	temp_num = (int *)malloc(sizeof(int) * (argc - 1));
	while (index_argv < argc)
	{
		if (!ps_if_number(argv[index_argv])
			|| ps_if_in_arr(ft_atoi(argv[index_argv]), index_numarr, temp_num))
		{
			ft_putstr_fd("Error\n", 1);
			free(temp_num);
			exit();
		}
		temp_num[index_numarr++] = ft_atoi(argv[index_argv++]);
	}
	return (temp_num);
}
