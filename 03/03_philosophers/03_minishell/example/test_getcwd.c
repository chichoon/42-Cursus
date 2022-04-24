/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getcwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:08:41 by jiychoi           #+#    #+#             */
/*   Updated: 2021/10/07 13:08:53 by jiychoi          ###   ########.fr       */
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

	buf = malloc(sizeof(char) * 20); //넉넉치 못한 buffer, 넉넉치 못한 size
	ptr = getcwd(buf, 20); //에러 출력 (ERANGE)
	printf("20\n%s (%p) -> ptr %p\n\n", buf, buf, ptr);
	free(buf);

	buf = malloc(sizeof(char) * 100); //넉넉한 buffer, 넉넉치 못한 size
	ptr = getcwd(buf, 20); //에러 출력 (ERANGE)
	printf("100-20\n%s (%p) -> ptr %p\n\n", buf, buf, ptr);
	free(buf);

	buf = malloc(sizeof(char) * 20); //넉넉치 못한 buffer, 넉넉한 size
	ptr = getcwd(buf, 100); //힙 버퍼 오버플로우
	printf("20-100\n%s (%p) -> ptr %p\n\n", buf, buf, ptr);
	free(buf);

	buf = 0;
	ptr = getcwd(buf, 100);
	printf("NULL pointer\n%s (%p) -> ptr %p\n\n", ptr, buf, ptr);
	free(buf);
}
