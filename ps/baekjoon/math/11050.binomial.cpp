#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// nCk = n-1Ck + n-1Ck-1

int cache[11][11];

int binomial(int n, int k) {
  int& ret = cache[n][k];
  if (ret != -1) return ret;

  if (n == k || k == 0) return ret = 1;

  return ret = binomial(n - 1, k) + binomial(n - 1, k - 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, -1, sizeof(cache));

  int N, K;
  cin >> N >> K;

  cout << binomial(N, K);

  return 0;
}
