/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_readline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:54:21 by jiychoi           #+#    #+#             */
/*   Updated: 2021/12/14 14:34:13 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*input;
	int		i;

	while (1)
	{
		input = readline("> ");
		if (!input)
			return (0);
		printf("%s\n", input);
		free(input);
	}
	return (0);
}
