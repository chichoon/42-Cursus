# get_next_line 함수 구현하기
파일을 읽어들이고, 거기서 \n (개행) 전의 한 줄씩 뽑아오는 함수  
정적 변수를 얼마나 적절하게 사용하느냐 가 관건  

### Prototype
- **int get_next_line(int fd, char **line);**
- fd는 읽어들일 파일의 디스크립터
- line은 읽은 값 (문자열) 하나가 저장된 주소값
	- 주소값에 접근하면 string 한 개의 시작 주소값이 들어있 음
- 반환값
	- 한 라인이 읽혔을 때 : 1
	- EOF에 도달했을 때 : 0
	- 에러가 발생했을 때 : -1

### 주의사항
- libft 사용 금지!!
	- 필요한 함수는 get_next_line_utils.c에 적절히 정의하여 사용해야 한다
- 컴파일은 **gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c** 로 진행
	- BUFFER_SIZE는 헤더에서 미리 정의할 필요가 굳이 없다 (-D 플래그를 사용하면, 새로운 매크로 상수를 헤더에 추가해주는 것과 진배없음)
	- BUFFER_SIZE를 사전 정의하거나 플래그를 사용해서 넣지 않으면 컴파일 에러가 발생하므로, 뮬리넷에서 무조간 -D 플래그를 사용해서 컴파일할듯? (이부분에 대한 예외처리는 해주지 않아도 될 것 같다..)

