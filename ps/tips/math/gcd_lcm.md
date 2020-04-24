# 최대공약수와 최소공배수
## 유클리드 호제법

두 수 P, Q가 있을 때, P와 Q의 최대공약수는 P-Q의 Q의 최대공약수와 같다는 성질을 이용한다.

> - P = a * b
> - Q = a * c
> - P - Q = a * (b - c)
> - GCD = a

```cpp
#include <algorithm>
int gcd(int p, int q) {
  if (p < q) swap(p, q);
  if (q == 0) return p;
  return gcd(p, p - q);
}
```

## 최대공배수
주어진 입력의 범위를 잘 보고, `int`보다 커질 듯 하다면 적절하게 `long long int`를 사용해주자. 이때, 오버플로우가 발생하지 않도록 연산 순서에 유의하자.
