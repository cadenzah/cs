// https://programmers.co.kr/learn/courses/30/lessons/12943
// 식이 맞은 듯할 때에는 자료형의 크기를 의심해보자

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long temp = num;
    
    while (answer <= 500) {
        if (temp == 1) return answer;
        
        if (temp % 2 == 0) temp /= 2;
        else temp = temp * 3 + 1;
        
        ++answer;
    }
    return -1;
}
