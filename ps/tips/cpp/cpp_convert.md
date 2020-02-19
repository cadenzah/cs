# String과 Int 간의 변환

## Index
- `String` → `Int`
- `Int` → `String
- ASCII `Int` → `String`
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

## ASCII `Int` → `String`
해당 정수값을 기반으로 새로운 `string` 타입 객체를 임시로 생성한다.

```cpp
int digit = 65; // 'A'
string s(1, digit);
```

> - 알파벳은 각각 26문자, 총 52문자이다
> - 대문자: 65 ~ 90 / 소문자: 97 ~ 122

### `\x`
- 16진수를 가리킨다.
