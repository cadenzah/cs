# String과 Int 간의 변환

## Index
- `String` → `Int`
- `Int` → `String
- ASCII `Int` → `String`
- `char` → `Int`
  - ASCII Code Table

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

## ASCII `Int` → `String` / `char` → `String`
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

## `char` → `Int`
문자열로 표기된 자리수를 `int`형 숫자로 바꿀 때 역시 ASCII값을 기반으로 변환한다. 모든 한자리 정수는 '0'을 기준으로 1씩 증가한다는 점을 이용하면 직관적으로 코드를 작성할 수 있다.

```cpp
char digit = '0' // 내부적으로 48
cout << digit - 48; // 0
cout << digit - '0'; // 0
```

### `\x`
- 16진수를 가리킨다.
