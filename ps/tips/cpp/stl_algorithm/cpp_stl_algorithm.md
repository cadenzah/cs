# C++ STL Algorithms

## Index
- 일반적인 특징
  - 컨테이너 독립적으로 구현된 내부
  - 반복자를 통한 범위 지정
  - 반 열린 구간
- `unique`
- `nth_element`
- `max` / `min`
- `max_element` / `min_element`
- `swap`
- `merge`

## 일반적인 특징

> `<algorithm>` 헤더 필요

### 1. 컨테이너 독립적으로 구현된 내부
반복자를 통하여 컨테이너의 각 요소에 접근한다는 동일한 인터페이스가 이용될 수 있도록 템플릿으로 구현된다.

### 2. 반복자를 통한 범위 지정
1번의 특징에 따라, 각 함수를 호출할 때 컨테이너의 요소들을 순회할 수 있는 반복자를 전달해주어야 한다.

### 3. 반 열린 구간
2번과 같이 범위를 지정할 때, 아래와 같은 반 열린 구간을 사용하여 범위를 표기한다.

```
begin <= i < end
```

반 열린 구간의 장점은 다음과 같다:
- `end - begin`으로 구간 길이(크기)를 쉽게 계산 가능
- 공집합을 표현할 수 있다 (`begin == end`)
- 두 구간의 연속 여부를 쉽게 확인
    > [b1, e1)와 [b2, e2)의 연속을 확인하려면, e1 == b2 또는 b1 == e2 여부만 확인하면 된다

## `unique`
컨테이너의 주어지는 범위를 쭉 순회하며 연속으로 존재하는 요소를 컨테이너의 맨 뒤로 보낸다. 그 후, 중복되어 배제된 요소가 시작되는 위치의 반복자를 반환한다. **중복을 배제할 대상 컨테이너의 요소들은 반드시 정렬된 상태이어야 한다.**

```cpp
vector<int> numbers; // { 1, 1, 2, 3, 4, 4, 5, 6 }
vector<int>::iterator duplicate = unique(numbers.begin(), numbers.end());

cout << numbers // { 1, 2, 3, 4, 5, 6, 1, 4 }
cout << numbers.begin() + 6 == duplicate // true
```

중복된 요소는 제거되지 않고 그대로 원본 배열에 남아있으므로, `unique`의 반환값인 반복자를 활용한다.

## `nth_element` (수정 필요)
컨테이너의 요소들을 특정 요소의 값(n번째)을 기준으로 컨테이너 내에서 두 부분으로 나눈다. 컨테이너 정렬의 결과는 `elements < A[i] <= elements` 조건을 만족한다. 이때 지정되는 특정 요소의 반복자는 **해당 컨테이너를 정렬하였을 때를 기준으로** 그 위치를 나타낸다. 

```cpp
vector<int> list(10); // { 1, 1, 2, 7, 8, 9, 0, 3, 4, 3 };

// 정렬된 list의 요소 중, 맨 앞에서 5번째 위치에 존재하는 요소 기준으로 파티셔닝
// { 0 1 1 2 3 "3" 4 7 8 9 }
nth_element(list.begin(), list.begin() + 5, list.end());
for (int i = 0 ; i < list.size() ; i++) cout << list << " ";
// 최종 결과: { 1 1 2 0 3 3 4 7 8 9 }
```

병합 정렬의 Divide를 연상하자.

## `max` / `min`
인자로 주어지는 두 수 중 최대값/최소값을 반환한다. 내부적으로 대소 비교가 이루어지므로, 기본 자료형이 이외의 구조체 등을 사용한다면 적절하게 비교 연산자를 재정의하거나, 세번째 인자로 비교 연산자를 전달한다.

```cpp
template <class T> const T& max (const T& a, const T& b) {
  return (a<b)?b:a;     // or: return comp(a,b)?b:a; for version (2)
}

int a, b;
int ret = max(a, b)
```

## `max_element` / `min_element`
컨테이너에서 가장 큰/작은 요소를 가리키는 반복자를 반환한다. 내부적으로 대소 비교가 이루어지므로, 기본 자료형이 이외의 구조체 등을 사용한다면 적절하게 비교 연산자를 재정의하거나, 세번째 인자로 비교 연산자를 전달한다.

```cpp
struct Person {
  int age;
  string name;
  Person(int _age, string& _name) { age = _age; name = _name; }
  bool operator < (Person& a, Person& b) {
    return a.age < b.age;
  }
};

vector<Person> list(10);
vector<Person>::iterator elderly = max_element(list.begin(), list.end());
```

## `swap`
두 변수 값을 서로 교환한다.

```cpp
int a=2, b=4;
swap(a, b);
```

## `merge`
(작성 예정)


## Reference
- [cplusplus.com](http://www.cplusplus.com/reference/algorithm)
