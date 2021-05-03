/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:41:19 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 11:55:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, unsigned int num)
{
	void	*ptr_backup;

	ptr_backup = ptr;
	if (!ptr_backup)
		return (0);
	while (num > 0)
	{
		*ptr++ = value;
		num--;
	}
	return (ptr_backup);
}
