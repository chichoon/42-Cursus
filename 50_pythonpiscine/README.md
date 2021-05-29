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

## Day 02

### ex04
#### Nonetype과 Null
- Nonetype의 None은 별개로 존재한다
	- str = "", list = [] 등은 다 None이 아님
	- 보통 함수 인자값에 아무것도 안 들어왔을 때 default값으로 사용
- 조건문에 조건으로 넣어줬을 때
	- str = "", list = []는 조건문에서 False를 반환한다 (C에서 Null과 같음)
	- list = [""] 는 인자가 있다고 가정하므로 True를 반환한다
	- None은 무조건 False를 반환한다
- 그래서 Elem의 생성자에서 content is not None일 때 content == "" 과 [] 가 걸러진다
- 이 중에서 Text 타입이 아닐 때 Validation Error 반환
	- "" 같은 경우는 None도 아니고 False를 반환하므로 타입을 체크

## Day 03

### ex02
#### Wikipedia api
```
https://en.wikipedia.org/w/api.php?action=query&titles={arg}&prop=revisions&rvprop=content&format=json
```
1. **action=query**
	- mediawiki에서 값을 받아온다
2. **titles={arg}**
	- 위키 항목 제목을 지정한다
3. **prop=revisions**
	- 검토용 정보를 가져온다
4. **rvprop=content**
	- 각 항목 제목마다 컨텐츠를 가져온다
5. **format=json**
	- 내용을 가져올 때 json 형식으로 가져온다


### ex05
#### First Django Application
[참고한 링크](https://docs.djangoproject.com/ko/3.2/intro/tutorial01/)
1. 가상환경 실행 (이미 만들어둔 django_venv를 사용)
2. (django, psycopg2이 없을 경우) 가상환경에 설치
3. **django-admin startproject (프로젝트명)** 을 통해 프로젝트 추가
4. **cd (프로젝트명)** 으로 쟝고 프로젝트 폴더로 이동
5. 프로젝트 세팅 - helloworld 앱 생성 기준
	0. **python3 manage.py migrate** 이용하여 데이터베이스 생성 (not mandatory now)
	1. **python3 manage.py startapp helloworld** 이용하여 helloworld 앱 생성
	2. (프로젝트명)/helloworld 폴더 안에 있는 파일 수정
		- (프로젝트명)/(프로젝트명)/settings.py에 앱 등록
		- helloworld/views.py를 수정하여 적절한 Http Response 또는 html을 template에서 불러오도록 설정
		- (프로젝트명)/(프로젝트명)/urls.py를 수정하여 프로젝트의 경로에서 helloworld 앱의 경로가 연결되도록 설정
		- helloworld/urls.py 추가

6. **python3 manage.py runserver** 이용하여 서버 시작


## Day 04

### ex00
- html 연결할 때: settings.py의 TEMPLATES 리스트에 템플릿 경로 추가 (BASEDIR / 'templates' 등)

### ex01
- Template Engine 사용법 :
```py
def django(request):
    return render(request, 'django.html')
```
- 따로 경로를 잡아줘야 했던 이유는.. 앱등록을 안해서 그런거였다 앱등록 꼭 하기
- template를 사용하는 html을 render하면 자동으로 템플릿 적용되어 보여짐
