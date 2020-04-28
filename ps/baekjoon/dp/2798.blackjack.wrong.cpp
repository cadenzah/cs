#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 복잡하게 생각할 필요가 없는 것은 복잡하게 생각하지 말자

int cache[100][3];
int value[100];
int N, M;
// 현재 index번째 카드를 다루고 있고, 현재 cards개의 카드를 선택했을 때,
// 해당 카드의 조합으로 만들 수 있는 M에 가장 가까운 최대합
int maximumSum(int index, int cards) {
  // base case
  // 모든 카드를 다 봤거나, 카드를 3개 모두 얻었을 때
  if (index == N || cards == 3) return 0;

  int& ret = cache[index][cards];
  if (ret != -1) return ret;

  // M을 초과하면, 무효로 0을 반환
  // i번째 카드를 고르느냐
  int candidate1 = maximumSum(index + 1, cards + 1) + value[index];
  if (candidate1 > M) candidate1 = 0;
  // i+1번째 카드를 고르지 않느냐
  int candidate2 = maximumSum(index + 1, cards);
  if (candidate2 > M) candidate2 = 0;

  // 둘 중에 더 큰 값
  return ret = max(candidate1, candidate2);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, -1, sizeof(cache));

  cin >> N >> M;
  for (int i = 0 ; i < N ; i++) {
    cin >> value[i];
  }

  int answer = maximumSum(0, 0);
  cout << answer;

  return 0;
}
