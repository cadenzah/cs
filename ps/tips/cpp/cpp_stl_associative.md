# C++의 연관 컨테이너

## Index
- 개관 - 연관 컨테이너(Associative Container)
- 기본 자료형 이외의 데이터를 저장할 때
- STL에서 공통적으로 지원하는 동작들
- `set`
- `map`
  - `map`과 `unordered_map`
  - `pair`
    - `pair`에 대한 STL `.sort` 사용
- `multiset` / `multimap`
  - `.erase(key)`의 동작
  - `.equal_range(key)`

## 개관 - 연관 컨테이너(Associative Container)

> 상대적으로 Map, Set, Hash 등의 자료구조가 개념적으로 낯설어서 정리해본다

- **키**와 **값**처럼 관련있는 데이터를 하나의 쌍으로 저장하는 컨테이너.
- 요소 삽입시 컨테이너 내부의 값들과 비교하여 정렬된 위치에 저장 → **검색에 탁월한 이점**
  - *검색의 부담이 삽입 시점으로 이동한 셈*.
  - *삽입시 위치를 지정해주지 않아도 된다*; `map.insert(element);`
- 연관 컨테이너의 반복자는 **양방향 반복자**: 검색 및 순회 작업이 아주 빠르므로 임의 접근 필요 없음
- *키의 중복이 가능한지* 여부에 따라 일반 Map, Set과 Multimap, Multiset으로 나뉜다
- 검색, 삽입, 삭제 등의 속도: `logN`
- 내부적으로 Red-Black 트리를 사용하는 것이 일반적
  - `unordered_map` 등 C++11에서 추가된 해시 기반 컨테이너는 내부적으로 Hash Table을 사용

## 기본 자료형 이외의 데이터를 저장할 때
연관 컨테이너는 삽입 시점에 각 요소들을 정렬하여 유지하므로, 적절한 비교 방법을 정의해야 한다. 그래야 요소를 순회하며 제 자리를 찾을 때에 비교가 가능해진다.

- 컨테이너에 삽입할 **데이터의 자료형에서** `operator <`를 정의
- 함수 객체 타입을 정의하여 **컨테이너 객체 선언시** 전달

```cpp
struct Data {
  int value;
  Data(int _value) { value = _value; }
  bool operator < (const Data& _data) const {
    // 어떤 값을 기준으로 각 요소의 전후 위치를 비교할지 지정
    return value < _data.value;
  }
}
```

이때, 비교 연산자의 결과를 반환할 때 `==`를 사용하면 안 된다. 왜냐하면 연관 컨테이너에 삽입되는 요소는 원칙적으로 **중복될 수 없기 때문이다.** 만약 두 요소의 Key가 동일하지만 Value가 다른 경우, 이들이 중복으로 간주되지 않도록 반드시 구분되어야 한다.

```cpp
// 두 요소는 어떠한 경우이든 반드시 구분될 수 있어야 한다.
// 만약 이미 동일한 요소가 컨테이너에 들어있다고 판단되면, 해당 요소는 삽입되지 않는다.
struct Todo {
  int priority;
  string desc;
  Todo(int _priority, string& _desc) { priority = _priority; desc = _desc; }
  bool operator < (const Todo& _todo) const {
    if (todo.priority == _todo.priority) {
      // 동일한 우선순위의 요소를 서로 구분짓자
      return todo.desc < _todo.desc; // 같은 우선순위의 할일은 가나다 순으로 정렬
    } else {
      return todo.priority > _todo.priority; // 더 높은 우선순위의 할일이 앞에 온다
    }
    // 만약 동일한 우선순위와 설명을 가진 요소가 들어온다면, 이는 삽입되지 않고 무시된다.
  }
}
```

> 자세한 내용은 *strict weak ordering*을 검색해보자

또한, 비교 연산자에 사용되는 두 피연산자 - 위의 경우 `this`와 `_todo`가 `const`로 선언되어 전달되는 것에 유의하자. 연관 컨테이너가 비교 연산 수행시 사용하는 반복자는 **상수 반복자**이다. **이때, 상수 반복자가 가리키는 대상은 반드시 상수 데이터이어야 한다.**

