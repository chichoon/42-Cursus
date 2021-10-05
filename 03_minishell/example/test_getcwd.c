/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getcwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:08:41 by jiychoi           #+#    #+#             */
/*   Updated: 2021/10/05 08:22:03 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*buf;
	char	*ptr;

	buf = malloc(sizeof(char) * 100);
	ptr = getcwd(buf, 100);
	printf("100\n%s (%p) -> ptr %p\n\n", buf, buf, ptr);
	free(buf);
	buf = malloc(sizeof(char) * 20);
	ptr = getcwd(buf, 20);
	printf("20\n%s (%p) -> ptr %p\n\n", buf, buf, ptr);
	free(buf);
	buf = malloc(sizeof(char) * 100);
	ptr = getcwd(buf, 20);
	printf("100-20\n%s (%p) -> ptr %p\n\n", buf, buf, ptr);
	free(buf);
	buf = malloc(sizeof(char) * 20);
	ptr = getcwd(buf, 100);
	printf("20-100\n%s (%p) -> ptr %p\n\n", buf, buf, ptr);
	free(buf);
	buf = 0;
	ptr = getcwd(buf, 100);
	printf("20-100\n%s (%p) -> ptr %p\n\n", ptr, buf, ptr);
	free(buf);
}
