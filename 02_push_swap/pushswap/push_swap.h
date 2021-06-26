/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:03:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/26 15:49:57 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>


typedef struct	s_dnode
{
	int key;
	struct s_dnode *prev;
	struct s_dnode *next;
}				t_dnode;

#endif
