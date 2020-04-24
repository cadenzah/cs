// 유클리드 호제법

#include <iostream>
#include <algorithm>
using namespace std;

int gcd_gen(int p, int q) {
  if (p < q) swap(p, q);
  if (q == 0) return p;
  return gcd_gen(q, p - q);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int p, q;
  cin >> p >> q;

  int gcd = gcd_gen(p, q);
  cout << gcd << "\n";

  long long int lcm = p / gcd * q;
  cout << lcm;

  return 0;
}
