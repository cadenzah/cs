#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, temp;
  cin >> n;
  vector<int> list(n);
  
  // A 완성
  for (int i = 0 ; i < n ; i++) cin >> list[i];
  sort(list.begin(), list.end());

  cin >> n;
  for (int i = 0 ; i < n ; i++) {
    cin >> temp;
    if (binary_search(list.begin(), list.end(), temp)) cout << 1;
    else cout << 0;
    
    if (i != n - 1) cout << "\n";
  }

  return 0;
}
