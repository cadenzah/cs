// 길이가 제각각인 K개의 선.
// 이를 잘라서 N개로 만든다고 할 때, 랜선의 최대 길이는?
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define LL long long

// 사용할 랜선: 1 <= K <= 10000
// 필요 개수:   1 <= N <= 1000000
// K[i] 는 2^31 - 1 이하 자연수
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int K, N;
  cin >> K >> N;
  vector<LL int> cables(K);
  LL int left = 1, right = 0;

  for (int i = 0 ; i < K ; i++) {
    cin >> cables[i];
    if (cables[i] > right)
      right = cables[i];
  }
    
  // 1과 <K개 랜선 중 가장 긴 길이> 사이에서 이분 탐색하며
  // N개 이상의 랜선을 만들어낼 수 있는 최대 길이를 찾는다
  LL int length;
  while (left <= right) {
    LL int mid = (left + right) / 2;
    int count = 0;
    for (int i = 0 ; i < K ; i++) {
      count += cables[i] / mid;
      if (count >= N) {
        left = mid + 1;
        length = mid;
        break;
      }
    }
    if (count < N)
      right = mid - 1;
  }
  
  // 랜선 길이가 증가함에 따라 랜선 개수의 총합은 자연스럽게 감소한다 

  cout << length;

  return 0;
}
