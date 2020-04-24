#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> list(n);
  for (int i = 0 ; i < n ; i++) cin >> list[i];

  sort(list.begin(), list.end());

  for (int i = 0 ; i < n - 1 ; i++) cout << list[i] << "\n";
  cout << list[n - 1];

  return 0;
}
