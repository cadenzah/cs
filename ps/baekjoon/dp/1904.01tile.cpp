#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Bottom-up의 전형적이 예시
// 초반에, 점화식 규칙이 적용되지 않는 값들이 몇몇 존재하며 (1, 2)
// 이후 for문으로 빠르게 n번째 항들을 계산하는 부분에 유의

/*
1을 쓰거나, 00을 쓰거나, 길이가 n 이하일 떄까지

길이가 k인 새로운 문자열 = 
길이가 k - 1인 직전까지의 것에 1
길이가 k - 2인 직전까지의 것에 00

길이 1 := 1
길이 2 := 11 00

1 11
1 00
00 1

*/


int cache[1000001];

void countTiles(int n) {
  cache[1] = 1;
  cache[2] = 2;
  for (int i = 3 ; i <= n ; i++) {
    cache[i] = (cache[i - 1] + cache[i - 2]) % 15746;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, -1, sizeof(cache));

  int n;
  cin >> n;

  countTiles(n);
  cout << cache[n];

  return 0;
}
