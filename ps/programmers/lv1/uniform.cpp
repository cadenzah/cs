// https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>

using namespace std;

// 체육복이 있는 사람은, 자신의 번호 *바로 앞 또는 바로 뒤* 번호 학생에게만 대여 가능
// 체육복 소지 인원 최대화

// n: 전체 학생 수 (2 <= n <= 30)
// lost: 체육복 받아야 하는 학생들 번호
// reserve: 체육복 주는 학생들 번호

int solution(int n, vector<int> lost, vector<int> reserve) {

    int answer = 0;
    // 전체 명단 - 입력 처리 편리함을 위하여 index=0 사용 X
    vector<int> result(n + 1, 1);

    // 각 학생들이 가지는 체육복 갯수 초기화
    // :: 0개 - 빌려야 함
    for (int i = 0 ; i < lost.size() ; i++) {
        result[lost[i]] = 0;
    }
    // :: 2개 - 빌려줄 수 있음
    for (int i = 0 ; i < reserve.size() ; i++) {
        // 도난 당했다면, 이미 위에서 0개로 초기화됨. 일관성있게 더해주면 됌.
        ++result[reserve[i]];
    }
    // 나머지는 모두 1개

    // i = 0인 경우(맨앞), 바로 뒤에만 체크
    if (result[1] == 2 && result[2] == 0) {
        --result[1];
        ++result[2];
    }

    for (int i = 2 ; i < n ; i++) {
        // 여벌을 가지고 있는 경우
        if (result[i] == 2) {
            // 1. 앞 먼저 체크
            if (result[i - 1] == 0) {
                --result[i];
                ++result[i - 1];
            } else if (result[i + 1] == 0) {
            // 2. 앞에 안 줘도 되면, 뒤에 체크
                --result[i];
                ++result[i + 1];
            }
        }
    }

    // i = n인 경우(맨뒤), 바로 앞에만 체크
    if (result[n] == 2 && result[n - 1] == 0) {
        --result[n];
        ++result[n - 1];
    }

    // result에서 1개 이상인 경우를 모두 체크
    for (int i = 1 ; i <= n ; i++) {
        if (result[i] >= 1) ++answer;
    }

    return answer;
}
