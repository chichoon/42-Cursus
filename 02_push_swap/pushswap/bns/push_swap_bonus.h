/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:03:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/19 00:58:35 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_dnode
{
	int				key;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}				t_dnode;

# define KEY_A 0
# define KEY_B 1

/*
	** Push_Swap_bonus (Checker: To check if sorted)
*/
void	push_swap_checker(t_dnode *a_head);

/*
	** Push_Swap: Initialize & validate stack A
*/
void	ps_init_stack_a(int argc, char *argv[], t_dnode *head);
void	ps_make_stack_a(int argc, char *argv[], t_dnode *a_head);
void	ps_init_stack_b(t_dnode *b_head);

/*
	** Push_Swap: Command functions (sa, sb, ra, rb, pa, pb, rra, rrb)
*/
void	ps_p(t_dnode *head_dst, t_dnode *head_src);
void	ps_s(t_dnode *head);
void	ps_r(t_dnode *head);
void	ps_rr(t_dnode *head);
void	ps_ss(t_dnode *head, t_dnode *head_other);
void	ps_rarb(t_dnode *head, t_dnode *head_other);
void	ps_rrr(t_dnode *head, t_dnode *head_other);

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

/*
	** Push_Swap: Utilities
*/
void	ps_print_and_exit(t_dnode *a_head, t_dnode *b_head, char *str);
void	ps_free_char2d(char **arr);
int		ps_compare_str(char *str1, char *str2);

#endif
