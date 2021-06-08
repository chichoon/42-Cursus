# Libft Part 1-3 : Memory allocation functions
메모리 할당 (malloc) 을 사용하는 함수들  

## ft_calloc.c
- **void	*ft_calloc(size_t count, size_t size);**
- 메모리 할당해 줄 자료형의 크기와 개수를 받아서 크기 * 개수만큼 할당해준 후, 0으로 초기화
- 만약 할당에 실패했을 경우, 널 포인터 반환
- 그 외의 경우, 할당한 메모리의 첫 주소 반환

## ft_strdup.c
- **char	*ft_strdup(const char *src);**
- src 문자열을 그대로 새로운 주소에 복사
- src 문자열의 길이를 구해서 길이 + 1만큼 메모리 할당 후, 모든 값을 복사하고 마지막에 널문자 추가
- 만약 할당에 실패했을 경우, 널 포인터 반환
- 그 외의 경우, 복사한 문자열이 들어있는 메모리의 첫 주소 반환