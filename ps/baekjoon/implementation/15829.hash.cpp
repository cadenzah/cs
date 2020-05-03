// 50점

#include <iostream>
#include <vector>
using namespace std;

#define LL long long

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int L, M = 1234567891;
  int answer = 0;
  LL int r = 1;
  string _input;
  cin >> L;
  cin >> _input;

  for (int i = 0 ; i < L ; i++) {
    int a = _input[i] - 96;
    answer += a * r % M;
    r *= 31;
  }
  
  cout << answer;

  return 0;
}
