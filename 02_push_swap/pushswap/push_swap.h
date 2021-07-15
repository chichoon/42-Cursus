/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:03:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/16 01:53:41 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h> ////////erase this!!!!!!!!!

/*
	**	Push_Swap: Structures
	**	int key is for integer key to sort
	**	int key for instruction command code
	**		1 : sa, 2 : sb
	**		3 : pa, 4 : pb
	**		5 : ra, 6 : rb
	**		7 : rra, 8 : rrb
	**		11 : ss, 12 : rr, 13 : rrr
	**	if key of head is 0 : Stack A
	**	if key of head is 1 : Stack B
*/

typedef struct s_dnode
{
	int				key;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}				t_dnode;

# define KEY_A 0
# define KEY_B 1
# define CMD_SA 1
# define CMD_SB 2
# define CMD_PA 3
# define CMD_PB 4
# define CMD_RA 5
# define CMD_RB 6
# define CMD_RRA 7
# define CMD_RRB 8
# define CMD_SS 11
# define CMD_RR 12
# define CMD_RRR 13
# define OPERATION_P 0
# define OPERATION_R 1
# define OPERATION_INDEX 2
# define NODE_PIVOT 0
# define NODE_TEMP 1

/*
	** Push_Swap (find pivot & quick sort);
*/
void	push_swap(t_dnode *a_head);
int		ps_find_mid(t_dnode *dnode_head, int length);
void	ps_sort(t_dnode *a_head, t_dnode *b_head, t_dnode *inst_head);
void	ps_operate_a(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, int lstlen);
void	ps_operate_b(t_dnode *b_head, t_dnode *a_head,
			t_dnode *inst_head, int lstlen);

/*
	** Push_Swap: Optimization
	** (Sort for 2, 3, 4, 5 nodes & optimize instruction)
*/
void	ps_operate_two_a(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, int lstlen);
void	ps_operate_two_b(t_dnode *b_head, t_dnode *a_head,
			t_dnode *inst_head, int lstlen);
void	ps_operate_three_a(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head);
void	ps_operate_three_b(t_dnode *b_head, t_dnode *a_head,
			t_dnode *inst_head);
void	ps_operate_four_a(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head);
void	ps_operate_four_b(t_dnode *b_head, t_dnode *a_head,
			t_dnode *inst_head);
void	ps_operate_five_a(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head);
void	ps_operate_five_b(t_dnode *b_head, t_dnode *a_head,
			t_dnode *inst_head);
void	ps_optimize_inst(t_dnode *inst_head);

/*
	** Push_Swap: Initialize & validate stack A
*/
void	ps_init_stack_a(int argc, char *argv[], t_dnode *head);
void	ps_make_stack_a(int argc, char *argv[], t_dnode *a_head);
void	ps_init_stack_b(t_dnode *b_head);
void	ps_init_stack_oper(t_dnode *inst_head);

/*
	** Push_Swap: Command functions (sa, sb, ra, rb, pa, pb, rra, rrb)
*/
int		ps_p(t_dnode *head_dst, t_dnode *head_src, t_dnode *inst_head);
int		ps_s(t_dnode *head, t_dnode *head_other, t_dnode *inst_head);
int		ps_r(t_dnode *head, t_dnode *head_other, t_dnode *inst_head);
int		ps_rr(t_dnode *head, t_dnode *head_other, t_dnode *inst_head);

/*
	** Push_Swap: function for double linked list (del, add, checker, find)
*/
t_dnode	*ps_lstadd_front(int key, t_dnode *dnode_next);
t_dnode	*ps_lstadd_back(int key, t_dnode *dnode_prev);
void	ps_lstdel(t_dnode *dnode_del);
void	ps_lstdel_all(t_dnode *dnode_head);
int		ps_lstlen(t_dnode *dnode_head);
int		ps_lstcheck_dup(t_dnode *dnode_head);
int		ps_lstcheck_order(t_dnode *dnode_head, int length);
void	ps_lstcheck_print(t_dnode *dnode_head);
t_dnode	*ps_lstfind_nth(t_dnode *dnode_head, int n);
t_dnode	*ps_lstfind_key(t_dnode *dnode_head, int key);

/*
	** Push_Swap: Utilities
*/
void	ps_print_and_exit(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, char *str);
void	ps_free_char2d(char **arr);
void	ps_add_operation(t_dnode *a_head, t_dnode *b_head,
			t_dnode *inst_head, int inst_code);
void	ps_iterate_rr(t_dnode *head, t_dnode *head_other,
			t_dnode *inst_head, int iter);
void	ps_iterate_p(t_dnode *head_dst, t_dnode *head_src,
			t_dnode *inst_head, int iter);

#endif
