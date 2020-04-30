// 에라스토테네스의 체
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;

  for (int div = 3 ; div <= int(sqrt(n)) ; div++)
    if (n % div == 0) return false;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int input, count = 0;
  for (int i = 0 ; i < N ; i++) {
    cin >> input;
    if (isPrime(input)) count++;
  }

  cout << count;

  return 0;
}
