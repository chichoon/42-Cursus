/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:40:51 by jiychoi           #+#    #+#             */
/*   Updated: 2021/12/19 16:42:23 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[], char *envp[])
{
	char	*str[4] = {"cat", "-e", "asd", (char *)0};
	//argv[]로 넣어줄 인자값 배열
	//실제로 터미널에 입력해주는 인자값들은 str[1] 부터이므로 (argv와 같음)
	//cat 등을 할 때 플래그와 인자값은 str[1], str[2]에 넣어주었다
	//배열의 끝은 0으로 Null Terminate

	execve("/bin/cat", str, envp);
}
