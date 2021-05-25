# Piscine Python Django
배고프다...

## Day 00

### ex00
#### curl
- 데이터를 특정 프로토콜을 이용하여 서버에서 받아오거나 보내는 역할
- 지원되는 프로토콜은 다음과 같다 :
	- DICT, FILE, FTP, FTPS, GOPHER, HTTP, HTTPS, IMAP, IMAPS, LDAP, LDAPS, POP3,  POP3S,  RTMP,  RTSP, SCP, SFTP, SMB, SMBS, SMTP, SMTPS, TELNET and TFTP

### ex01
#### html 태그
- **title** : 페이지의 제목 (브라우저의 탭 등에 표시됨)
- **h1 ~ h7** : header, 숫자가 작을 수록 글자가 크다, 제목 및 소제목 표시용
- **table**: 표를 만든다
	- **thead**로 표의 윗 부분을 만든다
	- **tbody**로 표의 본체 부분을 만든다
		- **th**는 표의 제목을 적는다, 기본 가운데 정렬 + bold
		- **tr**은 가로줄을 만든다 (이 안에 td를 배치하면서 셀을 만들 수 있음)
		- **td**는 실질적인 셀이 만들어진다
	- border: solid 속성을 부여하면 테두리가 한 줄짜리 평평한 선이 된다
	- border-collapse: collapse 속성을 부여하면 인접한 셀들끼리 착 달라붙는다 (원래는 떨어져버림)
- **ul**, **ol**: 리스트를 만든다
	- **ul**은 unordered
	- **ol**은 ordered
	- **li**는 리스트 요소들이므로 ul, ol 안에 밀어넣으면 됨

## Day 01

### ex06
#### sorted
- iterable한 데이터 (list, str, tuple, dict 등, 멤버를 하나씩 반환 가능한 자료형) 를 인자값으로 받아, 새로운 정렬된 리스트로 반환해준다
- **sorted(데이터, key=, reverse=)**
	- 데이터에는 정렬할 데이터가 옴
	- key에는 정렬할 기준이 옴
	- reverse가 True이면 내림차순으로 정렬됨, 기본은 False로 오름차순 정렬
- list.sort()는 리스트를 정렬해서 덮어씌움
- sorted(list)는 리스트를 정렬해서 새로운 리스트를 반환함 (원본 리스트는 그대로 있다)

#### sorted & lambda식
- key로 사용할 값을 지정할 때 operator를 import하여 operator.itemgetter() 으로 값을 지정해 줄 수도 있음
- lambda식을 사용하여 값을 지정해 줄 수도 있고
	- **key = lambda x : (x에 관한 수식)**
	- 그러면 수식이 적용된 값이 key값으로 들어감
	```py
	key = lambda x : (x[1], x[0])
	```
	- 딕셔너리의 각 요소 (items) 에 대하여 두 번째 요소 (x[1])를 첫 번째 기준으로, 첫 번째 요소 (x[0]) 를 두 번째 기준으로 삼는다
	```py
	res = sorted(d.items(), key=lambda x: x[0])
	res = sorted(res, key=lambda x: x[1])
	```
	- 이렇게 두 줄로 반복해도 같은 값이 나옴
- **lambda x : (x에 관한 수식)** 은 결국 **def foo(x): (x에 관한 수식)** 과 같은 역할을 한다
- 단 람다식은 일회성이라 특정 데이터만을 처리할 때 주로 사용됨
- map 함수나 sorted 함수 등과 같이 주로 쓰인다
