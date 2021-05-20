# printf 구현

## ft_printf.c
### ft_printf
- fmt라는 string을 받아온다
	- fmt에는 일반 string과, %로 시작하는 format specifier가 들어있음
	- 또한, 가변 인자의 포인터가 fmt 다음부터 시작
	- fmt가 널일 경우, 0을 리턴하고 아무것도 출력 X
- 가변인자를 받아오기 때문에, va_start와 fmt를 이용하여 가변인자의 시작 포인터를 지정한다
- 리턴값은 지금까지 출력한 string의 총 길이가 된다
- 본격적인 파싱과 출력은 ft_printf_main에서 진행

### ft_printf_main
- 실질적인 동작을 수행하는 함수
- 가변인자의 시작점 param과 문자열 fmt를 받아온다
	- 가변인자 param은 와일드카드 / format 값에 따른 인자를 va_arg로 받아오기 위해 사용됨
	- fmt는 우리가 지금부터 파싱할 string
- fmt_conv라는 구조체를 선언
	- 각 format placeholder별로 어떤 플래그와 width, precision을 담고 있는지, type는 무엇인지 저장한다
	- 플래그 파싱 ~ 출력까지 계속 쓰이다가 마지막에 free됨
- fmt_until은 포인터 2개를 이용하기 위해 선언한 문자열
	- 예를 들어, format placeholder의 시작점 / 끝점을 찾거나, 우선 출력할 string의 끝 (% 직전이나, 널문자 직전) 을 찾아서 저장하게 됨
- output은 최종적으로 리턴할 출력 문자열 길이
	- 0으로 초기화된 후, fmt를 돌면서 계속 값을 더해간다
- 동작 방식
	- fmt 문자열의 처음부터 끝까지
	1. 문자 %를 찾아서, fmt_until을 찾는다
		- %를 찾지 못했을 경우, 현재 fmt부터 널문자까지 전체를 출력 후 출력한 문자열만큼을 output에 더하고 리턴한다
	2. %를 찾았을 경우, fmt_until에 해당 주소를 담고, 그 주소 직전까지 출력 후 output에 더한다
	3. fmt를 %의 위치로 이동시키고, fmt_until은 그 다음을 가리키도록 한다
	4. fmt_until부터 문자열을 검사하여 %나 cspdiuxX conversion을 찾는다
		- 이때 % 앞에는 -.*0123456789만 올 수 있고, cspdiuxX는 그냥 일단 찾는다
		- 못 찾았을 경우, fmt를 fmt_until 다음으로 옮긴다 (현재 %를 무시하고 다음 문자열로 스킵) 그리고 while문 처음으로 돌아감
	5. cspdiuxX%를 찾았을 경우, fmt_until을 해당 문자 위치로 이동시킨다
	6. fmt부터 fmt_until 사이의 플래그를 def_format 함수를 이용하여 파싱하고, 이 정보를 구조체 fmt_conv 안에 저장한다
		- 구조체 저장에 실패했을 경우, fmt를 fmt_until 다음으로 옮기고 fmt부터 다시 탐색
	7. 구조체 저장에 성공했을 경우, 이 내용을 토대로 ctrl_twr 함수에 보낸다
		- ctrl_twr 함수는 해당 format specifier가 가리키는 type를 확인하여 적절한 출력 함수에 구조체와 param을 인자로 전달
		- 그리고 ctrl_twr은 출력한 인자값의 길이만큼을 반환하므로, 이를 output에 더함으로써 출력 길이를 더해간다
	8. 출력에 성공한 format placeholder 다음으로 fmt 포인터를 옮긴 후, 1로 돌아가 다시 탐색한다
	- 모든 출력이 완료되었을 경우, 지금까지 더했던 출력 문자열의 총 길이인 output을 리턴하고 함수 종료

### get_convs_ptr
- 포인터를 1씩 이동시키면서 cspdiuxX를 검사
- cspdiuxX 발견했다면 해당 위치 포인터 리턴
- 널문자나 다음 % 전까지 발견 못하면 0 리턴

### ctrl_twr
- 완성된 구조체 fmt_conv를 이용하여 어떤 형식의 값을 출력해야 하는지 결정해주는 함수
- 각 함수 (ft_printcspdiuxX) 는 리턴값으로 출력한 길이를 반환하기 때문에, 이것을 그대로 output에 담고 리턴한다
- 그전에 구조체 free 잊지말기

