// vector로 쭉 받아오기
// upper_bound, lower_bound로 개수 찾기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, temp;
  cin >> N;
  vector<int> cards(N);

  // 카드 목록 초기화
  for (int i = 0 ; i < N ; i++) cin >> cards[i];
  sort(cards.begin(), cards.end());
  
  cin >> N;
  for (int i = 0 ; i < N ; i++) {
    cin >> temp;

    // 이진 탐색으로 처음과 끝 위치 찾는다
    temp = upper_bound(cards.begin(), cards.end(), temp) - lower_bound(cards.begin(), cards.end(), temp);
    cout << temp;
    if (i < N - 1) cout << " ";
  }

  return 0;
}
