# String과 Int 간의 변환

## Index
- `String` → `Int`
- `Int` → `String
- ASCII `Int` → `String`
  - ASCII Code Table
- 숫자의 자료형 변환
  - `char` → `Int`
  - 자릿수 추출하기

## `String` → `Int`
`std::stoi` 함수를 사용하여 변환 가능하다.

```cpp
using namespace std;
string before = "1234";
int after = stoi(before);
printf("%d\n", after);
```

> ### 어떤 String이 정수인지 확인하려면
> `isDigit()`을 활용하자

## `Int` → `String`
`std::to_string` 함수를 사용하여 변환 가능하다.

```cpp
using namespace std;
int before = 1234;
string after = to_string(before);
printf("%s\n", after);
```

## ASCII 값에 대응하는 문자를 `String`으로 변환하기 `Int` → `String` / `char` → `String`
해당 정수값을 기반으로 새로운 `string` 타입 객체를 임시로 생성한다.

```cpp
int digit = 65; // 'A'
string s(1, digit);

string answer = "";
answer = answer + string(1, digit);
```

> **TIP**: 알파벳은 각각 26문자, 총 52문자이다
> - 대문자: 65 ~ 90 / 소문자: 97 ~ 122

C의 `char` 또한 내부적으로 정수값이므로 이러한 변환 과정을 동일하게 사용하여 `string` 타입의 값으로 젼환할 수 있다.

## 문자의 ASCII 값 추출하기
`char` 타입으로 받은 뒤, `int` 타입으로 형변환한다.

```cpp
...
char input;
cin >> input;
cout << (int) input;
```

## 숫자의 자료형 변환

### `char` → `Int`
문자열로 표기된 자리수를 `int`형 숫자로 바꿀 때 역시 ASCII값을 기반으로 변환한다. 모든 한자리 정수는 '0'을 기준으로 1씩 증가한다는 점을 이용하면 직관적으로 코드를 작성할 수 있다.

```cpp
char digit = '0' // 내부적으로 48
cout << digit - 48; // 0
cout << digit - '0'; // 0
```

### 각 자릿수값을 정수 배열로 추출하기

> - 예를 들어, `int` 값의 각 자릿수를 개별적으로 접근할 때
> - 간혹가다 헷갈려서 정리
> - (자료형의 크기는 딱히 무관하다)

각 자릿수를 나머지 연산하면서 배열에 차곡차곡 저장한다. 이때, 10으로 나눠주면서 한 자리씩 시프트한다.

```cpp
long long int VALUE = 12345678987654;
vector<int> digits;

while (VALUE / 10 != 0 || VALUE % 10 != 0) {
  digits.push_back(VALUE % 10);
  VALUE /= 10;
}
```

- 10으로 나눈 몫은 곧 다음 단계에서 사용된다
- 10으로 나눈 나머지는 해당 단계의 자릿값
- 10으로 나눈 몫이 0이라는 것은 VALUE가 한 자리 수라는 의미
- 10으로 나눈 나머지도 0이면 모든 자릿값을 추출했다는 의미

이후 각 자릿값들을 기반으로 다시 새로운 값을 완성해야 한다면, 나누는 대신 **곱해주면서** 역순으로 진행해주면 된다.

```cpp
VALUE += digits[0]; // 맨 앞자리값
for (int i = 1 ; i < digits.size() ; i++) {
  // 맨 앞자리의 다음부터 진행
  VALUE = VALUE * 10 + digits[i];
}
```

### `\x`
- 16진수를 가리킨다.
