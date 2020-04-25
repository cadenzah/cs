// list를 사용하자
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  list<int> cards;
  int n;
  cin >> n;
  for (int i = 1 ; i <= n ; i++) cards.push_back(i);

  // 1. 맨 앞의 것을 버리고,
  // 2. 새로운 맨 앞의 것을 맨 뒤로 보낸다
  // 이것을 1장 남을 때까지 (길이가 1일 때까지 반복한다)
  while(cards.size() > 1) {
    cards.pop_front();
    int top = cards.front();
    cards.pop_front();
    cards.push_back(top);
  }

  cout << cards.front();

  return 0;
}
