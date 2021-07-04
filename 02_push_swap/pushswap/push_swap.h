/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:03:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/03 18:14:27 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
#include <stdio.h> ////////erase this!!!!!!!!!

/*
	** Push_Swap: Structures
	** int key is for integer key to sort
	** char key is for instructions
	**		a : sa, b : sb, c : ss
	**		d : pa, e : pb
	**		f : ra, g : rb, h : rr
	**		i : rra, j : rrb, k : rrr
*/

typedef struct s_dnode
{
	int				key;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}				t_dnode;

typedef struct s_dnode_inst
{
	char				key;
	struct s_dnode_list	*prev;
	struct s_dnode_list	*next;
}				t_dnode_list;

/*
	** Push_Swap: Initialize list
*/
void	ps_init_stack(t_dnode *head, t_dnode *tail);
void	ps_make_list(int argc, char *argv[], t_dnode *a_head);
void	ps_validate_list(t_dnode *a_head, t_dnode *a_tail);

/*
	** Push_Swap: Command functions (sa, sb, ra, rb, pa, pb, rra, rrb)
*/
void	ps_sa(t_dnode *a_head, t_dnode *a_tail);
void	ps_sb(t_dnode *b_head, t_dnode *b_tail);
void	ps_ss(t_dnode *a_head, t_dnode *a_tail,
			t_dnode *b_head, t_dnode *b_tail);
void	ps_pa(t_dnode *a_head, t_dnode *b_head, t_dnode *b_tail);
void	ps_pb(t_dnode *a_head, t_dnode *a_tail, t_dnode *b_head);
void	ps_ra(t_dnode *a_head, t_dnode *a_tail);
void	ps_rb(t_dnode *b_head, t_dnode *b_tail);
void	ps_rr(t_dnode *a_head, t_dnode *a_tail,
			t_dnode *b_head, t_dnode *b_tail);
void	ps_rra(t_dnode *a_head, t_dnode *a_tail);
void	ps_rrb(t_dnode *b_head, t_dnode *b_tail);
void	ps_rrr(t_dnode *a_head, t_dnode *a_tail,
			t_dnode *b_head, t_dnode *b_tail);

/*
	** Push_Swap: function for double linked list (del, add)
*/
t_dnode	*ps_lstadd_front(int key, t_dnode *dnode_next);
t_dnode	*ps_lstadd_back(int key, t_dnode *dnode_prev);
void	ps_lstdel(t_dnode *dnode_del);
void	ps_lstdel_all(t_dnode *dnode_head);
int		ps_lstcheck_dup(t_dnode *dnode_head, t_dnode *dnode_tail);
int		ps_lstcheck_order(t_dnode *dnode_head, t_dnode *dnode_tail);
void	ps_lstcheck_print(t_dnode *dnode_head, t_dnode *dnode_tail);

/*
	** Push_Swap: Utilities
*/
void	ps_error_and_exit(t_dnode *a_head);
void	ps_free_char2d(char **arr);

#endif
