#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define LL long long

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, B, C;
  LL int count = 0;
  cin >> N;
  vector<int> A(N);
  for (int i = 0 ; i < N ; i++)
    cin >> A[i];
  cin >> B >> C;

  for (int i = 0 ; i < N ; i++) {
    // 총감독관을 먼저 빼고,
    // 나머지에 대하여 부감독관으로 나눈 몫을 구하는데
    // 이때 나머지가 존재한다면 부감독관을 한명 더 쓴다
    int left = A[i];
    left -= B; count++;

    if (left <= 0)
      continue;

    if (left % C != 0)
      count = count + (left / C) + 1;
    else
      count = count + (left / C);
  }

  cout << count;

  return 0;
}
