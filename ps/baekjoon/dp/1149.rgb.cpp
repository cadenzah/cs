// Top-down으로 해결한 전형적인 예시
// - 최종 점화식을 구할 때에, n번째 항이 여러개가 존재하며 그 중에서 최소값을 고르는 대목에 유의한다 (`main` 함수 내부)
// - n번째 값을 구하기 위하여 n-1번째 재귀호출과 n번째 해답을 더하는 대목에 유의

// 전체 길이
// int calc(int n): n개 집을 칠할 때, 색칠 비용의 최소값

// int calc(int length, int color): length개 집을 칠할 때, 맨 뒤의 색깔이 color일 때의 총 비용; 최소
// min(calc(length - 1, nextColor1), calc(length - 1, nextColor2)) + cost[length][color];
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[1001][3];
int cost[1001][3];

int calc(int length, int color) {
  // base case
  if (length == 0) return 0;

  int nextColor1 = (color + 1) % 3;
  int nextColor2 = (color + 2) % 3;

  int& ret = cache[length][color];
  if (ret != -1) return ret;

  return ret = min(calc(length - 1, nextColor1), calc(length - 1, nextColor2)) + cost[length][color];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, -1, sizeof(cache));

  int n;
  cin >> n; 

  // 색칠 비용 초기화
  for (int i = 1 ; i <= n ; i++) {
    int r, g, b;
    cin >> r >> g >> b;
    cost[i][0] = r; cost[i][1] = g; cost[i][2] = b;
  }

  int answer = min(calc(n, 0), calc(n, 1));
  answer = min(calc(n, 2), answer);
  cout << answer;

  return 0;
}
