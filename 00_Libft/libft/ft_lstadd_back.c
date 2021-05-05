/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:10:52 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/04 15:16:11 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr_lst;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr_lst = *lst;
	while (curr_lst->next)
		curr_lst = curr_lst->next;
	curr_lst->next = new;
}
