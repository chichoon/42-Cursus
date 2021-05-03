# Libft 함수에 대한 설명
구현해야 할 함수가 엄청매우매우매우무지많다  
해당 함수들을 메모해놓기 위해 만듦

## ft_memset.c
- **void *ft_memset(void *ptr, int value, unsigned int num);**
- ptr 포인터를 시작점으로 하여, num 바이트만큼 value값으로 초기화
- 초기에 인자로 받은 ptr이 널일 경우, 복사 없이 0을 반환
- 그 외의 경우, 초기 포인터값을 반환

## ft_bzero.c
- **void *ft_bzero(void *ptr, unsigned int size);**
- ptr 포인터를 시작점으로 하여, size 바이트만큼 0으로 초기화
- 초기에 인자로 받은 ptr이 널일 경우, 복사 없이 0을 반환
- 그 외의 경우, 초기 포인터값을 반환
- deprecated.. 하지만 42는 좋아하는 것 같다

## ft_memcpy.c
- **void *ft_memcpy(void *dst, void *src, unsigned int num);**
- dst 포인터를 시작점으로 하여, num 바이트만큼 src 포인터의 값을 복사
- 초기에 인자로 받은 dst, src 중 하나라도 널일 경우, 복사 없이 0을 반환
- 그 외의 경우, 초기 포인터값을 반환

## ft_memccpy.c
- **void *ft_memccpy(void *dst, void *src, int c, unsigned int n);**
- dst 포인터를 시작점으로 하여, c 문자를 만날 때까지 src 포인터의 값을 복사
- n 바이트만큼 복사를 하였음에도 불구, c 문자를 만나지 못했다면 0 반환
- 그 외의 경우, 초기 포인터값을 반환

## ft_memmove.c
- **void *memmove(void *dst, void *src, unsigned int count);**
- dst 포인터를 시작점으로 하여, count 바이트만큼 src 포인터의 값을 복사
- memcpy와 다른 점이 있다면, memcpy는 src 포인터와 dst 포인터가 겹칠 경우 값이 중복될 우려가 있음
- 허나 memmove는 먼저 버퍼에 복사할 값을 저장하고 해당 버퍼에 들어있는 값을 복사하기 때문에, 포인터가 겹칠 때 값의 중복을 예방할 수 있다
- 반환값은 memcpy와 같음
	- 초기에 인자로 받은 dst, src 중 하나라도 널일 경우, 복사 없이 0을 반환
	- 그 외의 경우, 초기 포인터값을 반환
