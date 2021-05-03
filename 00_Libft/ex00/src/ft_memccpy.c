/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:01:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 12:05:15 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, unsigned int n)
{
	void *dst_backup;

	dst_backup = dst;
	while (n)
	{
		if (*src == c)
			return (dst_backup);
		*dst++ = *src++;
	}
	return (0);
}
