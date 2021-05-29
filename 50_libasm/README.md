# libasm
strlen, strcpy, strcmp, write, read, strdup을 어셈블리어로 구현하시오 ㄷㄷ

### Prototype

### 뽀나스 파트
- atoi_base, list_push_front, list_size, list_sort, list_remove_if를 어셈블리어로 구현하시오


#### 동료평가중...
- libasm도 테스터기가 존재함!
- 확장자는 s
- section .text -> 여기부터 파일을 순서대로 읽음
- ft_strlen
	- xor rax, rax : 값 초기화, 같은 값을 xor취함으로써 (효율적으로) 0을 넣어주는 더 빠른
	- jmp count -> count 로 이동
	- cmp : 컴페어, rdi가 받아온 문자열이 들어가는 곳
	- je : 위의 줄이 맞을 경우 수행 하라 (je end : 끝으로 가시오)
	- inc rax : rax를 ++해줌
	- rax는 리턴값이라고 정의되어있음
- ft_strcpy
	- loop : 루프
	- mov cl, byte [rsi + r8] : c1
	- jne : 위의 줄이 틀릴 경우 수행하라
	- jmp : 쩜프
- ft_strcmp
	- rdi : 첫번째 인자값
	- rsi : 두번째 인자값
	- byte[레지스터] -> 레지스터에 저장된 byte를 가리킴
	- al, cl -> 8비트, rax, rcx -> 64비트 (같은 값을 가리키고 있음)
	- ret : rax를 리턴하시오
- ft_write
	- rax, 0x2000004 를 할당해주고, syscall을 하면 자동으로 write를 해줌
	- error 처리 : 출력을 실패하면 rax에 에러가 담겨있으므로, call __error 통해서 errono의 주소를 rax에 저장
	- push rax : rax 내의 값을 스택에 잠시 저장
	- pop rax : 스택에 저장한 값을 불러오기
	- mov [rax], rdx -> *src = dst 와 같음
	- 에러 발생 시 -1을 리턴해야 하므로, mov rdx, -1 후 ret
	- jc : 윗줄이 음수일 때
- ft_read
	- 2000003
- ft_strdup
	- rdi에 받아온 문자열을 스택에 저장
	- call ft_strlen : 받아온 문자열의 길이를 받아옴 (rax에)
	- rdi에 rax 값 대입 후, call _malloc
	- mov rdi, rax
	- pop rsi
	- call _ft_strcpy 통해서 malloc한 값에 스트링 복사
