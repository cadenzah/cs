// https://programmers.co.kr/learn/courses/30/lessons/12912

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    long long int _a = (long long int) a;
    long long int _b = (long long int) b;
    
    answer = (_b * (_b + 1) - _a * (_a - 1)) / 2;
    
    return answer;
}
