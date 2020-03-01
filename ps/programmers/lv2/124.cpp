#include <string>
#include <vector>

using namespace std;

// 3진법, 1, 2, 4 순
// 0은 없다 ; 0은 자연수가 아니다..........

// 맨 뒤부터 처리하자
// 3으로 나눈 나머지: k번째 자리수 (124진수)
// 3으로 나눈 몫: k+1 자리수 (왼쪽으로 진행)에 대하여 처리할 10진수

string convert(int decimal) {
    string answer = "";

    // (입력 - 1) 기준으로
    // 0번쨰: 1
    // 1번째: 2
    // 2번째: 4
    while (decimal / 3 != 0 || decimal % 3 != 0) {
        int current_digit = decimal % 3;
        switch (current_digit) {
            case 0: 
                answer = "4" + answer;
                decimal = decimal / 3 - 1;
                break;
            case 1:
                answer = "1" + answer;
                decimal = decimal / 3;
                break;
            case 2:
                answer = "2" + answer;
                decimal = decimal / 3;
                break;
        }
    }

    return answer;
}

string solution(int n) {
    string answer = convert(n);
    return answer;
}
