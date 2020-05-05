#include <iostream>
#include <vector>
using namespace std;

#define LL long long

// 이분 탐색
// low = 예산 요청들 중 최소값
// high = 예산 요청들 중 최대값
  // 1. 상한액 >= 예산요청 : 예산요청을 더한다
  // 2. 상한액 < 예산요청 : 상한액을 더한다
  // 이렇게 해서 다 더한 값 <= 총 예산 일 때까지 이분탐색

// 1 <= N <= 100000
// N <= M <= 10 0000 0000
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M; // 지방의 수, 총 예산
  int low = 0, high = -1, answer;
  cin >> N;
  vector<int> budgets(N);
  for (int i = 0 ; i < N ; i++) {
    cin >> budgets[i];
    if (budgets[i] > high)
      high = budgets[i]; // 최대 예산 요청값을 구한다
  }

  cin >> M;

  // 이분탐색
  while (low <= high) {
    int mid = (low + high) / 2;
    int sum = 0;
    for (int i = 0 ; i < N ; i++) {
      if (mid >= budgets[i])
        sum += budgets[i];
      else
        sum += mid;
      
      if (sum > M)
        break;
    }
    if (sum > M)
      high = mid - 1;
    else {
      answer = mid;
      low = mid + 1;
    }
  }
  
  cout << answer;

  return 0;
}
