#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    return answer;
}

// 단위 길이가 커질수록 더 효율적이다

solution(s, i) : 문자열 s 중에서 i번째 인덱스 이후의 문자열을 압축한 것 중 가장 짧은 것의 길이

패턴 발견시 -> 줄인 패턴 길이 + solution(해당 패턴 뒷부분)
    
    max((패턴 개수) * k + solution(s, i), (패턴 개수 문자열의 길이) + k + solution(s, i + k));
(k는 줄인 패턴들의 길이)

int minZipped(string& s, int k) {
    // solution(s, i) : 문자열 s 중에서 i번째 인덱스 이후의 문자열을 압축한 것 중 가장 짧은 것의 길이
    
}
