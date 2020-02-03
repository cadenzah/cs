# CPP로 입력 다루기!

> 출력은 그냥 출력하면 되니까 다루지 않는다

## Index
- `cin`/`cout`의 성능 높이기
- 전체 길이를 컴파일 시간에 알 수 없을 때 입력 받아오기
  - 예시 1: 숫자 입력이 공백으로 구분될 때
  - 예시 2: 숫자 입력이 띄어쓰기 없이 한번에 올 때
  - 예시 3: 문자열 입력이 공백으로 구분될 때
- 전체 길이를 런타임에 알 수 없을 때 입력 받아오기
  - 예시 1: 숫자 입력이 들어올 때
  - 예시 2: 문자열 입력이 들어올 때
- 문자(열) 입력 받아오기
  - 공백(띄어쓰기 등)이 포함된 문자열을 받아야 할 때
  - `cin >> `과 `getline()`을 함께 사용할 때 주의
  - 문자열 내에서 특정 값들만 추출하기 (`.split()`)
- STL 컨테이너 사용시 유의
  - 복사 선언시 범위 지정

---

## `cin`/`cout`의 성능 높이기

> 출처: https://codecollector.tistory.com/381

C++의 `cin`/`cout`에 사용되는 스트림은 기본적으로 `printf`/`scanf`와 같은 C의 `stdio`와 버퍼를 함께 사용한다. C의 `stdio`를 사용하지 않을 것이라면 `cin`/`cout`만이 버퍼를 사용하도록, 그래서 사용되는 버퍼가 줄고 실행 속도가 향상될 수 있도록 조치해주어야 한다.

```cpp
using namespace std;

ios::sync_with_stdio(false);
cin.tie(NULL);
```

단, 이 코드를 실행한 후에는 `printf`/`scanf`/`getchar`/`gets` 등 `stdio`의 입출력 함수를 사용하면 안 된다.

## 전체 길이를 컴파일 시간에 알 수 없을 때 입력 받아오기
- 첫 줄에 입력 길이(k)를 주므로 이를 받아놓는다
- `<iostream>`의 `cin`을 사용
- 입력을 처리하기 위한 임시 변수(`temp`)를 사용한다
- `vector`를 사용하고, k번 루프를 돌려서 `v.push_back()` 식으로 받는다. 이 때, 입력이 어떻게 들어오는지가 중요하다.

### 예시 1: 숫자 입력이 공백으로 구분될 때

다음과 같은 입력에 대하여,

```bash
# https://www.acmicpc.net/problem/11022
5
1 1
2 3
3 4
9 8
5 2
```

- `cin`은 *공백(whitespace)이 있을 때* 입력 받기를 멈춘다.
  - 여기서 공백에는 줄바꿈, 띄어쓰기 모두 포함된다.
- 따라서, 위 입력은 다음과 같이 받으면 된다.

```cpp
#include<iostream>
using namespace std;
int main(void) {
  int count;
  int temp1, temp2;
  vector<int> sum;
  
  for (int i = 0 ; i < count ; i++) {
    cin >> temp1 >> temp2; // 매 루프마다 temp1과 temp2는 재활용된다
    sum.push_back(temp1 + temp2); // 각 줄마다의 값들을 더한 값을 vector에 추가한다
  }
}
```

- 여기서 강조하는 것은 여러 입력이 들어올 때에 어떻게 처리하는지이다.
- 입력 개수를 받아놓은 뒤, 각각의 입력을 받을 임시 변수를 활용하는 것이 핵심

### 예시 2: 숫자 입력이 띄어쓰기 없이 한번에 올 때
다음과 같은 입력을 생각해보자.
```bash
# 이 예시에서는 각 입력이 한자리 정수라고 가정한다
# https://www.acmicpc.net/problem/11720
5
54321
```

> 입력이 한자리 이상인 경우도 손쉽게 응용할 수 있다.

