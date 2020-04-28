#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

// 그냥 완전탐색...
// 입력을 보고 시간복잡도를 구해보고서, 괜찮다 싶으면 그냥 완전탐색 돌리자.
// 안 되는 걸 붙들고 있지 말자. 접근이 틀렸을 수도 있다.

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int answer = 0, N, M;

  cin >> N >> M;
  vector<int> cards(N);
  // 카드 더미 초기화
  for (int i = 0 ; i < N ; i++) cin >> cards[i];

  for (int i = 0 ; i < N ; i++) {
    for (int j = i + 1 ; j < N ; j++) {
      for (int k = j + 1 ; k < N ; k++) {
        int cand = cards[i] + cards[j] + cards[k];
        if (cand <= M && answer < cand) answer = cand;
      }
    }
  }

  cout << answer;

  return 0;
}

// N장의 카드, 그 중에 3장을 골라서 합 <= M 이어야 한다
// 3 <= N <= 100 / 10 <= M <= 300000
