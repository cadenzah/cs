#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string input;
  int lines, last_line;

  cin >> input;
  lines = input.length() / 10 + 1; // 총 몇줄
  last_line = input.length() % 10; // 마지막줄 단어 개수

  for (int i = 0 ; i < lines - 1 ; i++) {
    for (int j = 0 ; j < 10 ; j++) {
      cout << input[i * 10 + j];
    }
    cout << "\n";
  }
  for (int j = 0 ; j < last_line ; j++) {
    cout << input[(lines - 1) * 10 + j];
  }
}
