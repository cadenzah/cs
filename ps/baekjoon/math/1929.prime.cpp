// 1은 소수도 합성수도 아니다
// 2부터 쭉 돌아가면서, 소수인 값들의 배수를 제거해나간다
  // 합성수임이 판별된 값을 만나면, 무시
  // sqrt(n)까지만 순회해봐도 된다. 어떤 k가 합성수라면, 한 수는 sqrt(k)보다 작거나 같고, 또 한 수는 sqrt(k)보다 크거나 같으므로, sqrt(k) 이전의 소인수를 사용하여 순회했을 때 반대편의 값이 식별되어 판별이 이루어질 것.
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> genPrimes(int end) {
  vector<int> primes(end + 1);
  primes[1] = -1;

  for (int i = 2 ; i <= int(sqrt(end)) ; i++) {
    if (primes[i] == -1)
      continue;
    else {
      for (int j = i * i ; j <= end ; j += i) {
        primes[j] = -1;
      }
    }
  }

  return primes;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;

  vector<int> primes = genPrimes(b);

  for (int i = a ; i <= b ; i++) {
    if (primes[i] != -1) {
      cout << i << "\n";
    }
  }
  
  return 0;
}
