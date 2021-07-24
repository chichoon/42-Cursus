/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:59:55 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/19 00:39:45 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ps_ss(t_dnode *head, t_dnode *head_other)
{
	ps_s(head);
	ps_s(head_other);
}

void	ps_rarb(t_dnode *head, t_dnode *head_other)
{
	ps_r(head);
	ps_r(head_other);
}

void	ps_rrr(t_dnode *head, t_dnode *head_other)
{
	ps_rr(head);
	ps_rr(head_other);
}
