/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:07:34 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/04 15:09:28 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*curr_lst;

	length = 0;
	curr_lst = lst;
	while (curr_lst)
	{
		curr_lst = curr_lst->next;
		length++;
	}
	return (length);
}
