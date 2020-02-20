# STL 내장 `sort` 사용하기

## index
- 내림차순 정렬 (기본값)
- 정렬 방식 변경하기
- 조건자 함수 정의하여 사용하기

## 내림차순 정렬
- `sort` 함수의 기본 작동 방식은 오름차순이다. 
- `string`의 경우, 각각의 문자들이 대문자부터, 가나다순으로 정렬된다. ASCII 코드값 기준임을 알 수 있다.
  - 'A': 65 / 'a': 97

```cpp
#include <string>
#include <algorithm>

string s = "abcDEF";
sort(s.begin(), s.end()); // "DEFabc"
```

## 정렬 방식 변경하기
- `sort`의 세번째 인자로 조건자 함수를 전달할 수 있다. 생략시 기본값으로 `less<T>`가 전달되며 **좌변이 우변보다 작을 때 참인 오름차순 정렬**이 이루어진다. 기본값 이외의 작동이 필요하다면 별도의 조건자를 전달해주어야 한다.
- 조건자는 `<algorhtm>` 헤더에 포함되어있다.

```cpp
sort(s.begin(), s.end(), greater<int>());
```

위의 경우 `>` 연산자를 사용하여 내림차순 정렬이 이루어짐을 알 수 있다.

## 조건자 함수 정의하여 사용하기
- 컨테이너 내의 요소를 임의로 정렬하려면 조건자 함수를 직접 정의해주어야 한다.
- [38-1-가. 함수 객체](http://soen.kr/) 페이지를 참조하였다.

```cpp
struct compare{
  int index;
  compare(int _index) { index = _index; }
  
  bool operator() (const string& a, const string& b) {
    if (a[index] >= b[index]) return true;
    else return false;
  }
};

...

string _list[] = { "abc", "cab", "dee" };
vector<string> list(_list.begin(), _list.end());
sort(list.begin(), list.end(), compare(index));
```
