// 첫번째줄의 경우
// cards[2000001]으로 선언한 것을 찾는다
// 입력에 대하여 10000001을 더한 값에 대하여 ++ 한다

// 두번째줄의 경우
// 들어온 순으로 벡터(target)에 넣고
// 각 벡터를 돌면서 target[i] + 10000001 를 인덱스로 하여 조사
// 

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int cards[20000001];

int convert(int input) {
  return input + 10000001;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cards, 0, sizeof(cards));

  int M, temp;
  cin >> M;
  for (int i = 0 ; i < M ; i++) {
    cin >> temp;
    cards[convert(temp)]++;
  }

  cin >> M;
  for (int i = 0 ; i < M ; i++) {
    cin >> temp;
    cout << cards[convert(temp)];
    if (i < M - 1) cout << " ";
  }
  
  return 0;
}
