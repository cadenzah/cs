#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int MONTHS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  const string _DAYS[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
  vector<string> DAYS(&_DAYS[0], &_DAYS[7]);

  int month, day;
  cin >> month >> day;

  for (int i = 0 ; i < month - 1 ; i++) {
    // 직전 달까지만 더한다
    day = day + MONTHS[i];
  }

  // 1월 1일은 MON, 1
  cout << DAYS[day % 7];

  return 0;
}
