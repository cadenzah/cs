// 스택을 쓴다.

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int K, input;
  cin >> K;
  stack<int> list;

  for (int i = 0 ; i < K ; i++) {
    cin >> input;
    if (input == 0)
      list.pop();
    else
      list.push(input);
  }

  int answer = 0;
  while (!list.empty()) {
    answer += list.top();
    list.pop();
  }

  cout << answer;

  return 0;
}
