#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cache0[41]; // i번째 피보나치 수를 만드는 데에 호출된 fib(0)의 횟수
int cache1[41]; // i번째 피보나치 수를 만드는 데에 호출된 fib(1)의 횟수
/*
i   0   1
----------
0   1   0
1   0   1
2   1   1
3   cache0[2]+cache0[1] cache1[2]+cache1[1]
*/

void generateCntFib(int n) {
  cache0[0] = 1; cache0[1] = 0;
  cache1[0] = 0; cache1[1] = 1;
  for (int i = 2 ; i <= n ; i++) {
    cache1[i] = cache1[i - 1] + cache1[i - 2];
    cache0[i] = cache0[i - 1] + cache0[i - 2];
  }
}

void printCntFib(int n) {
  cout << cache0[n] << " " << cache1[n] << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache0, -1, sizeof(cache0));
  memset(cache1, -1, sizeof(cache1));

  generateCntFib(40);

  int cnt;

  cin >> cnt;

  for (int i = 0 ; i < cnt ; i++) {
    int n = 0;
    cin >> n;
    printCntFib(n);
  }

  return 0;
}