위 예시에서는 입력의 길이, 전체 숫자 문자열, 이렇게 2개의 입력을 받았다. 길이를 정확히 모르더라도 상관없다. 입력을 받은 뒤 길이를 구하면 그만이기 때문이다.

1. 해당 입력을 `string` 값으로 받는다.
2. 해당 입력값의 길이를 활용하여 입력 String 각각에 첨자로 접근한다.
3. 첨자로 접근한 각각의 문자는 `char` 자료형이므로, ASCII 코드로 사용 가능하다. 따라서, (각 문자 - `48`)로 해당 값을 `int`로 변환한다.

```cpp
for (int i = 0 ; i < count ; i ++) {
  int temp = input[i] - 48;
}
```


### 예시 3: 문자열 입력이 공백으로 구분될 때
- 예시 1과 마찬가지로, 공백을 기준으로 구분하여 받으면 된다

```cpp
#include<iostream>
#include<vector>
using namespace std;
int main() {
  int count; cin >> count;
  vector<string> str(count); // 정해진 개수 만큼의 입력을 받을 vector 선언
  for (int i = 0 ; i < count ; i++) {
    cin >> str[i];
  }
  
  for (int i = 0 ; i < count ; i++) {
    cout << str[i] << " ";
  }

  return 0;
}
```

```bash
# 예시 입력
4
Jack Johnson Jill Jude

# 예시 출력
Jack Johnson Jill Jude
```

## 전체 길이를 런타임에 알 수 없을 때 입력 받아오기
- 입력이 끝날 때까지 계속하여 입력을 받아서 처리해주어야 한다.
  - 입력 동작(Statement)이 조건문에서 평가(Expression)될 수 있음을 활용
- 입력에 EOF가 등장할 때까지 반복문을 계속 수행.

> 단, 입력이 끝나는 상황에서 어떤 식으로 처리되는지는 문제에 따라 다를 수 있다. 아래 코드는 백준 10951번 문제를 기준으로 유효한 풀이.

### 예시 1: 숫자 입력이 들어올 때
```cpp
// https://www.acmicpc.net/problem/10951
#include<iostream>
#include<vector>
using namespace std;

int main() {
  int temp1, temp2;
  while (cin >> temp1 >> temp2) {
    // 입력에 EOF가 들어있으면, -1로 평가되므로 종료
    cout << temp1 + temp2 << "\n";
  }

  return 0;
}
```

### 예시 2: 문자열 입력이 들어올 때
단어 단위로 들어오는 문자열 입력은 숫자와 동일하게 `cin`을 사용하여 처리한다.

공백으로 구분되는 장문 문자열이 입력되는 경우, `getline()`을 사용한다. 이때, `cin`과 마찬가지로 입력에 `EOF`가 들어있을 때 `-1`을 반환하므로 반복문의 조건 평가로 활용할 수 있다.

아래와 같은 입력 예시를 그대로 다시 출력하려면,
```bash
Hello
World!
Let's try something new!
```

아래와 같은 코드로 충분하다.

```cpp
// https://www.acmicpc.net/problem/11718 - 그대로 출력하기
#include <iostream>
using namespace std;

int main(void) {
  string input;

  while(getline(cin, input)) {
    cout << input << endl;
  }

  return 0;
}
```

## 문자(열) 입력 받아오기
- `string` 타입의 객체로 처리
- `cin` 객체와 `>>` 연산자를 통하여 처리
  - 공백(Whitespace: Enter, Space 등)에 따라 입력을 구분
  - 입력 버퍼에 대한 처리를 알아서 해준다.
- [전체 길이를 컴파일 시간에 알 수 없을 때, 문자열 입력이 공백으로 구분될 때] 참고

### 공백(띄어쓰기 등)이 포함된 문자열을 받아야 할 때
- `string`과 `getline()`을 함께 사용한다.
  - `getline(cin, str)` 식의 용법

```cpp
#include<iostream>
using namespace std;
int main(void) {
  string str;
  getline(cin, str);
  cout << str << endl;

  return 0;
}
```

