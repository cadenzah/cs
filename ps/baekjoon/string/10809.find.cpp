#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> list(26, -1);
  string input;
  cin >> input;

  for (int j = 97 ; j < 123 ; j++) {
    char letter = (char)j;
    for (int i = 0 ; i < input.length() ; i++) {
      if (input[i] == letter) {
        list[j - 97] = i;
        break;
      }
    }
  }

  for (int i = 0 ; i < 25 ; i++) {
    cout << list[i] << " ";
  }
  cout << list[25];

  return 0;
}
