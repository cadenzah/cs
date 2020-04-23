/*
0 1 2 3 4 5 6 7 8 9 10 11 12
1 1 1 2 2 3 4 5 7 9 12 16 21
 0 0 1 0 1 1 1 2 2 3  4  5

0번째(1) = 1
1번째(1) = 0번째
2번째(1) = 1번째
3번째(2) = 2번째 + 0번째
4번째(2) = 3번째

5번째(3) = 4번째 + 0번째
6번째(4) = 5번째 + 1번째
7번째(5) = 6번째 + 2번째
8번째(7) = 7번째 + 3번째
9번째()

(n >= 5) p[n] = p[n-1] + p[n-5];
*/

#include <iostream>
#include <cstring>
using namespace std;

long long int cache[101];

void calc(int n) {
  cache[1] = 1; cache[2] = 1; cache[3] = 1;
  cache[4] = 2; cache[5] = 2;
  for (int i = 6; i <= n ; i++) cache[i] = cache[i - 1] + cache[i - 5];
}

void print(int n) {
  cout << cache[n] << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  calc(100);

  int cnt;
  cin >> cnt;

  for (int i = 0 ; i < cnt ; i++) {
    int n;
    cin >> n;
    print(n);
  }
}



 