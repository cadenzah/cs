#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct comparor {
  bool operator () (const string& a, const string& b) {
    // 1. 길이가 짧은 순
    if (a.length() != b.length()) return a.length() < b.length();
    else return a < b;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<string> list(n);

  for (int i = 0 ; i < n ; i++) cin >> list[i];
  sort(list.begin(), list.end(), comparor());

  for (int i = 0 ; i < list.size() ; i++) {
    if (list[i] == list[i + 1]) continue;
    cout << list[i] << "\n";
  }

  return 0;
}
