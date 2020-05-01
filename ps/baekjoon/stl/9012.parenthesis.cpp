// 문자열 끝까지 돌면서 스택에 각 (를 넣는다
// 스택이 비어있지 않을 때 )를 만나면, (를 하나 pop한다
// 스택이 비었을 때 )를 만나면, 이는 오류이다.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  string input;
  cin >> t;

  for (int zz = 0 ; zz < t ; zz++) {
    cin >> input;
    bool isValid = true;
    stack<char> counter;
    for (int i = 0 ; i < input.length() ; i++) {
      // (를 만나면 넣는다
      if (input[i] == '(')
        counter.push('(');
      else {
      // )를 만나면:
      // 스택이 비었을 때: 오류 - break한다
      // 스택에 뭔가 있을 때: )를 제거한다
        if (counter.empty()) {
          isValid = false;
          break;
        }
        else
          counter.pop();
      }
    }
    if (counter.empty() && isValid)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }

  return 0;
}
