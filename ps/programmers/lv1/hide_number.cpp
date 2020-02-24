// https://programmers.co.kr/learn/courses/30/lessons/12948

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer(phone_number.length() - 4, '*');
    
    // length - 4 ... length - 1
    string revealed = phone_number.substr(phone_number.length() - 4, 4);
    
    return answer + revealed;
}
