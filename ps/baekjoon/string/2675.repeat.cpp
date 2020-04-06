#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int cnt;
  cin >> cnt;

  for (int _i = 0 ; _i < cnt ; _i++) {
    int times;
    string input, answer = "";
    cin >> times >> input;

    for (int i = 0 ; i < input.length() ; i++) {
      for (int j = 0 ; j < times ; j++) {
        answer += string(1, input[i]);
      }
    }
    cout << answer;
    if (_i < cnt - 1) cout << "\n";
  }

  return 0;
}
