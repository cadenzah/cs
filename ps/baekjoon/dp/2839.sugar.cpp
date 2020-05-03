// 냅색
// 현재 남은 킬로그램, 현재 봉지 개수
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cache[5001];

// leftKilo만큼 남았을 때, 
// 이 남은 설탕을 담는 데에 필요한 봉지 수의 최소값
int delivery(int leftKilo) {
  // leftKilo < 0 이면, 정확하게 못 담았으므로 땡
  if (leftKilo < 0) return 987654321;
  if (leftKilo == 0) return 0;

  int& ret = cache[leftKilo];
  if (ret != -1) return ret;

  return ret = min(delivery(leftKilo - 3) + 1, delivery(leftKilo - 5) + 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, -1, sizeof(cache));
  int N;
  cin >> N;
  
  int answer = delivery(N);
  if (answer >= 987654321)
    answer = -1;
  cout << answer;
  
  return 0;
}
