/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:48:33 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/04 15:56:12 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr_lst;
	t_list	*next_lst;

	if (!*lst)
		return ;
	curr_lst = *lst;
	next_lst = curr_lst->next;
	while (curr_lst)
	{
		del(curr_lst->content);
		free(curr_lst);
		curr_lst = next_lst;
		if (next_lst)
			next_lst = next_lst->next;
	}
	*lst = 0;
}
