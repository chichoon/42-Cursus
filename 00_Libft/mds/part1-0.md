# Libft Part 1-0 : Memory functions
메모리 관련 함수들  
memset, bzero를 제외하고 모두 void *인 인자값을 unsigned char *로 변환해줘야 한다  
예외처리는 원본 함수와 똑같이 해줘야 한다 (원본이 crash 났다면, 구현본도 crash)  

## ft_memset.c
- **void	*ft_memset(void *ptr, int value, size_t n);**
- ptr 포인터를 시작점으로 하여, num 바이트만큼 value값으로 초기화
- 초기에 인자로 받은 ptr이 널일 경우 Crash
- 그 외의 경우, 초기 포인터값을 반환
- 인자로 받아오는 포인터가 void형식이기 때문에, 값을 대입하기 위해 내부에서 형변환을 요구함 (unsigned char)

## ft_bzero.c
- **void	ft_bzero(void *ptr, size_t n);**
- ptr 포인터를 시작점으로 하여, size 바이트만큼 0으로 초기화
- 초기에 인자로 받은 ptr이 널일 경우 Crash
- 반환값 없음
- 인자로 받아오는 포인터가 void형식이기 때문에, 값을 대입하기 위해 내부에서 형변환을 요구함 (unsigned char)
- deprecated.. 하지만 42는 좋아하는 것 같다

## ft_memcpy.c
- **void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);**
- dst 포인터를 시작점으로 하여, num 바이트만큼 src 포인터의 값을 복사
- 초기에 인자로 받은 dst, src 중 하나라도 널일 경우, 복사 없이 널포인터 반환
- 그 외의 경우, 초기 포인터값을 반환

## ft_memccpy.c
- **void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n);**
- dst 포인터를 시작점으로 하여, c 문자를 만날 때까지 src 포인터의 값을 복사 (c 문자 포함)
- 초기에 인자로 받은 dst, src 중 하나라도 널일 경우, 복사 없이 널포인터 반환
- n 바이트만큼 복사를 하였음에도 불구, c 문자를 만나지 못했다면 0 반환
- 그 외의 경우, 복사 후 c 문자 다음의 포인터를 반환

## ft_memmove.c
- **void	*ft_memmove(void *dst, const void *src, size_t n);**
- dst 포인터를 시작점으로 하여, count 바이트만큼 src 포인터의 값을 복사
- memcpy와 다른 점이 있다면, memcpy는 src 포인터와 dst 포인터가 겹칠 경우 값이 중복될 우려가 있음
- 허나 memmove는 복사 시작 지점을 달리 하여 복사하기 때문에, 포인터가 겹칠 때 값의 중복을 예방할 수 있다
	- dst 포인터가 src 포인터보다 뒤에 있을 경우 src의 맨 끝 값부터 복사
	- dst 포인터가 src 포인터보다 앞에 있을 경우 src의 맨 앞 값부터 복사
	- 시작 지점을 달리 하면, 값이 먼저 복사된 후 포인터를 이동하기 때문에 중복된 값이 들어갈 일이 없다
- 반환값은 memcpy와 같음
	- 초기에 인자로 받은 dst, src 중 하나라도 널일 경우, 복사 없이 널 포인터 반환
	- 그 외의 경우, 초기 포인터값을 반환

## ft_memchr.c
- **void	*ft_memchr(const void *src, int c, size_t n);**
- src 포인터 내에서 문자열 c를 탐색
- c를 찾지 못했다면 널 포인터 반환
- 그 외의 경우, 처음으로 c를 발견한 포인터값 반환

## ft_memcmp.c
- **int		ft_memcmp(const void *s1, const void *s2, size_t n);**
- n번동안 s1과 s2를 비교
- s1과 s2 안의 문자열이 서로 다를 경우, s1 - s2를 반환
- n번 탐색했을 때 모든 문자열이 일치할 경우, 0 반환