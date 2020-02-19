// https://programmers.co.kr/learn/courses/30/lessons/12926

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    int input_length = s.length();
    int new_char = 0;
    string answer = "";
    
    for (int i = 0 ; i < input_length ; i++) {
        // 공백 처리
        if (s[i] == ' ') {
            answer = answer + " ";
            continue;
        }
        
        new_char = s[i] + n;
        
        if (s[i] < 91 && new_char >= 91) {
            new_char = new_char - 26;
        } else if (s[i] < 123 && new_char >= 123) {
            new_char = new_char - 26;
        }
        
        answer = answer + string(1, new_char);
    }
    
    return answer;
}
