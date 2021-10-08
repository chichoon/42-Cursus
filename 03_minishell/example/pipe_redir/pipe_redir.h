/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redir.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:38:37 by jiychoi           #+#    #+#             */
/*   Updated: 2021/10/09 00:01:25 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_REDIR_H
# define PIPE_REDIR_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/*
	* UTILITIES
*/
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *src, const char *to_find, size_t n);

#endif
