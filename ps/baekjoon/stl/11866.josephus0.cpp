// list를 쓴다
// 맨 마지막에 다다르면, 맨 처음으로 되돌아간다
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

// 1. 삭제 위치를 찾는다
// 2. 해당 위치의 값을 벡터에 넣는다
// 3. 해당 위치의 값을 삭제한다

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  list<int> people;
  int N, K;
  cin >> N >> K;

  // N명 초기화
  for (int i = 0 ; i < N ; i++) people.push_back(i + 1);
  list<int>::iterator itr = people.begin();
  // 1명이 남을 때까지 반복
  cout << "<";
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < K - 1 ; j++) {
      // K번째 인물을 찾는다
      itr++;
      if (itr == people.end()) {
        // 끝에 다다랐다면, 맨 앞으로 간다
        itr = people.begin();
      }
    }
    // 해당 인물의 번호를 넣는다
    cout << *itr;
    if (i < N - 1) cout << ", ";
    // 해당 인물을 리스트에서 제거한다
    itr = people.erase(itr);
    if (itr == people.end()) itr = people.begin();
  }
  cout << ">";

  return 0;
}
