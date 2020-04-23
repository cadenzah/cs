#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
1을 쓰거나, 00을 쓰거나, 길이가 n 이하일 떄까지

길이가 k인 새로운 문자열 = 
길이가 k - 1인 직전까지의 것에 1
길이가 k - 2인 직전까지의 것에 00 11 

길이 1 := 1
길이 2 := 11 00

1 11
1 00
1일 때 2개
00일 때 1개

00 1

*/

직전에 놓은 말, 그때까지 길이
countTiles(n) = countTiles()


int cache[1000001];

void countTiles(int n) {
  cache[1] = 1;
  cache[2] = 2;
  for (int i = 3 ; i <= n ; i++) {
    cache[i] = cache[i - 1] + cache[i - 2];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, -1, sizeof(cache));

  int n;
  cin >> n;

  countTiles(n);

  for (int i = 1 ; i <= n ; i++) cout << i << " " << cache[i] << "\n";

}
