// 첫자리, 셋째자리 바꾼다
#include <iostream>
using namespace std;

int convert(int input) {
  int digit100 = input / 100;
  int digit10 = input / 10 - digit100 * 10;
  int digit1 = input % 10;
  return digit1 * 100 + digit10 * 10 + digit100;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int no1, no2;
  cin >> no1 >> no2;

  no1 = convert(no1);
  no2 = convert(no2);

  if (no1 >= no2) cout << no1;
  else cout << no2;

  return 0;
}
