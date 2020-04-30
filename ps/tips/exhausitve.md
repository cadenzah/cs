# 완전 탐색 (Brute-force)

> 문제를 읽어 보고, 모든 경우를 볼 수 있을 만한 입력 크기인지 확인해보자.
> 
> 효율적인 기법을 사용하지 않고 모든 경우를 다 확인해보더라도 괜찮다면, 완전 탐색으로도 충분하다.

## Index

- 기저 사례(Base case)
- 핵심 1: 모든 경우의 수를 모두 따져본다
- 핵심 2: 현재 단계를 기준으로 재귀한 후, 현재 작업한 것을 무효화
- 2차원 상에서의 완전 탐색
- 최적해 찾기

## 기저 사례(Base case)

## 핵심 1: 모든 경우의 수를 모두 따져본다

> 각 경우는 모두 하나의 **선택지**

한 단계마다 m개의 선택지가 존재하고, n번의 단계가 존재할 때, *1단계에서 1을 고른 뒤 n-1번의 단계 반복*하는 경우 + *2단계에서 2를 고른 뒤 n-1번의 단계 반복*하는 경우 + ...

```cpp
int solve(int n, int depth, ...) {
  if (depth == n) { /* 하나의 경우가 완성이 되었다 */ }
  int ret = MAX_VALUE;
  for (int i = 0 ; i < 4 ; i++) { // 한 단계에서 4가지 선택이 가능할 때
    { ... } // 하나의 선택을 했음을 기록
    ret = min(ret, solve(n, depth + 1, ...));
    { ... } // 방금 수행한 선택을 해제
  }
}
```

## 핵심: 현재 단계를 기준으로 재귀한 후, 현재 작업한 것을 무효화
현재 단계에서 수행한 것은 현재 단계가 종료된 뒤 - 즉, 상위 Depth로 복귀했을 때 - 에는 사라져야 한다. 그래야 모든 경우의 수를 사용하여 완전 탐색할 수 있다.

> 중복이 없도록!

```cpp
// 종만북 코드 6.2
void pick(int n, vector<inv>& picked, int toPick) {
  if (toPick == 0) { printPicked(picked); return; }
  int smallest = picked.empty() ? 0 : picked.back() + 1;

  for (int next = smallest ; next < n ; next++) {
    picked.push_back(next);
    pick(n, picked, toPick - 1);
    picked.pop_back();
  }
}
```

이때, 동일한 입력 및 경우에 대하여 중복으로 세지 않도록 **정해진 규칙에 따라** 답을 구해야 한다. 예를 들어, **사전 순으로 "가장 먼저" 오는 답만을 세는 것**이다. 그러면 사전 순서에 의하여 중복된 경우를 하나로 합칠 수 있다.

```cpp
// 종만북 코드 6.5
int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
  // 아직 짝이 없는 학생들 중 번호가 가장 빠른 학생을 찾는다
  int firstFree = -1;

  for (int i = 0 ; i < n ; i++) {
    if (!taken[i]) { firstFree = i; break; }
  }

  // 기저 사례: 모든 학생들이 짝을 찾았을 경우, 한가지 방법이 나온 것이므로 종료
  if (firstFree == -1) return 1;
  int ret = 0;

  // ret의 값이 아래의 루프를 통하여 수정되지 않는다면,
  // 이는 해당 단계에서 더 이상 유효한 짝 배정이 이루어지지 못하였다는 의미이므로
  // 0을 그대로 반환하여 결과를 바꾸지 않는다

  // 현재 가장 번호가 빠른 학생(firstFree)을 매칭시킬 상대를 찾는다
  for (int pairWith = firstFree + 1 ; pairWith < n ; pairWith++) {
    if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
      // 서로 친구이며 해당 학생은 짝이 없으므로, 짝짓기
      taken[firstFree] = taken[pairWith] = true;
      // 새로운 짝을 추가시킨 상태에서 나머지 학생들을 짝지어준 결과를 받아오고, 이를 경우의 수에 추가한다
      ret = ret + countPairings(taken);
      // 방금 짝지어준 경우를 해제한다
      taken[firstFree] = taken[pairWith] = false;
    }
  }

  return ret;
}
```

## 2차원 상에서의 완전 탐색
2차원 지도 상에서 한 칸씩 돌아가며 정해진 규칙에 따른 답을 찾는 방식. 매 단계마다 정해진 규칙을 따르는지 검사하고, 인접한 칸에 대하여 재귀 호출을 수행한다.

> 삼성 기출 문제의 대부분의 완전 탐색은 이러한 유형의 변형이다

```cpp
// 종만북 코드 6.3
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

bool inRange(int, int);

bool hasWord(int y, int x, const string& word) {
  // 기저 사례1: 현재 위치가 유효 점위 안에 존재하는지 확인
  if (!inRange(y, x)) return false;
  // 기저 사례2: 찾고자 하는 단어의 철자가 현재 단계에서 맨앞에 존재하는지 확인
  if (board[y][x] != word[0]) return false;
  // 기저 사례: 찾고자 하는 단어를 모두 찾았는지 확인
  // 길이가 1이면, 직전 재귀 호출을 통하여 모든 철자를 확인하였다는 의미
  if (word.size() == 1) return true;

  for (int direction = 0 ; direction < 8 ; direction++) {
    int nextY = y + dy[direction], nextX = x + dx[direction];
    // 맨 앞 제외한 나머지 철자들에 대하여 재귀 호출
    if (hasWord(nextY, nextX, word.substr(1))) return true;
  }

  return false; // 맨 앞자리만 일치하고 나머지는 불일치
}
```

## 최적해 찾기
한번의 재귀 호출은 **해당 재귀 호출 단계를 기준으로 가장 최적의 답을 반환**한다는 것을 전제하며, 실제로 그러한 결과를 반환하도록 작성되어야 한다.

그래서 최적해는 `현재 단계에서 지금까지 얻은 값중 최적값 + 다음 단계에서 얻을 수 있는 값 중 최적값`이다.

```cpp
// 종만북 코드 6.7
int n;
double dist[MAX][MAX];

// path: 현재 단계 기준으로 지금까지 만든 경로의 배열
// visited: 각 도시를 기존 경로 상에서 방문하였는지 여부
// currnetLength: 현재 경로의 길이

// 현재 path 상에서 아직 방문하지 않은 도시들을 방문하는 데에 필요한 경로 길이 중 최소값 반환
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
  // 기저 사례: 모든 경로를 방문함 -> 처음 출발한 도시로의 경로 길이 반환
  if (path.size() == n) {
    return currentLength + dist[path.back()][0];
  }

  double ret = 987654321; // 매우 큰 값으로 초기화

  // 아직 방문하지 않은 모든 도시에 대하여 방문하고
  // 그 중에서 최소 길이인 것을 선택
  for (int next = 0 ; next < n ; next++) {
    if (visited[next]) continue;

    // 여기가 실행된다는 것은 해당 도시(next)를 방문하지 않았음을 의미;
    // 현재 단게에서는 해당 도시를 선택하여 방문해"본다"
    int here = path.back();
    path.push_back(next);
    visited[next] = true;

    double candidate = shortestPath(path, visited, currentLength + dist[here][next]);

    // 여기서는 next에서 시작하여 이어지는 경로 중 길이가 최소인 경로가 반드시 정해지며,
    // 이에 따라 path와 visited에도 최소 길이인 경로에 맞게 내부 값들이 수정되어있다
    ret = min(ret, candidate);
    visited[next] = false;
    path.pop_back();
  }
  return ret; // here에서 시작하는 경로 중 길이가 최소인 경로
}

```
