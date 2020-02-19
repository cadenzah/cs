# 동적 계획법

## Index
- 전제 조건
- 메모이제이션 활용 원칙

## 전제 조건

- 부분 문제들이 순수 함수이어야 함. 즉, 동일 입력 → 동일 출력임을 보장해야 함.

## 메모이제이션 활용 원칙

1. 기저 사례를 코드 상에서 가장 먼저 확인
  - 입력값의 유효성 확인, 가장 마지막 부분 문제인지 등
2. `cache` 배열의 값이 저장되었는지 여부를 배열 상에 표기
  - 예를 들어, 모든 출력값이 양수임이 보장된다면, 아직 계산되지 않은 값을 표기시 `-1`로 표기
  - 아니면, 실제 각각의 메모이제이션 값을 저장
3. 매 부분 문제에서의 답을 가리킬 때 참조형으로 표현. 그러면 오타 방지에 유용
    ```cpp
    int cache[2500][2500];
    ...
    int& ret = cache[a][b];
    ```