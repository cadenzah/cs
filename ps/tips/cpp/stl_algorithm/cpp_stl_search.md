# C++ STL Algorithms - Search

## Index
- `find` / `find_if` / `search`
- `binary_search`
- `upper_bound` / `lower_bound`

## `find`
컨테이너에서 주어지는 범위를 순회하며 전달된 인자와 일치하는 요소를 찾고, 해당 요소의 위치를 반복자로 반환한다. 일치 여부는 `==` 연산자만을 사용함에 유의.

> 만족하는 값을 발견하지 못했다면, container.end()를 반환한다.

```cpp
vector<int> list(10);
vector<int>::iterator itr = find(list.begin(), list.end(), 5);
cout << *itr;
```

## `find_if`
`find` 함수와 동일하지만, 별도의 비교 방법을 제공하고자 할 때 사용. 세번째 인자로 이항 비교 함수 객체를 전달한다.

> 만족하는 값을 발견하지 못했다면, container.end()를 반환한다.

## `search`
컨테이너에서 주어지는 범위(`original`)를 순회하며 인자로 전달된 컨테이너 범위(`query`)의 내용이 존재하는지 확인. 존재한다면, 해당 내용이 처음으로 발견된 위치의 반복자를 반환.

```cpp
vector<int> original(50); // { 1, 5, 3, 6, 23, 3, 2, 5, 8, 3, 3, 2, 11, 64, 3, ... };
vector<int> query(4); // { 3, 2, 5, 8 }

vector<int>::iterator itr = search(original.begin(), original.end(), query.begin(), query.end());
cout << *itr; // original.begin() + 5
```

> 만족하는 값을 발견하지 못했다면, container.end()를 반환한다.

내부적으로 `==` 연산자를 사용하여 부분 컨테이너를 검사하므로, 별도의 비교 방법을 전달하려면 다섯번째 인자로 이항 비교 함수 객체를 전달하면 된다.

## `binary_search`
컨테이너에서 주어지는 범위를 순회하며 전달된 인자와 일치하는 값을 찾는다. 찾고자 하는 값이 존재하는지 여부를 `boolean` 값으로 반환한다. 이 때, **대상 컨테이너는 정렬된 상태이어야 한다.**

```cpp
vector<int> list(n);
int target;

sort(list.begin(), list.end());
bool result = binary_search(list.begin(), list.end(), target);
```

## `upper_bound` / `lower_bound`
이름에서 알 수 있듯 **상/하한선**을 확인하는 함수이다. 인자로 전달되는 값을 기준으로 상한선과 하한선을 가리키는 **반복자**를 반환한다. 이때, 상한선이란 인자로 전달되는 값보다 **큰 값**이 시작되는 지점(`value` < `*upper_bound_itr`)이며, 하한선이란 인자로 전달되는 값보다 **크거나 같은 값**이 시작되는 지점(`*lower_bound_itr` <= `value`)이다.

이 함수들이 사용되는 컨테이너들은 반드시 **정렬된 상태**이어야 한다. 그래야 이진 탐색의 이득을 누릴 수 있기 때문.

```cpp
vector<int> list; // { 1, 2, 3, 4, 5, 5, 6, 7, 8}
vector<int>::iterator itr = lower_bound(list.begin(), list.end(), 5); // list.begin() + 4
```

값을 비교하기 위하여 내부적으로 비교 연산자가 사용되므로, 별도의 비교 방법을 전달하려면 호출시 4번째 인자로 비교 함수 객체를 전달하거나, 컨테이너에 저장되는 요소 타입에 `<` 연산자를 재정의하면 된다.
