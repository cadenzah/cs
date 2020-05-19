#include <iostream>
using namespace std;

int answer = 0;
int N;

// 모든 방법을 구해본다
// 순열
void solve(int sum) {

  // base case: 초과할 때: 답이 아니다
  if (sum > N)
    return;

  // base case: 답일 떄
  if (sum == N) {
    answer++;
    return;
  }

  // 직전의 수열에 1을 더한다
  solve(sum + 1);
  // 직전의 수열에 2를 더한다
  solve(sum + 2);
  // 직전의 수열에 3을 더한다
  solve(sum + 3);
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  for (int ii = 0 ; ii < T ; ii++) {
    cin >> N;
    solve(0);
    cout << answer << "\n";
    answer = 0;
  }

  return 0;
}
