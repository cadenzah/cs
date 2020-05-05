#include <iostream>
#include <cstring>
using namespace std;

int cache[15][15];

// k층 n호에 사는 사람들 수
int countPeople(int k, int n) {
  // base case
  if (k == 0) return n;

  int& ret = cache[k][n];
  if (ret != -1) return ret;

  int answer = 0;
  for (int i = 1 ; i <= n ; i++)
    answer += countPeople(k - 1, i);

  return ret = answer;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, -1, sizeof(cache));

  int T;
  cin >> T;

  for (int i = 0 ; i < T ; i++) {
    int k, n;
    cin >> k >> n;
    cout << countPeople(k, n) << "\n";
  }

  return 0;
}
 