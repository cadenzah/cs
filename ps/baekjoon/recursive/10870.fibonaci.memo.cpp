#include <iostream>
#include <vector>
using namespace std;

int cache[20] = { 0 };

int fib(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  int& n_2 = cache[n - 2], n_1 = cache[n - 1];
  if (n_2 == 0) n_2 = fib(n - 2);
  if (n_1 == 0) n_1 = fib(n - 1);
  return n_2 + n_1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  cout << fib(n);
}
