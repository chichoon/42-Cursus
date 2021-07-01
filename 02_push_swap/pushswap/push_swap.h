/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:03:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/01 17:14:12 by jiychoi          ###   ########.fr       */
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
	** Push_Swap: Command functions (sa, sb, ra, rb, pa, pb, rra, rrb)
*/
void	ps_sa(t_dnode *a_top, t_dnode *a_end);
void	ps_sb(t_dnode *b_top, t_dnode *b_end);
void	ps_ss(t_dnode *a_top, t_dnode *a_end, t_dnode *b_top, t_dnode *b_end);
void	ps_pa(t_dnode *a_top, t_dnode *b_top, t_dnode *b_end);
void	ps_pb(t_dnode *a_top, t_dnode *a_end, t_dnode *b_top);
void	ps_ra(t_dnode *a_top, t_dnode *a_end);
void	ps_rb(t_dnode *b_top, t_dnode *b_end);
void	ps_rr(t_dnode *a_top, t_dnode *a_end, t_dnode *b_top, t_dnode *b_end);



/*
	** Push_Swap: function for double linked list (del, add)
*/
t_dnode	*ps_lstadd_front(int key, t_dnode *dnode_next);
t_dnode	*ps_lstadd_back(int key, t_dnode *dnode_prev);
void	ps_lstdel(t_dnode *dnode_del);
void	ps_lstdel_all(t_dnode *dnode_start);

#endif
