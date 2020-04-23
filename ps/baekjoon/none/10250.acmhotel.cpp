#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int _i = 0 ; _i < t ; _i++) {
    int h, w, n;
    cin >> h >> w >> n;

    int room = (n % h == 0) ? n / h : n / h + 1;
    int floor = (n % h == 0) ? h : n % h;
    cout << floor * 100 + room << "\n";
  }

  return 0;
}
