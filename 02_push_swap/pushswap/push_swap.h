/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:03:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:36:33 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_dnode
{
	int				key;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}				t_dnode;

/*
	** Push_Swap: function for double linked list (del, add, move)
*/
t_dnode	*ps_lstadd_front(int key, t_dnode *dnode_next);
t_dnode	*ps_lstadd_back(int key, t_dnode *dnode_prev);
void	ps_lstmove_front(t_dnode *dnode_tomove, t_dnode *dnode_next);
void	ps_lstmove_back(t_dnode *dnode_tomove, t_dnode *dnode_prev);
void	ps_lstdel(t_dnode *dnode_del);
void	ps_lstdel_all(t_dnode *dnode_start);

#endif
