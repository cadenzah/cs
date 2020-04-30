# STL 내장 `sort` 사용하기

## index
- 정렬 범위
- 오름차순 정렬 (기본값)
- 정렬 방식 변경하기
- 조건자 함수 정의하여 사용하기
  - 문제에서 제시한 비교 조건을 정확히 구현하자

> `<algorithm>` 헤더 필요

## 정렬 범위
`sort`에 전달하는 첫번째 및 두번째 인자가 대상 컨테이너 내에서 정렬이 이루어질 범위를 지정한다. 대상 컨테이너에 대한 반복자를 전달하면 된다. **특정 구간만이 정렬되도록 지정해줄 수도 있음을 유의하자**.

```cpp
#include <algorithm>

...
vector<int> list; // { 1, 2, 6, 5, 4, 3, 8 }
sort(list.begin() + 2, list.end() - 2); // { 1, 2, "4, 5, 6", 3, 8 }
```

## 오름차순 정렬
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

위의 경우 `>` 연산자를 사용하여 내림차순 정렬이 이루어짐을 알 수 있다. 표준 라이브러리에서 제공하는 조건자는 함수 객체이므로, 생성자 호출로 객체를 생성해주어야 함(`()`연산자 사용)에 주의한다.

## 조건자 함수 정의하여 사용하기
- 컨테이너 내의 요소를 임의로 정렬하려면 조건자 함수를 직접 정의해주어야 한다.
- [38-1-가. 함수 객체](http://soen.kr/) 페이지를 참조하였다.

```cpp
struct compare{
  int index;
  compare(int _index) { index = _index; }
  
  const bool operator() (const string& a, const string& b) {
    if (a[index] >= b[index]) return true;
    else return false;
  }
};

...

string _list[] = { "abc", "cab", "dee" };
vector<string> list(_list.begin(), _list.end());
sort(list.begin(), list.end(), compare(index));
```

- `vector`의 요소로 구조체를 사용한다면, 해당 구조체와 조건자 함수를 위한 구조체를 **별도로 작성**하는 편이 구현이 용이하다.

### 문제에서 제시한 비교 조건을 정확히 구현하자
구현 문제의 경우 대소 비교 조건을 문제에서 제시하는 경우가 많다. 이를 제대로 다루지 않는다면 제대로 처리되지 못하는 경우가 발생할 수 있으므로 주의가 필요하다. 아래의 예를 보자.

```cpp
// 백준 11651 문제
struct comparer {
  const bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second < b.second) return a.second < b.second;
    else return a.first < b.first;
  }
};
```

2차원 좌표평면 상의 두 정점을 비교하기 위한 조건자 함수이다. 문제에서 주어진 조건은 우선 *y 좌표의 오름차순*으로 정렬한 뒤, 만약 y 좌표가 같다면 *x 좌표의 오름차순*으로 정렬을 하는 것이다.

당연히 위의 코드는 제대로 작동하지 않는다. 모든 경우를 포괄하지 않는다. 첫번째 조건문 이후의 `else`에서 반환하는 결과는 **y 좌표가 같은 경우**에만 해당되어야 하는데, `a.second > b.second`인 경우도 포함할 것이다. 이 경우는 제외되어야 한다.

아래와 같은 식으로 작성한 것이 정답이다.

```cpp
struct comparer {
  const bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second < b.second) return true;
    else if (a.second == b.second) {
      if (a.first < b.first) return true;
    }
    return false;
  }
};
```

또한, 조건자 함수를 사용한다는 것은 내장 자료형이 아닌 임의로 정의된 자료형의 비교를 수행한다는 의미이다. 따라서, 해당 자료형으로부터 만들어낼 수 있는 모든 경우들에 대하여 대소 관계가 명확하게 갈리도록 조건자 함수가 정의되어야 한다.