## ft_printf_csp_0
### ft_print_c
- 문자 한 개를 출력하는 함수
- config_asterisk 함수를 이용하여 asterisk의 위치에 따라 (. 전인지 후인지에 따라 width와 precision이 달라짐) 구조체 안에 width와 precision 지정
- type가 c이냐 %이냐에 따라 동작이 달라지는데, c일 땐 가변인자로부터 int 하나를 받아와서 char로 형변환 후 출력하고, %일 땐 그냥 %를 바로 출력한다
- print_ctrltwr_c에서 나머지 플래그 처리를 해주기 때문에, 해당 함수로 인자 전달 후 리턴값으로 output 받아 반환

### ft_print_s
- 문자열을 출력하는 함수
- config_asterisk 함수를 이용하여 asterisk의 위치에 따라 (. 전인지 후인지에 따라 width와 precision이 달라짐) 구조체 안에 width와 precision 지정
- 만약 널포인터가 들어왔을 경우, 널임을 나타내는 (nulㅣ) 문자열을 출력 (이때, strjoin을 사용했기 때문에 반드시 후에 free를 해줘야 한다)
- 만약 정밀도가 음수일 경우, 문자열의 길이 그대로를 출력하기 때문에 fmt_conv->precision을 문자열 길이로 초기화
- print_ctrltwr_s에서 나머지 플래그 처리를 해주기 때문에, 해당 함수로 인자 전달 후 리턴값으로 output 받아 반환

### ft_print_p
- 주소값을 출력하는 함수
- config_asterisk 함수를 이용하여 asterisk의 위치에 따라 (. 전인지 후인지에 따라 width와 precision이 달라짐) 구조체 안에 width와 precision 지정
- 만약에 널포인터가 들어왔고, 정밀도가 정의되지 않았을 경우 0x0이 아닌 0x만이 출력되기 때문에, strjoin을 이용하여 빈 문자열을 출력
- 널포인터가 아닐 경우, itoa_base를 이용하여 16진수 문자열로 바꿔준 뒤 출력에 사용
- 두 경우 모두 함수 내부에서 malloc을 사용하기 때문에 반드시 free해줘야 함
- print_ctrltwr_p에서 나머지 플래그 처리를 해주기 때문에, 해당 함수로 인자 전달 후 리턴값으로 output 받아 반환

### check_if_percent
- 현재 서식지정자가 %기호인지 아닌지 판단하는 함수
- % 기호 전에는 플래그 0-.*, 숫자만 올 수 있기 때문에 그 외의 것이 들어왔을 경우엔 제외
- 정상적인 서식지정자라 판단되었을 경우, % 문자의 위치를 반환

### config_asterisk
- 와일드카드가 폭 (width) 쪽에 있는지, 정밀도 (precision) 쪽에 있는지에 따라 va_arg가 다른 곳에 들어가기 때문에 if문을 이용하여 분기
	- 폭에 음수가 들어올 경우, 플래그에 -이 있는 것과 같이 동작하며, 실제 폭은 절대값이 된다
- 와일드카드가 양 쪽 모두 존재하는 경우는 undefined이나, segfault가 나선 안 되기 때문에 값을 받아들이는 방향으로 조정

## ft_printf_csp_1
### calc_length
- 실질적으로 출력될 문자열의 길이를 계산하는 함수
- type가 s (문자열) 일 경우, 정밀도의 영향을 많이 받기 때문에 (정밀도가 실제 문자열 길이보다 짧을 경우, 정밀도만큼만 출력) 정밀도에 따라 출력될 문자열의 길이를 다르게 제한한다
- 만약 precision이 정의되지 않았지만 .이 존재할 땐, 0 리턴 (문자열 하나도 출력 안함)
- 만약 precision은 정의되지 않았지만 .도 존재하지 않을 땐, 문자열의 길이 그대로 리턴 (문자열 그대로 출력)
- 만약 precision이 존재하면서 length보다 짧을 때, precision을 그대로 리턴 (정밀도만큼만 출력, 정밀도가 음수일 땐 정밀도 정의 안되었을 때처럼 출력 X)

