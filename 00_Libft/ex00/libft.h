/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:59:11 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 20:07:49 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/*
	** Part 1-0 : memory functions
*/
void			*ft_memset(void *ptr, int value, size_t n);
void			ft_bzero(void *ptr, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *src, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
	** Part 1-1 : string functions
*/
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
char			*ft_strchr(const char *src, int c);
char			*ft_strrchr(const char *src, int c);
char			*ft_strnstr(const char *src, const char *to_find, size_t n);

/*
	** Part 1-2 : char determination functions
*/
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
	** Part 1-3 : memory allocation functions
*/
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *src);

/*
	** Part 2-0 : additional str management functions
*/
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
	** Part 2-1 : additional file write functions
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
	** Part b : bonus functions & structure define
*/
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));

/*
	** Part n : functions i'd like to use
*/
char			*ft_strndup(char *str, int length);

#endif
