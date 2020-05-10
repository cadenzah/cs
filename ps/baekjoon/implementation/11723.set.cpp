// bitmask?
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false)  ;
  cin.tie(NULL);

  int set = 0, M, value;
  string input;
  cin >> M;

  for (int i = 0 ; i < M ; i++) {
    cin >> input;
    if (input == "add") {
      cin >> value;
      set |= (1 << (value - 1));
    } else if (input == "remove") {
      cin >> value;
      set &= ~(1 << (value - 1));
    } else if (input == "check") {
      cin >> value;
      if (set & (1 << (value - 1))) {
        cout << "1" << "\n";
      } else
        cout << "0" << "\n";
    } else if (input == "toggle") {
      cin >> value;
      set ^= (1 << (value - 1));
    } else if (input == "all") {
      memset(&set, 255, sizeof(set));
    } else if (input == "empty") {
      memset(&set, 0, sizeof(set));
    }
  }

  return 0;
}
