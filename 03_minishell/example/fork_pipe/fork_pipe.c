/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:45:39 by jiychoi           #+#    #+#             */
/*   Updated: 2021/10/08 13:44:08 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_pipe.h"

char	**pipe_getpath(char *envp[])
{
	int		i;
	char	**path;

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path = ft_split(envp[i], ':');
			break ;
		}
	}
	i = -1;
	while (path[++i])
		printf("%s\n", path[i]);
	return (path);
}

void	pipe_parent(int fd)
{
	char	buf[100];

	printf("this is parent process %d\n", getpid());
	read(fd, buf, 100);
	printf("%s\n", buf);
}

void	pipe_child(int fd)
{
	printf("this is child process %d\n", getpid());
	write(fd, "Hello World!!!\n", 15);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	pipe_getpath(envp);
	printf("%d\n", getpid());
	if (pipe(fd) < 0)
		return (0);
	pid = fork();
	if (pid)
		pipe_parent(fd[0]);
	else
		pipe_child(fd[1]);
}
