// 문제에서 말하는 풀이 방식에 낚이면 안 된다........

// M명의 사람들, N개의 입국심사관들
// 각 입국심사관들은 저마다 심사 시간이 다르다 (Tk)

// 출력: 총 소요 시간 최소화

// 구할 대상: 총 소요 시간
// 최소값: 1
// 최대값: 최대 심사시간 * (총 인원수 / 심사관수 + 1)

// 이분 탐색 후: 
  // 해당 시간 내에 심사를 마칠 수 있어야 한다

// 심사가 가능한가?
  // 각 심사관이 mid 시간동안 심사 가능한 인원:
  // mid / time[i]
  // (기다려야 하는 시간 + 심사시간)이 가장 짧은 곳을 찾아 가야 한다
  // 다 더한 값 >= M 이면
    // answer = mid;
    // high = mid - 1;
  // 다 더한 값 < M 이면
    // 시간이 더 필요
    // low = mid + 1;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  LL int N, M; // N명의 입국심사관들, M명의 입국자들
  cin >> N >> M;
  vector<int> time(N);
  for (int i = 0 ; i < N ; i++)
    cin >> time[i];
  sort(time.begin(), time.end());

  LL int low = 1, high = time[N - 1] * M;

  LL int answer;
  while (low <= high) {
    LL int mid = (high + low) / 2;
    LL int sum = 0; // 입국심사 가능한 인원 수
    for (int i = 0 ; i < N ; i++) {
      sum += mid / time[i];
      if (sum >= M)
        break;
    }

    if (sum >= M) {
      answer = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << answer;
  return 0;
}
