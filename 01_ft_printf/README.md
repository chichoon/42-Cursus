# printf 함수 구현하기
항상 애용하던 우리의 친구 printf를 직접 구현하시오  

#### 구현해야 하는 Conversions
- **c** : char (문자 한 개 : a)
- **s** : string (문자열 : asdf)
- **p** : pointer (주소값 : 0x00c12049ffffad15)
- **d** : decimal (부호있는 정수 : 123, -344, 10진수)
- **i** : integer (부호있는 정수 : -555, 235, 10 / 8 / 16진수 모두 입력받음)
- **u** : unsigned (부호없는 정수 : 123, 355, 10진수)
- **x** : unsigned hexadecimal (부호 없는 16진수 : 0x5f, 소문자)
- **X** : unsigned hexadecimal (부호 없는 16진수 : 0x5F, 대문자)

#### 보너스 Conversions
- nfge
- **n** : 
- **f** : float (부동소수 : 0.124)
- **g** : float (부동소수 : 1.20000 과 1.20000e+00 중 짧은것 사용, 대문자)
- **e** : float (실수 : 0.1240000e+10)