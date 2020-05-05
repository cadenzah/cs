// 높이 H
// 결과값: 높이 H의 최대값 <- 이게 대상

// 입력:
  // M: 필요한 나무 길이

// 최소: 0 **(모두 다 가져간다)**
// 최대: 가장 높은 나무의 높이

// 어떤 높이를 정했을 때, 이 높이가 적절한지 어떻게 판단하지?
  // tree[i] - mid 를 싹다 더한 값 sum과 M을 비교한다
  // mid >= tree[i] 이면, 0을 더한다 (잘리지 않음)
  // 높이(mid)가 커지면, sum이 감소한다.
  // sum <= M : 높이가 더 낮아야 한다. high = mid - 1;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  LL int N, M;
  cin >> N >> M;
  vector<LL int> tree(N);
  for (int i = 0 ; i < N ; i++)
    cin >> tree[i];
  sort(tree.begin(), tree.end());
  
  LL int low = 0, high = tree[N - 1];
  LL int answer;
  while (low <= high) {
    LL int mid = (low + high) / 2;
    LL int sum = 0;
    for (int i = 0 ; i < N ; i++) {
      LL int part = tree[i] - mid;
      if (part < 0)
        part = 0;
      sum += part;
      if (sum >= M)
        break;
    }

    if (sum >= M) {
      answer = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  
  cout << answer;
  return 0;
}
