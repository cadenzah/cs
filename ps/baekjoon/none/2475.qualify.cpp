#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // 각 자리를 제곱한 수의 합을 10으로 나눈 나머지
  int temp, answer = 0;

  for (int i = 0 ; i < 5 ; i++) {
    cin >> temp;
    answer += temp * temp;
  }

  cout << answer % 10;

  return 0;
}
