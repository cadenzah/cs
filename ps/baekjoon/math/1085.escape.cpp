// 4방향으로의 거리 모두 얻어서 최소값 반환
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y, w, h;
  cin >> x >> y >> w >> h;

  int left = x;
  int right = w - x;
  int up = h - y;
  int down = y;

  int answer = min(min(min(left, right), up), down);

  cout << answer;

  return 0;
}
