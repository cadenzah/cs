// getline을 사용하여 문자열을 받아온다
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string input;
  while (getline(cin, input)) {
    bool isValid = true;
    stack<char> counter;
    if (input.length() == 1 && input[0] == '.')
      break;
    
    for (int i = 0 ; i < input.length() ; i++) {
      // ( 또는 [ 이면 -> 그냥 넣는다
      if (input[i] == '(' || input[i] == '[')
        counter.push(input[i]);
      // ) 또는 ] 이면
      if (input[i] == ')' || input[i] == ']') {
        if (counter.empty()) {
          // 그 직전에 빈 스택이면 땡
          isValid = false;
          break;
        } else {
          if ((input[i] == ')' && counter.top() == '(')
          || (input[i] == ']' && counter.top() == '['))
            counter.pop();
          else {
            // 바로 직전 스택 요소가 대응하는 괄호가 아니면 땡
            isValid = false;
            break;
          }
        }
      }
    }

    if (counter.empty() && isValid)
      cout << "yes" << "\n";
    else
      cout << "no" << "\n";
  }
}