## STL에서 공통적으로 지원하는 동작들
- `.insert(element)`: 삽입. 위치 지정 필요 없음에 유의
- `.find(element)`: 검색. 컨테이너 내의 위치를 반복자로 반환
- `.erase(element_iterator)`: 제거. 반복자로 위치 전달
- `.begin()` / `.end()`: 컨테이너의 시작과 끝+1을 가리키는 반복자 반환
- `.count(key)`: 인자로 전달된 `key`를 가지는 컨테이너 내 요소의 개수를 반환

## `Set`
- **집합** 생각하면 된다; 동일한 타입의 데이터를 모아놓은 것
- Key만 저장. 컨테이너 내에 해당 Key를 가진 요소의 존재 여부를 빠르게 알 수 있음

```cpp
#include <set>

template <class Key, class Compare = std::less<Key>,
          class Allocator = std::allocator<Key>>
class set { ... };

set<int> int_set;
set<int> int_set2(intCmp); // 별도의 비교 방법이 필요할 때, 함수 객체 형태로 2번째 인자 전달
```

## `map`
- Key-Value 쌍 형태로 저장.
- **반드시 `pair` 구조체의 값만 삽입할 수 있다.**

```cpp
#include <map>

template <class Key, class Value,
          class Compare = std::less<Key>,
          class Allocator = std::allocator<Value>>
class map { ... }

map<string, int> map1;
map<string, int> map2(mapCmp);
```

`map` 내의 요소는 반복자를 사용하여 접근하거나, `[Key]` 연산을 통하여 접근할 수 있다. 읽기/수정 모두 가능하다.

```cpp
map<int, string>::iterator itr = map1.find("안녕!");
itr->second = 100;
map1["안녕!"] = 200; // 해당 Key의 값이 컨테이너 내에 존재하지 않으면, 추가된다.
```

`[]` 연산의 경우 새로운 요소를 추가하는 것도 가능함에 유의하자. 같은 맥락에서, `[]`을 사용하여 존재하지 않는 Key의 값을 열람하려고 시도할 경우, **오류가 발생하지 않고** 해당 `second` 값의 자료형을 기준의 기본값이 추가되버린다. 디버깅에 유의하자.

```cpp
map1.insert(make_pair("존재하는 요소", 100); // 하나의 요소만 추가된 상태
cout << map1["존재하지 않는 요소"]; // 0; int 형의 기본값
```

### `pair` 구조체
- `키-값`의 데이터 형태를 나타내기 위한 구조체: JS의 속성이 1개인 Object를 생각하면 된다
  - `first`와 `second`를 통하여 각각의 값을 사용 가능
- `<utility>` 헤더에 포함: **STL의 다른 헤더를 사용하면 항상 포함**되어있다.

```cpp
#include <vector>
#include <string>
// #include <utility>

...

vector<pair<int, string>> list;
pair<int, string> element = make_pair(200, "나도 안녕!");

list.push_back(pair<int, string>(100, "안녕!"));
list.push_back(element);
cout << list[0].first; // 100
cout << list[0].second; // 안녕!
```

생성자를 사용하여 직접 임시 객체를 생성하거나, 생성자 래퍼 함수인 `make_pair`를 사용하면 된다.

#### `pair`에 대한 STL `.sort` 사용
- `first` 값을 기준으로 정렬되는 것이 기본값
- 조건자 함수를 별도로 정의하여 전달하면 다른 동작이 가능

## `multiset` / `multimap`
앞서 설명한 `set`과 `map`은 `Key`가 중복일 경우 삽입이 이루어지지 않는다. `multi-`가 붙은 연관 컨테이너들은 Key가 중복인 요소들의 삽입이 가능하다.

### `.erase(key)`의 동작
해당 `key` 인자에 대응하는 모든 요소를 제거

### `.equal_range(key)`
- 동일한 Key를 갖는 요소들을 모두 열람하고자 할 때 사용. 해당 Key를 인자로 전달.
- `pair<Itr, Itr>`를 반환하며, 두 값은 동일한 Key를 가지는 요소 여럿 중 **맨 처음 요소**, **맨 끝 요소**를 가리키는 반복자이다.

```cpp
#include <map>
#include <string>

...

multimap<string, int> list;
list.push_back(make_pair("하나", 1));
list.push_back(make_pair("하나", 2));
list.push_back(make_pair("하나", 3);

auto itrset = list.equal_range("하나");
for (auto itr = itrset.first ; itr != itrset.second ; itr++) {
  cout << itr->second << endl;
}
```


## Reference
- http://soen.kr
- https://modoocode.com/224
