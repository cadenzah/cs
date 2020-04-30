#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int square(int n) {
  return n * n;
}

// 출력시 줄바꿈 크게 신경쓰지 말자.

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> list(3);
  string answer = "";
  
  while (1) {
    cin >> list[0] >> list[1] >> list[2];
    if (list[0] == 0) {
      break;
    } else {
      sort(list.begin(), list.end());
      if (square(list[0]) + square(list[1]) == square(list[2])) 
        answer = "right";
      else
        answer = "wrong";
      cout << answer << "\n";
    }
  }
}
