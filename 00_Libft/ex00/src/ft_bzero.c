/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:14:56 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 11:55:41 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *ptr, unsigned int size)
{
	void	*ptr_backup;

	ptr_backup = ptr;
	if (!ptr_backup)
		return (0);
	while (size > 0)
	{
		*ptr++ = 0;
		size--;
	}
	return (ptr_backup);
}
