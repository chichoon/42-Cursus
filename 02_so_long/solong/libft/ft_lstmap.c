/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:05:44 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/14 13:33:16 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_recur_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list *curr_lst;
	t_list *new_lst;

	curr_lst = lst;
	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (0);
	if (lst->next)
	{
		new_lst->content = f(curr_lst->content);
		new_lst->next = ft_lstmap(lst->next, f, d);
		if (!new_lst->next)
		{
			ft_lstdelone(new_lst, d);
			return (0);
		}
	}
	else
	{
		new_lst->content = f(curr_lst->content);
		new_lst->next = 0;
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*new_lst;

	if (!lst)
		return (0);
	new_lst = ft_recur_lstmap(lst, f, d);
	return (new_lst);
}
