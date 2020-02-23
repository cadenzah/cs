// https://programmers.co.kr/learn/courses/30/lessons/12901

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    const int MONTH[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    const string DAY[] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int days = 0;
    
    // 1. 날짜를 다 받아서 더하고,
    for (int i = 1 ; i < a ; i++) {
        days += MONTH[i];
    }
    days += b;
    
    // 2. 7로 나눈 나머지를 구해서
    days %= 7;
    
    // 나머지를 인덱스로 DAY 접근
    string answer = DAY[days];
    
    return answer;
}
