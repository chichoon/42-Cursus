# **D04 - Piscine Python-Django**

쟝고 - ORM

_요약: 오늘은 쟝고의 ORM에 대해 알아봅시다._

<br>

# Contents

| Chapter | Contents                                 | page |
| :-----: | :--------------------------------------- | :--: |
|    1    | [**Instructions**](#Chapter-1)           |  2   |
|    2    | [**Today's specific rules**](#Chapter-2) |  3   |
|    3    | [**Exercise 00**](#Chapter-3)            |  5   |
|    4    | [**Exercise 01**](#Chapter-4)            |  6   |
|    5    | [**Exercise 02**](#Chapter-5)            |  7   |
|    6    | [**Exercise 03**](#Chapter-6)            |  9  |
|    7    | [**Exercise 04**](#Chapter-7)            |  11  |
|    8    | [**Exercise 05**](#Chapter-8)            |  13  |
|    9    | [**Exercise 06**](#Chapter-9)            |  15  |
|    10    | [**Exercise 07**](#Chapter-10)            |  17  |
|    11   | [**Exercise 08**](#Chapter-11)            |  19  |
|    12    | [**Exercise 09**](#Chapter-12)            |  21  |
|    13    | [**Exercise 010**](#Chapter-13)            |  23  |

<br>

# **Chapter 1**

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

- `python3` 인터프리터를 사용하세요.

- 모든 과제는 독립적이어야 합니다. 만약에 요구하는 기능이 이전 과제에서 다뤄졌던 경우, 현재 과제 폴더에 복사해 오세요.

- 어플리케이션과 관련된 모든 경로들은 프로젝트 폴더 내의 `urls.py`에 정의되어 있어야 합니다.

- `djangotraining`이라 이름붙여진 `postgresql` 데이터베이스에서 작업하셔야 합니다. `djangouser`이라는 역할 (role) 을 생성하고, 비밀번호를 `secret` 이라 설정하세요. 해당 역할은 모든 권한을 가져야 합니다.

- 레포지토리 폴더가 곧 쟝고 프로젝트여야 합니다. 프로젝트명은 이번 과제 날짜 (ex: day05) 로 설정하여야 합니다.

- 각 과제 (exercises) 별로 분리하여 작업하기 위해 쟝고의 어플리케이션 콘셉트를 이용할 것입니다. 모든 과제는 각 과제명 (ex: ex00, ex01,...) 으로 이름지어진 쟝고 어플리케이션에 존재하여야 하고, 어플리케이션은 레포지토리의 루트 디렉토리에 있어야 합니다.

- 쟝고 프로젝트는 적절히 설정되어 과제의 모든 요구사항에 부합하여야 합니다. 평가 도중 설정을 건드리는 것은 금지됩니다.

- 과제의 어떤 migration도 제출할 수 없습니다.

- 각 과제별로 `ORM`을 언급하는 부분이 있다면, `Django`의 ORM을 사용하여야 합니다. `SQL`은 한 줄도 사용하지 마세요.

- 각 과제별로 `SQL`을 언급하는 부분이 있다면, `psycopg2` 라이브러리를 이용하여 `SQL`의 모든 리퀘스트를 처리하여야 합니다.

다음은 krichard라는 학생의 Day42 과제 2개에 대한 제출 폴더 구조입니다 :

```sh
|-- krichard
| |-- .
| |-- ..
| |-- .git
| |-- .gitignore
| |-- d42
| | |-- __init__.py
| | |-- settings.py
| | |-- urls.py
| | |-- wsgi.py
| |-- ex00
| | |-- admin.py
| | |-- apps.py
| | |-- forms.py
| | |-- __init__.py
| | |-- models.py
| | |-- tests.py
| | |-- urls.py
| | |-- views.py
| |-- ex01
| | |-- admin.py
| | |-- apps.py
| | |-- forms.py
| | |-- __init__.py
| | |-- models.py
| | |-- tests.py
| | |-- urls.py
| | |-- views.py
| |-- manage.py
```

```
💡
현명하게 작업하세요: 코드를 분석하여 사용하기 쉽게 구성하세요. 시간을 꽤 절약할 수 있을 겁니다.
```


<br>

# Chapter 3

## Exercise 00

<br>

| **Piscine**                  | Exercise 00                                                                      |
| ---------------------------- | -------------------------------------------------------------------------------- |
| Exercise 00 : SQL-표 만들기 |
| **제출할 폴더**              | ex00/                                                                            |
| **제출할 파일**              |    |
| **허용되는 함수**            |                                                        |

<br>

ex00이라는 이름의 쟝고 어플리케이션을 만들고, 다음 URL을 통해 접근 가능한 뷰를 만드세요 : `127.0.0.1:8000/ex00/init`

해당 뷰는 `psycopg2` 라이브러리를 이용하여 Postgresql로 이루어진 SQL 테이블을 생성하고, 생성에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

SQL 테이블은 다음과 같이 구현되어야 합니다:

- `ex00_movies` 라는 이름이어야 합니다.

- 테이블이 생성된 적 없을 때만 생성하여야 합니다.

- 다음 필드만을 포함하여야 합니다:

  - `title`: 독창적이면서 다양한 문자열, 64바이트 최대, null이 아닌 값

  - `episode_nb`: 꽉 찬, Primary key

  - `opening_crawl`: 텍스트, null 가능, 길이제한 없음

  - `director`: 다양한 문자열, null이 아닌 값, 32바이트 최대

  - `producer`: 다양한 문자열, null이 아닌 값, 128바이트 최대

  - `release_date`: 날짜 (시간 제외), null이 아닌 값

<br>

# Chapter 4

## Exercise 01

<br>

| **Piscine**                   | Exercise 01                                                                      |
| ----------------------------- | -------------------------------------------------------------------------------- |
| Exercise 01 : ORM-표 만들기 |
| **제출할 폴더**               | ex01/                                                                            |
| **제출할 파일**               |     |
| **허용되는 함수**             |                                                      |

<br>

두 번째 어플리케이션 `ex01`에 `Movies`라 이름붙여진 `Django` 모델을 만드세요.

- `title`: 독창적이면서 다양한 문자열, 64바이트 최대, null이 아닌 값

- `episode_nb`: 꽉 찬, Primary key

- `opening_crawl`: 텍스트, null 가능, 길이제한 없음

- `director`: 다양한 문자열, null이 아닌 값, 32바이트 최대

- `producer`: 다양한 문자열, null이 아닌 값, 128바이트 최대

- `release_date`: 날짜 (시간 제외), null이 아닌 값

해당 모델은 `title` 어트리뷰트를 다시 전송할 수 있도록 `__str__` 메소드를 재정의하여야 합니다.

<br>

# Chapter 5

## Exercise 02

<br>

| **Piscine**              | Exercise 02                                                                      |
| ------------------------ | -------------------------------------------------------------------------------- |
| Exercise 02 : SQL-데이터 삽입 |
| **제출할 폴더**          | ex02/                                                                            |
| **제출할 파일**          |      |
| **허용되는 함수**        |                               |

<br>

`Django` 어플리케이션 `ex02`를 만드세요. 해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex02/init`: `ex00`에서 요구한 것과 똑같은 특성을 가진 테이블을 만드세요. 단 이름은 `ex02_movies` 가 되어야 합니다.

  생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex02/populate`: 다음 데이터를 직전 뷰에서 만든 테이블에 삽입하세요.

  - episode_nb: 1 - title: The Phantom Menace - director: George Lucas - producer: Rick McCallum - release_date: 1999-05-19

  - episode_nb: 2 - title: Attack of the Clones - director: George Lucas - producer: Rick McCallum - release_date: 2002-05-16

  - episode_nb: 3 - title: Revenge of the Sith - director: George Lucas - producer: Rick McCallum - release_date: 2005-05-19

  - episode_nb: 4 - title: A New Hope - director: George Lucas - producer: Gary Kurtz, Rick McCallum - release_date: 1977-05-25

  - episode_nb: 5 - title: The Empire Strikes Back - director: Irvin Kershner - producer: Gary Kurtz, Rick McCallum - release_date: 1980-05-17

  - episode_nb: 6 - title: Return of the Jedi - director: Richard Marquand - producer: Howard G. Kazanjian, George Lucas, Rick McCallum - release_date: 1983-05-25

  - episode_nb: 7 - title: The Force Awakens - director: J. J. Abrams - producer: Kathleen Kennedy, J. J. Abrams, Bryan Burk - release_date: 2015-12-11

  생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex02/display`: `ex02_movies` 테이블에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요. 최종적으로 공백인 필드 (void field) 도 포함하여 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

<br>

# Chapter 6

## Exercise 03
​
<br>

| **Piscine**                       | Exercise 03                                                                      |
| --------------------------------- | -------------------------------------------------------------------------------- |
| Exercise 03 : ORM-데이터 삽입 |
| **제출할 폴더**                   | ex03/                                                                            |
| **제출할 파일**                   |       |
| **허용되는 함수**                 |                         |

<br>

`Django` 어플리케이션 `ex03`을 만드세요. 어플리케이션 내에는 `ex01`에서 요구한 것과 똑같은 특성을 가진 테이블을 만드세요.

해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex03/populate`: 다음 데이터를 직전 뷰에서 만든 테이블에 삽입하세요.

  - episode_nb: 1 - title: The Phantom Menace - director: George Lucas - producer: Rick McCallum - release_date: 1999-05-19

  - episode_nb: 2 - title: Attack of the Clones - director: George Lucas - producer: Rick McCallum - release_date: 2002-05-16

  - episode_nb: 3 - title: Revenge of the Sith - director: George Lucas - producer: Rick McCallum - release_date: 2005-05-19

  - episode_nb: 4 - title: A New Hope - director: George Lucas - producer: Gary Kurtz, Rick McCallum - release_date: 1977-05-25

  - episode_nb: 5 - title: The Empire Strikes Back - director: Irvin Kershner - producer: Gary Kurtz, Rick McCallum - release_date: 1980-05-17

  - episode_nb: 6 - title: Return of the Jedi - director: Richard Marquand - producer: Howard G. Kazanjian, George Lucas, Rick McCallum - release_date: 1983-05-25

  - episode_nb: 7 - title: The Force Awakens - director: J. J. Abrams - producer: Kathleen Kennedy, J. J. Abrams, Bryan Burk - release_date: 2015-12-11

생성에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex03/display`: `movies` 테이블에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요. 최종적으로 공백인 필드 (void field) 도 포함하여 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

```
ℹ️
평가 시에는, migration이 테스트 전에 이루어질 것입니다.
```

<br>

# Chapter 7

## Exercise 04
​
<br>

| **Piscine**                       | Exercise 04                                                                      |
| --------------------------------- | -------------------------------------------------------------------------------- |
| Exercise 04 : SQL-데이터 삭제 |
| **제출할 폴더**                   | ex04/                                                                            |
| **제출할 파일**                   |       |
| **허용되는 함수**                 |                         |

<br>

`Django` 어플리케이션 `ex04`를 만드세요. 해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex04/init`: `ex00`에서 요구한 것과 똑같은 특성을 가진 테이블을 만드세요. 단 이름은 `ex04_movies` 가 되어야 합니다.

  생성에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex04/populate`: `ex02`에서 명시된 데이터를 직전 뷰에서 만든 테이블에 삽입하세요.

  지워진 데이터를 모두 재삽입하여야 합니다.

  삽입에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex04/display`: `ex04_movies` 테이블에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요. 최종적으로 공백인 필드 (void field) 도 포함하여 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

- `127.0.0.1:8000/ex04/remove`: 영화 제목을 `submit` 버튼, `remove` 버튼과 함께 드랍다운 리스트로 출력하는 `HTML` 페이지를 표시하세요.

  영화 제목들은 `ex04_movies` 테이블에 있는 제목을 가져오시면 됩니다.

  폼의 유효성이 검사된 후, 선택한 영화는 데이터베이스에서 지워지고, 폼은 남은 영화 제목으로 업데이트된 리스트를 다시 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

<br>

# Chapter 8

## Exercise 05
​
<br>

| **Piscine**                       | Exercise 05                                                                      |
| --------------------------------- | -------------------------------------------------------------------------------- |
| Exercise 05 : ORM-데이터 삭제 |
| **제출할 폴더**                   | ex05/                                                                            |
| **제출할 파일**                   |       |
| **허용되는 함수**                 |                         |

<br>

`Django` 어플리케이션 `ex05`를 만드세요. `ex01`에서 요구한 것과 똑같은 모델을 만드세요. 해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex05/populate`: `ex03`에서 명시된 데이터를 직전 뷰에서 만든 테이블에 삽입하세요.

  지워진 데이터를 모두 재삽입하여야 합니다.

  삽입에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex05/display`: `movies` 모델에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요. 최종적으로 공백인 필드 (void field) 도 포함하여 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

- `127.0.0.1:8000/ex05/remove`: 영화 제목을 `submit` 버튼, `remove` 버튼과 함께 드랍다운 리스트로 출력하는 `HTML` 페이지를 표시하세요.

  영화 제목들은 `movies` 모델에 있는 제목을 가져오시면 됩니다.

  폼의 유효성이 검사된 후, 선택한 영화는 데이터베이스에서 지워지고, 폼은 남은 영화 제목으로 업데이트된 리스트를 다시 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

```
ℹ️
평가 시에는, migration이 테스트 전에 이루어질 것입니다.
```

<br>

# Chapter 9

## Exercise 06
​
<br>

| **Piscine**                       | Exercise 04                                                                      |
| --------------------------------- | -------------------------------------------------------------------------------- |
| Exercise 06 : SQL-데이터 업데이트 |
| **제출할 폴더**                   | ex06/                                                                            |
| **제출할 파일**                   |       |
| **허용되는 함수**                 |                         |

<br>

`Django` 어플리케이션 `ex06`을 만드세요. 해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex06/init`: `ex00`에서 요구한 것과 똑같은 특성을 가진 테이블을 만드세요. 단 이름은 `ex06_movies` 가 되어야 하고, 다음과 같은 추가 필드를 포함해야 합니다:

  - `created` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되어야 합니다.

  - `updated` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되어야 합니다. 또한 다음과 같은 트리거를 이용하여 자동으로 현재 시간과 날짜로 업데이트되어야 합니다.

  ```sql
  CREATE OR REPLACE FUNCTION update_changetimestamp_column()
  RETURNS TRIGGER AS $$
  BEGIN
  NEW.updated = now();
  NEW.created = OLD.created;
  RETURN NEW;
  END;
  $$ language 'plpgsql';
  CREATE TRIGGER update_films_changetimestamp BEFORE UPDATE
  ON ex06_movies FOR EACH ROW EXECUTE PROCEDURE
  update_changetimestamp_column();
  ```

- `127.0.0.1:8000/ex06/populate`: `ex02`의 테이블에 직전 뷰에서 만든 테이블의 데이터를 붙이세요.

  삽입에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex06/display`: `ex06_movies` 테이블에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

- `127.0.0.1:8000/ex06/update`: 폼의 송신과 수신을 관리해야 합니다. 후자는 `ex06_movies`의 영화들을 드랍다운 메뉴로 구성하여 선택하고, 두 번째 필드에 텍스트를 적을 수 있어야 합니다. 폼의 유효성이 검사될 때, 뷰는 선택한 영화의 `opening_crawl` 필드를 `ex06_movies` 테이블의 폼에 작성한 텍스트로 대체하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

<br>
