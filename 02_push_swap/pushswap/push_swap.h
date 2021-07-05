/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:03:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/05 18:18:20 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h> ////////erase this!!!!!!!!!

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

# define IF_DUP 0
# define IF_ORDERED 1

/*
	** Push_Swap
*/
void	push_swap(t_dnode *a_head);

/*
	** Push_Swap: Initialize & validate stack A
*/
void	ps_init_stack_a(int argc, char *argv[], t_dnode *head);
void	ps_make_stack_a(int argc, char *argv[], t_dnode *a_head);
void	ps_validate_stack_a(t_dnode *a_head, t_dnode *b_head, int flag);

/*
	** Push_Swap: Initialize Sorted list and find Pivots
*/
int		ps_find_sorted_mid(t_dnode *dnode_head);

/*
	** Push_Swap: Command functions (sa, sb, ra, rb, pa, pb, rra, rrb)
*/
void	ps_sa(t_dnode *a_head);
void	ps_sb(t_dnode *b_head);
void	ps_ss(t_dnode *a_head, t_dnode *b_head);
void	ps_pa(t_dnode *a_head, t_dnode *b_head);
void	ps_pb(t_dnode *a_head, t_dnode *b_head);
void	ps_ra(t_dnode *a_head);
void	ps_rb(t_dnode *b_head);
void	ps_rr(t_dnode *a_head, t_dnode *b_head);
void	ps_rra(t_dnode *a_head);
void	ps_rrb(t_dnode *b_head);
void	ps_rrr(t_dnode *a_head, t_dnode *b_head);

/*
	** Push_Swap: function for double linked list (del, add, checker, find)
*/
t_dnode	*ps_lstadd_front(int key, t_dnode *dnode_next);
t_dnode	*ps_lstadd_back(int key, t_dnode *dnode_prev);
void	ps_lstdel(t_dnode *dnode_del);
void	ps_lstdel_all(t_dnode *dnode_head);
int		ps_lstlen(t_dnode *dnode_head);
int		ps_lstcheck_dup(t_dnode *dnode_head);
int		ps_lstcheck_order(t_dnode *dnode_head, t_dnode *dnode_tail);
void	ps_lstcheck_print(t_dnode *dnode_head);
t_dnode	*ps_lstfind_nth(t_dnode *dnode_head, int n);
t_dnode	*ps_lstfind_key(t_dnode *dnode_head, int key);

/*
	** Push_Swap: Utilities
*/
void	ps_print_and_exit(t_dnode *a_head, t_dnode *b_head, char *str);
void	ps_free_char2d(char **arr);

#endif
