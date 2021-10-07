/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:45:39 by jiychoi           #+#    #+#             */
/*   Updated: 2021/10/07 22:51:34 by jiychoi          ###   ########.fr       */
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

int	main(int argc, char *argv[], char *envp[])
{
	pipe_getpath(envp);
}
