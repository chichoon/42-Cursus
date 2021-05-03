/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:53:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 12:01:55 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned int num)
{
	void *dst_backup;

	dst_backup = dst;
	if (!dst || !src)
		return (0);
	else
	{
		while (num)
		{
			*dst++ = *src++;
			num--;
		}
	}
	return (dst_backup);
}
