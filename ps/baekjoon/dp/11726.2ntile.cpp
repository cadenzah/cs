#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cache[1001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(&cache, 0, sizeof(cache));
  int n;
  cin >> n;

  // S(n) = S(n - 1) + S(N - 2);
  cache[1] = 1;
  cache[2] = 2;
  for (int i = 3 ; i <= n ; i++) {
    cache[i] = (cache[i - 1] + cache[i - 2]) % 10007;
  }

  cout << cache[n];

  return 0;
}
