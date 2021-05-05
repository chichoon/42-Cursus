# Libft Part B: bonus functions & structure define
리스트 처리 함수들  
> typedef struct	s_list  
> {  
> 	void			*content;  
> 	struct s_list	*next;  
> }				t_list;  

content는 리스트의 실질적인 내용물 주소, next는 연결된 다음 리스트의 주소

## ft_lstnew.c
- **t_list	*ft_lstnew(void *content);**
- content 주소를 content로 담은 새로운 리스트 생성
- t_list 구조체의 크기만큼 메모리 할당 후, content와 next 넣어 줌
- next는 널포인터로 설정해준다
- 할당에 실패했을 경우 널 포인터 반환
- 그 외의 경우, 만든 리스트의 주소값 반환

## ft_lstadd_front.c
- **void	ft_lstadd_front(t_list **lst, t_list *new);**
- new->next를 lst가 가진 첫 번째 리스트 주소로 연결 후, 첫 번째 리스트 주소를 new로 설정

## ft_lstsize.c
- **int		ft_lstsize(t_list *lst);**
- 연결된 리스트 lst의 총 길이를 구해서 반환
- 리스트의 맨 끝은 무조건 널 포인터를 가리키므로, 널 포인터가 나올 때까지 ++하여 탐색
- 탐색한 후 나온 총 길이 반환

## ft_lstlast.c
- **t_list	*ft_lstlast(t_list *lst);**
- 연결된 리스트 lst의 맨 끝 리스트를 구해서 그 주소를 반환
- 리스트의 맨 끝은 무조건 널 포인터를 가리키므로, 널 포인터를 가리키는 리스트가 나올 때까지 ++하여 탐색
- 만약 lst가 널 포인터일 경우, 널 포인터 반환
- 그 외의 경우, 찾은 주소값 반환

## ft_lstadd_back.c
- **void	ft_lstadd_back(t_list **lst, t_list *new);**
- 리스트 lst의 맨 뒤에 새로운 리스트 new를 연결
- 만약 lst가 널 포인터일 경우, 탐색 중단
- 그 외의 경우, 맨 끝에 있는 리스트를 찾아서 next에 new를 연결

## ft_lstdelone.c
- **void	ft_lstdelone(t_list *lst, void (*del)(void *));**
- 
## ft_lstclear.c
- **void	ft_lstclear(t_list **lst, void (*del)(void *));**
## ft_lstiter.c
- **void	ft_lstiter(t_list *lst, void (*f)(void *));**
## ft_lstmap.c
- **t_list	\*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));**