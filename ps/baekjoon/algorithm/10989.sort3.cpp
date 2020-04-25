// 입력이 매우 크다 (10000000)
// counting sort?
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cache[100001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, 0, sizeof(cache));

  int n, temp;
  cin >> n;
  for (int i = 0 ; i < n ; i++) {
    cin >> temp;
    cache[temp]++;
  }

  int index = 0;
  while (index <= 10000) {
    if (cache[index] > 0) {
      cout << index << "\n";
      cache[index]--;
    } else {
      index++;
    }
  }

  return 0;
}
