#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
int minimumPath(int y, int x):
  (y,x)에서 시작하여, 아래 또는 오른쪽 한칸씩 진행할 때, 경로합의 최소값

:= cost[y][x] + min(minimumPath(y + 1, x) + cost[y + 1][x], minimumPath(y + 1, x + 1) + cost[y + 1][x + 1])
*/

int cache[501][501];
int cost [501][501];

int minimumPath(int y, int x) {
  // base case: 삼각형 내부가 아니면 성립 불가능
  if (y < x || y > 500) return 0;
  
  int& ret = cache[y][x];
  if (ret != -1) return ret;

  return ret = cost[y][x] + max(minimumPath(y + 1, x), minimumPath(y + 1, x + 1));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, -1, sizeof(cache));

  int n;
  cin >> n;

  // 삼각형 초기화
  for (int i = 1 ; i <= n ; i++) {
    for (int j = 1 ; j <= i ; j++) {
      cin >> cost[i][j];
    }
  }

  cout << minimumPath(1, 1);
  return 0;
}
