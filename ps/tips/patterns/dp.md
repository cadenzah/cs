# 동적 계획법

## Index
- 주의 사항
  - 굳이 복잡하게 생각할 필요 있을까? (완전 탐색으로 풀린다면, 그렇게 하라)
  - 답을 구하지 못한 부분 문제가 없어야 한다
  - DP와 완전 탐색의 혼합 유형
- 전제 조건
- 메모이제이션 코드 작성 팁
- 부분 문제 설계 팁
- TL;DR; 전형적인 유형

## 주의 사항

### 굳이 복잡하게 생각할 필요 있을까? (완전 탐색으로 풀린다면, 그렇게 하라)
완전 탐색과 마찬가지로 DP는 재귀적인 구조로 모든 경우를 고려하는 방법이다. 하지만, DP는 기존에 계산한 것을 메모이제이션 하는 것이 핵심 해법이다. **메모이제이션을 적용할 효율적이면서 적절한 방법**이 도출되지 않는다면, 또는 구현이 까다롭거나 바로 생각나지 않는다면, DP로 접근하는 것은 시간 낭비이다.

단순하게 접근해서 풀리는 문제이고, 이로 인한 시간 또는 메모리 초과가 발생하지 않는다면, 좋은 해법이다. 시간 복잡도가 높더라도 입력이 크지 않아 완전 탐색으로 풀이가 가능한 유형이라면, 굳이 DP를 사용할 이유가 없다. 3중 이상 for문은 나쁜게 아니다...

### 답을 구하지 못한 부분 문제가 없어야 한다
DP Cache에 초기값(`-1` 등)이 들어있는 채로 종료된다면, 해당 부분 문제의 답(최적해)를 구하지 않은 경우이다. 이러면 비록 로직이 옳더라도 답을 구하지 못하는 반례가 발생할 수 있으므로, 예외 처리를 하거나, 모든 부분 문제를 풀게끔 코드를 적절히 수정해야 한다.

```cpp
// BOJ 14501 - 퇴사
for (int i = startdate ; i <= N ; i++) {
  int nextdate = i + T[startdate];
  if (nextdate - 1 > N) {
    if (ret == -1)  // 처음으로 방문했는데, 부분 문제를 더 이상 계산할 수 없다면 0으로 직접 값을 대입
      ret = 0;
    break;          // 바깥은 for문으로 감싸져 있음
  }

  ret = max(ret, P[startdate] + calc(nextdate, T, P));
}
```

위 문제에서는 `nextdate`를 기준으로 세부 부분 문제(`calc()`의 재귀 호출)를 더 풀고, 이를 종합하여 최종적인 부분 문제(`ret`가 가리키는 메모이제이션 값)를 계산해낸다. 이때 `nextdate`가 주어진 조건에 부합하지 않는 경우, 해당 `nextdate` 이후로는 세부 문제를 만들지 않는다.

그런데 만약 세부 부분 문제를 하나도 만들지 못하는 상황이라면, 즉 `ret`의 값이 한번도 변경되지 않고 루프를 탈출해버리는 상황이라면 해당 세부 문제는 초기값(i.e. `-1`)인 상태로 머무르게 된다. 따라서 세부 문제를 계산할 수 없는 경우, 문제에서 정의된 최소값 등을 해당 세부 문제의 값으로 설정한다(이 문제의 경우 0이다).

### DP와 완전 탐색의 혼합 유형
문제에 따라 부분 문제 계산을 시작할 때 단 하나의 진입점만 필요할 수도 있고, 모든 경우에 대하여 시작해야 할 수도 있다. 문제를 잘 해석하여 `main` 내에서 적절하게 루프를 돌려 주자.

```cpp
// BOJ 14501 - 퇴사
int answer = -1;
for (int i = 1 ; i <= N ; i++) // 시작 날짜(i)를 모두 다르게 하여 최적해를 구한다
  answer = max(answer, calc(i, T, P));
```

이는 부분 문제의 설계에 따라 코드 구현이 달라진다. 위 코드의 경우,

> `int calc(int startdate, vector<int>& T, vector<int>& P)`
>
> `startdate`부터 마지막날(N)까지 상담했을 때 얻을 수 있는 최대 상담금액

로 부분 문제를 설계하였다. 따라서 모든 경우의 `startdate`에 대하여 값을 구해보고 그 중 최적해를 찾는 것이 필요하다.

## 전제 조건

- 부분 문제들이 순수 함수이어야 함. 즉, 동일 입력 → 동일 출력임을 보장해야 함.

## 메모이제이션 코드 작성 팁

1. 기저 사례를 코드 상에서 가장 먼저 확인
  - 입력값의 유효성 확인, 가장 마지막 부분 문제인지 등
2. `cache` 배열의 값이 저장되었는지 여부를 배열 상에 표기
  - 예를 들어, 모든 출력값이 양수임이 보장된다면, 아직 계산되지 않은 값을 표기시 `-1`로 표기
  - 아니면, 실제 각각의 메모이제이션 값을 저장
3. 매 부분 문제에서의 답을 가리킬 때 참조형으로 표현. 그러면 오타 방지에 유용

```cpp
// 두루 사용 가능한 템플릿
#include <cstring>
int cache[N + 1]; // 문제의 성격에 따라, 입력을 활용하기 좋은 형태로 배열 크기를 선언 (i.e. index가 1부터 시작)

int calc(int index) {
  // index번째 부분 문제를 계산한다
  int& ret = cache[index];
  if (ret != -1) // 이미 답을 계산했다면, 다시 계산하지 않고 그대로 활용
    return ret;

  // 답 구하기
  ret = max(...);
  return ret;
}

int main(void) {
  // 풀리지 않은 문제에 대하여 -1로 표시
  memset(&cache, -1, sizeof(cache));
}
```

## 부분 문제 설계 팁
### 최적 부분 구조인가?

### 기저 사례(base case)를 꼼꼼하게 설계하자.

### 인자로 들어온 값을 기준으로 그 다음 부분 문제의 입력을 구성하자
부분 문제의 답은 다음과 같이 구성한다.

```
ret = <현재 부분 문제의 답> + <다음 부분 문제의 답을 구하기 위한 재귀 호출>
```

이때 **<현재 부분 문제의 답>**는 현재 함수 호출 인자를 그대로 활용하여 구하고, **<다음 부분 문제의 답을 구하기 위한 재귀 호출>**에는 현재 함수 호출 인자를 적절하게 조정하여 대입한다.

```cpp
// `startdate`부터 마지막날(N)까지 상담했을 때 얻을 수 있는 최대 상담금액
int calc(int startdate, vector<int>& T, vector<int>& P) {
  ...
  // 현재(`startdate`일)의 값 + 다음(`startdate + 1`일)에 대한 계산 결과
  ret = max(ret, P[startdate] + calc(startdate + 1, T, P));
  return ret;
}
```

### 최대한 메모이제이션에 사용되는 값을 줄이자

> 재귀 함수에 사용되는 인자의 개수와는 별개이다. DP 배열의 차원 개수와 연관이 있다.

최대한 단순화할수록, 부분 문제의 계산수가 줄어들고 로직도 간단해진다.

## TL;DR; 전형적인 유형
- Top-down
  - 1149.rgp
  - 맨 끝에서부터 차례대로 문제를 분해해나가는 예시
- Bottom-up
  - 1902.01tile
  - 맨 처음부터 차례대로 계산해나가며 최종적인 답을 구하는 예시
  - 반복적 동적 계획법
- Napsack (배낭 문제)
  - 2839.suger
