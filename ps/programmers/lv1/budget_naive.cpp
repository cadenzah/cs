// https://programmers.co.kr/learn/courses/30/lessons/12982

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// i번째 이후 부서에게 budget을 기반으로 지원할 때 최대로 지원 가능한 부서 개수
int support(vector<int>& d, int i, int budget) {
    // 기저 사례 1: 모든 부서를 다 돌았을 때 (i == d.size()) -> return 0
    if (i == d.size()) return 0;
    // 기저 사례 2: 예산이 바닥났을 때 -> return 0
    if (budget < d[i]) return 0;
    
    // i번째 부서를 지원할 때 / // i번째 부서는 스킵할 때
    return max(1 + support(d, i + 1, budget - d[i]), support(d, i + 1, budget));
}

int solution(vector<int> d, int budget) {
    int answer = support(d, 0, budget);
    return answer;
}
