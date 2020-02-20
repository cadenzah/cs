// https://programmers.co.kr/learn/courses/30/lessons/12903

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int answer_index = s.length() / 2;

    if (s.length() % 2 == 0) {
        // 짝수
        return s.substr(answer_index - 1, 2);
    } else {
        // 홀수
        return string(1, s[answer_index]);
    }
}
