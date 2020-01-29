# String과 Int 간의 변환

## Index
- `String` → `Int`
- `Int` → `String

## `String` → `Int`
`std::stoi` 함수를 사용하여 변환 가능하다.

```cpp
using namespace std;
string before = "1234";
int after = stoi(before);
printf("%d\n", after);
```

## `Int` → `String`
`std::to_string` 함수를 사용하여 변환 가능하다.

```cpp
using namespace std;
int before = 1234;
string after = to_string(before);
printf("%s\n", after);
```
