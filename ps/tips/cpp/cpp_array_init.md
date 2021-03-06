# C++ 배열의 초기화 팁

## Index
- 1. (추천) `memset`을 이용한 초기화
- 2. `vector`를 이용한 초기화
- 3. `for` 문
- 3. `std::fill_in`

### 1. `memset`을 이용한 초기화
동적 계획법 문제를 풀 때, Cache 배열을 초기화할 때 빠르게 그리고 간단하게 초기화할 수 있는 방법이다. `-1`를 1Byte 단위로 표기했을 때 2의 보수법에 의하여 `0x1111`로 표기되는 현상을 활용하는 방법이다.

```cpp
#include <cstring> // 헤더 포함을 잊지 말자

int cache[101];
int cache2[101][101];

// 대상 배열의 주소, 초기화할 값, 배열의 크기
// 지정된 영역을 1Byte 단위로 초기화
memset(cache, -1, sizeof(cache));
memset(cache2, -1, sizeof(cache2));
```

3번째 인자에는 배열 차원에 무관하게 `sizeof(cache)`를 사용한 것에 유의한다.

### 2. `vector`을 이용한 초기화

```cpp
#include <vector>

vector<int> cache(N, 0);
vector<vector<int> > cache2(N, vector<int>(M, 0));
```

초기화용 값에도 재귀적인 느낌으로 `vector` 인스턴스를 넣어줄 수 있음에 유의하자.
