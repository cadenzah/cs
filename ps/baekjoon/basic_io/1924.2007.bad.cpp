#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // 2007년 1월 1일은 월요일
  // 2007년 x월 y일은?

  // 2월은 28일까지 있다
  
  // 1월 1일 기준으로 1일씩 더한다
  // 1월 2일은 1(화요일), 1월 3일은 2, ...

  int month_days, days, x, y;
  cin >> x >> y;

  switch(x) {
    case 1: month_days = 0; break;
    case 2: month_days = 31; break;
    case 3: month_days = 59; break;
    case 4: month_days = 90; break;
    case 5: month_days = 120; break;
    case 6: month_days = 151; break;
    case 7: month_days = 181; break;
    case 8: month_days = 212; break;
    case 9: month_days = 243; break;
    case 10: month_days = 273; break;
    case 11: month_days = 304; break;
    case 12: month_days = 334; break;
  }

  days = month_days + y;

  switch(days % 7) {
    case 0: cout << "SUN"; break;
    case 1: cout << "MON"; break;
    case 2: cout << "TUE"; break;
    case 3: cout << "WED"; break;
    case 4: cout << "THU"; break;
    case 5: cout << "FRI"; break;
    case 6: cout << "SAT"; break;
  }

  return 0;
}
