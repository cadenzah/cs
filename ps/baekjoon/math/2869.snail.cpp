// (V - A) 이상의 높이까지 올라가는 데에 (A - B)로 얼마나 (얼마나 걸리는가?
// (V - A) / (A - B) + 1

// 단, 이 때 (V - A) / (A - B)의 나머지가 있으면, 하루 더 올라갈 수 있다
// 4 1 11
#include <iostream>
#include <cmath>
using namespace std;

#define LL long long

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  LL int A, B, V;
  cin >> A >> B >> V;
  int a = (V - A) % (A - B);
  if (a != 0)
    a = (V - A) / (A - B) + 1;
  else
    a = (V - A) / (A - B);
  
  cout << a + 1;
  
  return 0;
}
