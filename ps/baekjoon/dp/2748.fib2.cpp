#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// vector<int> cache(91, -1);
long long int cache[91];

long long int fib(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  long long int& ret = cache[n];
  if (ret != -1) return ret;

  return ret = fib(n - 1) + fib(n - 2);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  memset(cache, -1, sizeof(cache));
  
  cout << fib(n);

}
