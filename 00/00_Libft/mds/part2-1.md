# Libft Part 2-1 : Additional file write functions
파일 디스크립터에 문자열을 쓰는 함수들  

## ft_putchar_fd.c
- **void	ft_putchar_fd(char c, int fd);**
- 전달받은 fd에 문자 하나 입력

## ft_putstr_fd.c
- **void	ft_putstr_fd(char *s, int fd);**
- 전달받은 fd에 문자열 입력 (널문자 전까지)

## ft_putendl_fd.c
- **void	ft_putendl_fd(char *s, int fd);**
- 전달받은 fd에 문자열 입력 후, 줄옮김 입력

## ft_putnbr_fd.c
- **void	ft_putnbr_fd(int n, int fd);**
- 전달받은 fd에 숫자 입력
- 입력 부분은 재귀함수로 구현함