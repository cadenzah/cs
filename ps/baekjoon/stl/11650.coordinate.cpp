#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// (x, y)
struct coordinate {
  int x;
  int y;
};

struct comparor {
  const bool operator() (const struct coordinate& a, const struct coordinate& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<struct coordinate> list(n);

  for (int i = 0 ; i < n ; i++) {
    cin >> list[i].x >> list[i].y;
  }
  sort(list.begin(), list.end(), comparor());

  for (int i = 0 ; i < n - 1 ; i++) {
    cout << list[i].x << " " << list[i].y << "\n";
  }
  cout << list[n - 1].x << " " << list[n - 1].y << "\n";

  return 0;
}
