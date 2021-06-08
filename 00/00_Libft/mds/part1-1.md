# Libft Part 1-1 : String functions
문자열 처리 관련 함수들  
예외처리는 원본 함수와 똑같이 해줘야 한다 (원본이 crash 났다면, 구현본도 crash)  

## ft_strlen.c
- **size_t	ft_strlen(const char *s);**
- str의 길이를 구해서 반환
- 널값 직전까지 str을 이동시켜 주면서 총 길이를 구한다

## ft_strlcpy.c
- **size_t	ft_strlcpy(char *dst, const char *src, size_t n);**
- src 내의 문자열을 n개만큼 dst 포인터에 복사
- dst 포인터에 문자열 복사 후, 마지막에 널 문자를 붙여주어야 한다 (string의 끝을 표시)
- dst와 src 둘 중 하나가 널 포인터일 경우 0 반환
- 그 외의 경우, src의 길이 반환

## ft_strncmp.c
- **int		ft_strncmp(const char *s1, const char *s2, size_t n);**
- n번동안 s1과 s2를 비교
- const char인 포인터는 unsigned char로 형변환 필요
- s1과 s2 안의 문자열이 서로 다를 경우, s1 - s2를 반환
- n번 탐색했을 때 모든 문자열이 일치할 경우, 0 반환

## ft_strlcat.c
- **size_t	ft_strlcat(char *dst, const char *src, size_t n)**
- dst의 끝 (널 문자 위치) 에 src의 문자열을 복사
- 이때, dst의 총 길이 (이미 있는 문자열의 길이) 와 복사된 src의 길이의 합이 n이 되게끔 src를 복사
- 만약 n이 dst의 길이보다 짧을 경우 (복사된 값이 없을 경우) n + src의 길이 반환
- 그 외의 경우, dst의 길이 + src의 길이 반환

## ft_strchr.c
- **char	*ft_strchr(const char *src, int c)**
- src 포인터 내에서 문자열 c를 탐색
- c를 찾지 못했다면 널 포인터 반환
- 그 외의 경우, 처음으로 c를 발견한 포인터값 반환

## ft_strrchr.c
- **char	*ft_strrchr(const char *src, int c)**
- src 포인터 내에서 문자열 c를 탐색하되, 뒤에서부터
- strchr과 동작은 일치하나, 뒤에서 한다는 점에서 다름
- c를 찾지 못했다면 널 포인터 반환
- 그 외의 경우, 처음으로 c를 발견한 포인터값 반환

## ft_strnstr.c
- **char	*ft_strnstr(const char *src, const char *to_find, size_t n)**
- src 내의 문자열을 n개만큼 탐색하면서, to_find 문자열을 검색
- to_find 문자열이 널 문자일 경우, src의 초기 주소 반환
- 그 외의 경우, 검색된 문자열의 시작지점 주소값 반환