### `cin >> `과 `getline()`을 함께 사용할 때 주의
- `cin`은 공백 문자를 발견했을 때 입력 버퍼로부터 입력을 받아오기를 멈추고 변수에 값을 대입한다.
- 그런데, 이때 공백 문자는 *그대로 입력 버퍼에 남아있게 된다*.
- 따라서, **입력 개수 등을 새는 목적**으로 `cin`을 사용한 뒤 `getline()`을 사용하는 경우, 반드시 *입력 버퍼를 비워주어야 한다.*

```cpp
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
  int count; cin >> count;   // 입력 문장의 개수 받기
  vector<string> str(count); // 문장을 저장할 vector 선언
  cin.ignore(256, '\n');     // 입력 버퍼 비우기

  for (int i = 0 ; i < count ; i++) {  
    getline(cin, str[i]);
  }
  for (int i = 0 ; i < count ; i++) {
    cout << str[i];
  }
}
```

### 문자열 내에서 특정 값들만 추출하기 (`.split()`)
입력들이 특정 문자를 기준으로 구분되어 들어올 때, 필요한 값들만 추출해내야 한다. 아래의 경우를 보자.
```bash
# 예시 입력 - baekjoon 10953
3
1,2
4,5
1,10
```

위의 입력에서 쉼표를 기준으로 앞과 뒤의 숫자를 추출하여 합을 구해야 한다. C++에는 `string` 타입에 `.split()`과 같은 메서드가 없으므로 이를 직접 구현하여야 한다.

```cpp
// 입력 받아오기
string temp;
cin >> temp;

comma_pos = temp.find(','); // 구분자 위치 얻어내기

// 숫자값 추출
string operand1_str;
// 첫번째 인자: 추출할 원본 문자열
// 두번째 인자: 원본 문자열에서 추출을 시작할 index
// 세번째 인자: 원본 문자열에서 index를 포함하여 추출할 문자의 개수
operand1_str.assign(temp, 0, comma_pos); // assign의 호출 대상 string에 대입
string operand2_str;
operand2_str.assign(temp, comma_pos + 1, temp.length() - comma_pos);

// 변환
int operand1 = stoi(operand1_str); // String to Int
int operand2 = stoi(operand2_str);
values[i] = operand1 + operand2;
```

## STL 컨테이너 사용시 유의

### 반복자를 사용한 범위 지정
STL의 반복자는 범위를 표기할 때 `[시작 위치 반복자, 끝 위치 반복자)`, 즉 **반 열린 구간**으로 표기하며, STL 컨테이너에서 범위를 활용한 작업 수행시 이러한 규칙을 사용한다.

따라서, `container.end()`는 컨테이너의 가장 마지막 요소 **다음**, 즉 **유효하지 않은 위치**를 가리키는 것이 일반적이다. 배열을 복사하여 컨테이너를 선언할 때에도 이러한 점을 유의하여 마지막 요소값이 누락되지 않도록 조심해야 한다.

```cpp
// https://www.acmicpc.net/problem/1924
const string _DAYS[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" }
vector<string> DAYS(&_DAYS[0], &_DAYS[7]);
```

위 코드에서 `&_DAYS[7]`은 유효하지 않은 위치이며, 실제 `DAYS` 벡터는 `&_DAYS[6]` 까지의 요소만을 포함하게 된다.

### Reference
- [[백준 BAEKJOON]10172번 개,11718번 그대로 출력하기 문제, 오답원인](https://jhnyang.tistory.com/128)
- [C언어 istream::getline()과 C++ string의 getline()! 한 줄 읽는 함수가 두 개?](https://jhnyang.tistory.com/107)
- [cstring vs string.h vs string 스트링클래스 차이](https://jhnyang.tistory.com/99)
- [C++ String 입력 받기](https://leeusin.tistory.com/418)
- [소프트웨어 공학 연구소](http://soen.kr)
