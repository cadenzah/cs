#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
  while(1) {
    string input;
    cin >> input;
    if (input == "0") break;

    int length = input.length() / 2;
    bool isPal = true;
    for (int i = 0 ; i < length ; i++) {

      if (input[i] != input[input.length() - 1 - i]) {
        isPal = false;
        cout << "no" << "\n";
        break;
      }
    }
    if (isPal == true) cout << "yes" << "\n";
  }

  return 0;
}