### calc_width
- 실질적으로 공백이 출력되는 폭을 계산하는 함수
- length는 calc_length를 통해 계산된 실질적 출력 길이를 사용
- 폭을 format placeholder에서 정의해 줬더라도, 정밀도나 실제 문자열의 길이에 따라서 변동되므로 이를 위한 예외처리를 해줌
1. fmt_conv->width가 음수가 되는 경우는 width를 받지 않았을 때 (default값인 -2147483648로 남아있을 때) 제외하고 config_asterisk에서 처리해주었기 때문에, 나머지 경우 (-2147483648 : width 미정의) 출력되는 폭의 길이는 0으로 리턴한다
2. 출력 문자열의 길이가 정밀도보다 클 경우
	- 정밀도가 default값이면서 플래그에 .이 존재할 경우엔, width 리턴
	- 정밀도가 default값이면서 플래그에 .이 존재하지 않을 경우엔, width가 length보다 큰 경우에 한해 width - length를 리턴
	- 정밀도가 0 이상이고 width가 정밀도보다 크면, width - 정밀도를 리턴 (정밀도가 0 이상일 땐, 출력 문자열의 길이가 정밀도보다 작거나 같은 경우밖에 없으므로 해당 케이스에 도달하지 못할 것으로 예상됨)
	- 그 외의 경우에 0 리턴
3. 출력 문자열의 길이가 정밀도보다 작거나 같을 경우
	- width가 길이보다 클 경우, width - length 리턴
	- 그 외의 경우에 0 리턴

### print_ctrltwr_c
- c를 출력할 때, 플래그에 따라 동작을 다르게 하기 위해 방향을 지정하는 함수
- wtp는 width to print, 실질적으로 출력되는 공백 또는 0의 개수를 의미
- c는 무조건 1글자만 출력되고 정밀도의 영향을 받지 않으므로, wtp만 이용하게 된다
- 만약 - 플래그가 설정되어 있을 경우, print_if_minus_c를 통해 왼쪽 정렬을 진행
- 만약 - 플래그가 없으면서 0 플래그가 설정되어 있으면, print_if_zero_c를 통해 공백 대신 0을 넣음 (undefined)
- 그 외의 경우엔, 플래그가 없다고 가정하여 print_no_flags_c를 통해 출력

### print_ctrltwr_s
- s를 출력할 때, 플래그에 따라 동작을 다르게 하기 위해 방향을 지정하는 함수
- wtp는 width to print, 실질적으로 출력되는 공백 또는 0의 개수를 의미
- length는 실제로 출력될 문자열의 길이를 나타내며, 정밀도에 따라 변하기 때문에 calc_length 함수를 사용했음
- 만약 - 플래그가 설정되어 있을 경우, print_if_minus_s를 통해 왼쪽 정렬을 진행
- 만약 - 플래그가 없으면서 0 플래그가 설정되어 있으면, print_if_zero_s를 통해 공백 대신 0을 넣음 (undefined)
- 그 외의 경우엔, 플래그가 없다고 가정하여 print_no_flags_s를 통해 출력

### print_ctrltwr_p
- p를 출력할 때, 플래그에 따라 동작을 다르게 하기 위해 방향을 지정하는 함수
- wtp는 width to print, 실질적으로 출력되는 공백 또는 0의 개수를 의미
- 포인터는 정밀도에 따라 0x와 주소값 사이가 0으로 채워지므로, ptp (precision to print) 를 통해 출력할 정밀도를 계산
	- 만약 fmt_conv에 저장된 정밀도가 양수일 때, ptp는 정밀도 - 주소의 길이 가 된다
	- ptp가 양수이고 width가 정밀도보다 클 때, wtp는 폭 - 정밀도 - 2가 된다 (2는 0x 때문)
	- ptp가 음수이고 width가 정밀도보다 클 때, wtp는 폭 - 문자열길이 - 2가 된다
	- fmt_conv에 저장된 정밀도가 음수나 0이면, wtp는 폭이 문자열 길이보다 클 때에 한해 폭 - 문자열길이 - 2가 된다
- 만약 - 플래그가 설정되어 있을 경우, print_if_minus_p를 통해 왼쪽 정렬을 진행
- 0 플래그에 대해서는 undefined이므로 출력 x
- 그 외의 경우엔, 플래그가 없다고 가정하여 print_no_flags_p를 통해 출력
