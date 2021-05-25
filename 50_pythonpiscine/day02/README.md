# **D01 - Piscine Python-Django**

파이썬 기초

_요약: 오늘은 Python의 통사론 (Syntactics) 과 의미론 (Semantics) 기초를 배울 여행을 떠나 봅니다._

<br>

# Contents

| Chapter | Contents | page|
| :----:| :------- | :------: |
| 1 | [**Preamble**](#Chapter-1) | 2 |
| 2 | [**Instructions**](#Chapter-2) | 3 |
| 3 | [**Today's specific rules**](#Chapter-3) | 4 |
| 4 | [**Exercise 00**](#Chapter-4) | 5 |
| 5 | [**Exercise 01**](#Chapter-5) | 7 |
| 6 | [**Exercise 02**](#Chapter-6) | 8 |
| 7 | [**Exercise 03**](#Chapter-7) | 10 |
| 8 | [**Exercise 04**](#Chapter-8) | 12 |
| 9 | [**Exercise 05**](#Chapter-9) | 14 |
| 10 | [**Exercise 06**](#Chapter-10) | 16 |

<br>

# **Chapter 1**

## Preamble

<br>

이것은 '자유 소프트웨어 노래' 의 가사입니다:

```
Join us now and share the software;
You’ll be free, hackers, you’ll be free.
Join us now and share the software;
You’ll be free, hackers, you’ll be free.
Hoarders can get piles of money,
That is true, hackers, that is true.
But they cannot help their neighbors;
That’s not good, hackers, that’s not good.
When we have enough free software
At our call, hackers, at our call,
We’ll kick out those dirty licenses
Ever more, hackers, ever more.
Join us now and share the software;
You’ll be free, hackers, you’ll be free.
Join us now and share the software;
You’ll be free, hackers, you’ll be free.
```


<br>

# **Chapter 2**

## Instructions

<br>

노골적인 모순이 없는 이상, 해당 지침은 Python Django Piscine 모든 날짜에 적용됩니다.

- 이 페이지에 있는 내용만이 레퍼런스로 적용됩니다. 루머를 믿지 마세요!

- 조심하세요! 과제를 제출하기 한 시간 전까지도 해당 문서는 변경될 수 있습니다.

- 이번 과제들은 난이도별로 배치되어 있습니다 - 쉬운 것부터 어려운 것 까지요. 만약 쉬운 과제가 제대로 작동하지 않으면, `우리는 절 대` 어려운 과제를 (완벽하게 구현하였더라도) 채점하지 않을 것입니다.

- 파일과 디렉토리에 적절한 권한 설정을 해 주었는지 확인하세요.

- 각 과제별로 **제출 필수사항**을 지키셔야 합니다.

- 여러분의 과제는 같은 피씨너들에게 채점받고 점수가 매겨질 것입니다.

- 그리고 그 뒤에, 뮬리넷이라는 프로그램에 의해 채점되고 점수가 매겨질 것입니다. 뮬리넷은 여러분의 과제를 정말 엄격하고 꼼꼼하게 채점할 것입니다. 또한 모든 작업은 자동으로 진행되므로, 여러분이 뮬리넷과 협상하는 것은 불가능합니다. 좋지 못한 결과를 깜짝 선물로 받고 싶지 않다면, 철저히 과제에 임하세요.

- 쉘 과제들은 `/bin/sh`에 의해 실행될 수 있어야 합니다.

- 여러분은 **절대로** 명시된 제출 파일 외의 다른 파일들을 폴더 내에 남겨두시면 **안됩니다.**

- 질문 있으세요? 오른쪽 동료에게 물어보세요. 아니면 왼쪽 동료한테 물어보세요.

- 여러분이 참고할 만한 가이드는 `Google / man / 인터넷` 등이 있습니다.

- 인트라나 슬랙의 피씬 채널에서 토의하는 것을 잊지 마세요!

- 예시를 꼼꼼히 살펴보세요. 과제에 명시되지 않은 상세한 부분들이 들어있을 수도 있으니까요..

<br>

# Chapter 3

## Today's specific rules

- 전역에 코드를 작성하지 마세요. 우리는 함수를 원해요!

- 다른 말이 명시되어 있지 않은 이상, 모든 제출 파일은 다음과 같이 끝나야 합니다 :
```
if __name__ == '__main__':
    # 여러분이 수행할 동작과 오류 처리
```

- 처리되지 않은 예외는 과제를 무효화할 것입니다. 심지어 테스트해야 하는 오류가 발생했더라도 말이죠..

- 각 과제별 설명란의 'Authorized functions' 에 명시되어 있는 함수 / 라이브러리 외에는 import가 절대 금지됩니다.


<br>

# Chapter 4

## Exercise 00

<br>

| **Piscine**                | Exercise 00            |
| ---------------------------- | ----------------------------------------------------------------------------------- |
| Exercise 00 : 실리콘 밸리를 정복하라!                 |
| **제출할 폴더**              | ex00/            |
| **제출할 파일**                 | `render.py, myCV.template, settings.py`         |
| **허용되는 함수**                   | `import sys, os, re`       |

<br>

여러분은 방금 놀라운 개발자 양성 코스를 완벽하게 통과했습니다! 이제 여러분은 인생을 영원히 바꿔줄 새로운 관점으로 세상을 보게 됩니다. 여러분은 방금 딱 하나의 목표를 가지고 실리콘 밸리에 도착했습니다 : 대박 쩌는 기술로 혁신적인 이력서 생성기를 개발하고 구인구직 업계의 빌 게이츠가 되겠다는 목표 말이죠!

그래서 여러분이 해야할 일은... 해당 기술을 직접 만들어야 합니다.

`.template` 확장자의 파일을 인자로 받는 `render.py` 프로그램을 만드세요. 프로그램은 파일의 내용물을 읽고, 몇몇 패턴을 `settings.py`에 선언된 값으로 변경하고 (`settings.py`에서 `if __name__ == '__main__'` 블록은 필요하지 않습니다.), 결과물을 `.html` 확장자로 저장해야 합니다.

여러분은 다음과 같은 예시를 직접 만든 프로그램에 _시험해 보셔야_ 합니다 :
```sh
$> cat settings.py
name = "duoquadragintian"
$> cat file.template
<p>"-Who are you?
-A {name}!"</p>
$> python3 render.py file.template
$> cat file.html
<p>"-Who are you?
-A duoquadragintian!"</p>
```

잘못된 파일 확장자, 존재하지 않는 파일 또는 잘못된 인자값 개수 등의 예외는 알맞게 처리되어야 합니다.

여러분은 `myCV.template` 파일을 제출해야 하고, 해당 파일은 HTML로 변환되었을 때 최소한 html과 이력서의 기본 구조 (`doctype, head, body`, 페이지의 title, 이력서 작성자의 이름과 성씨, 나이와 직업) 를 포함해야 합니다. 물론, 이러한 정보들은 `.template` 파일에 직접적으로 표시되진 않을 것입니다.

```
⚠️
스크립트로 불러오면 안 됩니다. 주어진 js 파일들은 수정되면 안 됩니다. 자바스크립트 코드를 HTML 코드 내에 추가하면 안 됩니다.
```

<br>

# Chapter 5

## Exercise 01 : Numbers

<br>

| **Piscine**                | Exercise 01            |
| ---------------------------- | ----------------------------------------------------------------------------------- |
| Exercise 01 : 숫자                 |
| **제출할 폴더**              | ex01/            |
| **제출할 파일**                 | `numbers.py`         |
| **허용되는 함수**                   | `n/a`       |

<br>

이 과제에서는, 여러분이 원하는 대로 함수를 마음껏 선언하셔도 되고, 개수나 이름도 상관 없습니다.

`d01.tar.gz` tarball 안의 ex01 폴더에는 `numbers.txt`가 들어있으며, 해당 텍스트 파일에는 1부터 100까지의 숫자가 콤마 (,) 로 구분되어 나열되어 있습니다.

`numbers.py` 라 이름붙여진 `python` 스크립트를 작성하세요. 해당 스크립트를 실행시키면 `numbers.txt`를 읽어들이고, 한 줄에 하나씩 표준 출력으로 출력하되, 콤마 없이 출력해야 합니다.

# Chapter 6

## Exercise 02 : My first Dictionary

<br>

| **Piscine**                | Exercise 02            |
| ---------------------------- | ----------------------------------------------------------------------------------- |
| Exercise 02 : 첫 딕셔너리                 |
| **제출할 폴더**              | ex02/            |
| **제출할 파일**                 | `var_to_dict.py`         |
| **허용되는 함수**                   | `N.A.`       |

<br>

다시 한번, 해당 과제에서는 여러분이 원하는 대로 자유롭게 함수를 선언하시면 됩니다. 이후 과제에서도 명시적으로 부인되지 않는 이상, 해당 내용을 반복해서 말하진 않을게요.

`var_to_dict.py` 라는 스크립트를 작성하세요. 그리고 해당 리스트를 여러분의 함수 중 하나에 복사하세요 :

```python
d = [
('Hendrix' , '1942'),
('Allman' , '1946'),
('King' , '1925'),
('Clapton' , '1945'),
('Johnson' , '1911'),
('Berry' , '1926'),
('Vaughan' , '1954'),
('Cooder' , '1947'),
('Page' , '1944'),
('Richards' , '1943'),
('Hammett' , '1962'),
('Cobain' , '1967'),
('Garcia' , '1942'),
('Beck' , '1944'),
('Santana' , '1947'),
('Ramone' , '1948'),
('White' , '1975'),
('Frusciante', '1970'),
('Thompson' , '1949'),
('Burton' , '1939')
]
```

여러분의 스크립트는 이 변수를 딕셔너리 타입으로 변환하여야 합니다. 연도는 key가 되고, 음악가의 이름은 value가 됩니다. 또한 다음과 같은 깔끔한 형식으로 딕셔너리를 표준 출력해야 합니다 :
```
1970 : Frusciante
1954 : Vaughan
1948 : Ramone
1944 : Page Beck
1911 : Johnson
...
```

```
ℹ️
실제 동작 결과와 해당 예시의 순서는 일치할 필요가 없습니다. 이것은 자연스러운 동작입니다. 왠지 아시나요?
```

# Chapter 7
## Exercise 03: Key search
​
<br>

| **Piscine**                | Exercise 03            |
| ---------------------------- | ------------------------------------ |
| Exercise 03 : Key로 찾기                   |
| **제출할 폴더**              | ex03/            |
| **제출할 파일**                 | `capital_city.py`         |
| **허용되는 함수**                   | `import sys`      |

<br>
​
여기에 여러분 프로그램의 함수에 수정하지 않고 복사해넣어야 하는 사전 자료형들이 있습니다.

```python
states = {
"Oregon" : "OR",
"Alabama" : "AL",
"New Jersey": "NJ",
"Colorado" : "CO"
}
capital_cities = {
"OR": "Salem",
"AL": "Montgomery",
"NJ": "Trenton",
"CO": "Denver"
}
```

주를 인자로 받아 (예: `Oregon`) 그 주도를 (예: `Salem`) 표준 출력으로 나타내는 프로그램을 작성하세요. 만약에 인자에 해당하는 답안이 없다면 `Unknown State`를 출력해야 합니다. 만약 주어진 인자가 없거나 - 또는 너무 많다면 - 아무것도 하지 않고 종료되어야 합니다.

```sh
$> python3 capital_city.py Oregon
Salem
$> python3 capital_city.py Ile-De-France
Unknown state
$> python3 capital_city.py
$> python3 capital_city.py Oregon Alabama
$> python3 capital_city.py Oregon Alabama Ile-De-France
$>
```
​
# Chapter 8
## Exercise 04 : Search by value
​
<br>

| **Piscine**                | Exercise 04            |
| ---------------------------- | ----------------------------------------------------------------------------------- |
| Exercise 04 : Value로 찾기                   |
| **제출할 폴더**              | ex04/            |
| **제출할 파일**                 | `state.py`         |
| **허용되는 함수**                   | `import sys`      |

<br>
​
이전 (ex03)에서 주어진 것과 똑같은 사전 자료형 값을 가지고 있습니다. 다시 한 번 값을 바꾸지 않은 채로 여러분의 프로그램 내 함수에 복사해넣으세요.

이번에는 ex03과는 반대로 주도를 입력으로 받아 그에 해당하는 주를 출력하는 프로그램을 만들어야 합니다. 그 외에는 지난번 Excersise와 똑같이 행동해야 합니다.

```sh
$> python3 state.py Salem
Oregon
$> python3 state.py Paris
Unknown capital city
$> python3 state.py
$>
```
​
# Chapter 9
## Exercise 05: Search by key or value
​
<br>

| **Piscine**                | Exercise 05            |
| ---------------------------- | ----------------------------------------------------------------------------------- |
| Exercise 05 : Key 또는 Value로 찾기            |
| **제출할 폴더**              | ex05/            |
| **제출할 파일**                 | `all_in.py`         |
| **허용되는 함수**                   | `import sys`      |

<br>
​
이전 (ex03, ex04)에서 주어진 것과 똑같은 사전 자료형 값을 가지고 있습니다. 다시 한 번 값을 바꾸지 않은 채로 여러분의 프로그램 내 함수에 복사해넣으세요. 여러분은 다음과 같이 동작하는 프로그램을 작성하여야 합니다:

- 프로그램은 어떠한 양의 질문도 쉼표로 구분하여 받아들일 수 있는 문자열 하나를 인자로 받아야 합니다.

- 문자열 안의 각 질문들마다, 프로그램은 그 질문이 `주`를 의미하는지, `주도`를 뜻하는지, 어느 것도 아닌지 판별해야 합니다.

- 프로그램은 질문의 대소문자를 구별해서는 안됩니다. 띄어쓰기의 개수 또한 고려 대상이 아닙니다.

- 입력받은 인자가 없거나 너무 많다면 프로그램은 아무것도 출력해선 안됩니다.

- 문자열 내에 두 쉼표가 연속해서 나온다면, 프로그램은 아무것도 출력하지 않습니다.

- 프로그램은 결과를 `줄바꿈(CR)`으로 구별하여 출력해야 하며, 다음 양식에 엄격하게 맞아야 합니다:

```sh
$> python3 all_in.py "New jersey, Tren ton, NewJersey, Trenton, toto, , sAlem"
Trenton is the capital of New Jersey
Tren ton is neither a capital city nor a state
NewJersey is neither a capital city nor a state
Trenton is the capital of New Jersey
toto is neither a capital city nor a state
Salem is the capital of Oregon
$>
```
​
# Chapter 10
## Exercise 06: 사전 정렬하기
​
<br>

| **Piscine**                | Exercise 06            |
| ---------------------------- | ----------------------------------------------------------------------------------- |
| Exercise 06: 사전 정렬하기            |
| **제출할 폴더**              | ex06/            |
| **제출할 파일**                 | `my_sort.py`         |
| **허용되는 함수**                   | `N.A`      |

<br>
​
다음 딕셔너리를 여러분의 함수 중 하나에 집어넣으세요:

```python3
d = {
'Hendrix' : '1942',
'Allman' : '1946',
'King' : '1925',
'Clapton' : '1945',
'Johnson' : '1911',
'Berry' : '1926',
'Vaughan' : '1954',
'Cooder' : '1947',
'Page' : '1944',
'Richards' : '1943',
'Hammett' : '1962',
'Cobain' : '1967',
'Garcia' : '1942',
'Beck' : '1944',
'Santana' : '1947',
'Ramone' : '1948',
'White' : '1975',
'Frusciante': '1970',
'Thompson' : '1949',
'Burton' : '1939',
}
```

음악가들의 이름을 연도별 오름차순으로, 같은 해에 대해서는 알파벳 순으로 정렬하는 프로그램을 만드세요. 한 줄에 한 사람씩, 연도는 표기하지 않습니다.
​
# Chapter 11
## Exercise 07: 주기율표
​
<br>

| **Piscine**                | Exercise 07            |
| ---------------------------- | ----------------------------------------------------------------------------------- |
| Exercise 07: 주기율표            |
| **제출할 폴더**              | ex07/            |
| **제출할 파일**                 | `periodic_table.py`         |
| **허용되는 함수**                   | `import sys`      |

<br>

부록에 있는 `d01.tar.gz` _tarball_ 의 `ex07/` 서브폴더에는 주기율표를 프로그래머용 양식으로 적은 `periodic_table.txt` 파일이 있습니다.
​
이 파일을 이용하여 적절한 양식으로 주기율표를 표현하는 HTML 페이지를 만들어내는 프로그램을 작성하세요.

- 각 원소는 HTML 테이블(또는 표)의 '박스(또는 칸)' 내부에 있어야만 합니다.

- 원소들의 이름은 반드시 4단계 타이틀 헤더로 감싸져야 합니다. (`<h4>`)

- 원소들의 속성은 리스트로 표시되어야 합니다. 최소한 원자번호, 원자기호, 그리고 원자량이 표시되어야 합니다.

- 최소한 구글에 나오는 맨델레예브의 주기율표 구성에 따라야 합니다. 필요한 곳에는 빈 칸과 빈 줄바꿈(CR)이 있어야 합니다.

​
여러분의 프로그램은 결과 파일로 `periodic_table.html`을 생성해야 합니다. 이 파일은 어떤 브라우저에서도 읽을 수 있어야 하며 반드시 `3WC` 기준을 충족해야 합니다.
​

프로그램을 원하는 대로 자유롭게 작성하세요. 다시 쓸 것 같은 기능이 있다면 코드를 쪼개는 데에 망설이지 마세요. html 태그를 css "인라인" 스타일을 이용해 입맛대로 꾸미는 것도 가능합니다. (표 테두리 색 기능을 떠올려보세요). 원한다면 `periodic_table.css` 파일까지도 생성할 수도 있습니다.
​

아래는 여러분들에게 어떠한 방식으로 결과물 출력해야 할 지 감을 주기 위해 발췌한 출력 결과입니다.
Here is an excerpt of an output example that will give you an idea:

```html
[...]
    <table>
        <tr>
            <td style="border: 1px solid black; padding:10px">
                <h4>Hydrogen</h4>
                    <ul>
                        <li>No 42</li>
                        <li>H</li>
                        <li>1.00794</li>
                        <li>1 electron</li>
                    <ul>
    </td>
[...]
```
