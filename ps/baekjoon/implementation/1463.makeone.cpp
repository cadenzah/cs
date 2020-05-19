// 완전탐색
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 987654321;

void solve(int value, int count) {
  // base: 현재 answer보다 크면 스톱
  if (count >= answer)
    return;

  // base: value == 1 이면,
  // answer와 비교하여 더 작은 값으로 대체
  if (value == 1) {
    answer = min(answer, count);
    return;
  }

  // 1. 3으로 나누어 떨러진다
  if (value % 3 == 0)
    solve(value / 3, count + 1);
  // 2. 2로 나누어 떨어진다
  if (value % 2 == 0)
    solve(value / 2, count + 1);
  
  // 마지막으로,
  // 3. 1을 빼본다 (가장 나중에 시도)
  solve(value - 1, count + 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int input;
  cin >> input;

  solve(input, 0);

  cout << answer;

  return 0;
}
