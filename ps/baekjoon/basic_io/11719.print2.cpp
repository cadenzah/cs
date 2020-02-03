#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string input;

  while(getline(cin, input)) {
    cout << input << "\n";
  }

  return 0;
}
