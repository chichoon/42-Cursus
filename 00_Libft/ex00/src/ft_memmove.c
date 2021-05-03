/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:05:30 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 12:29:02 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, void *src, unsigned int count)
{
	void	*dst_backup;
	void	buf[count];
	int		n;

	n = 0;
	if (!dst || !src)
		return (0);
	while (n < count)
		buf[n++] = *src++;
	n = 0;
	while (n < count)
		*dst++ = buf[n++];
	return (dst_backup);
}
