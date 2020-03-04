#include <string>
#include <vector>
#include <algorithm>

/*
 * H-Index (https://programmers.co.kr/learn/courses/30/lessons/42747)
 * 
 * 이 문제 역시, <가장 큰 수> 문제와 마찬가지로, 정렬을 할 때의 직관이 중요한 문제.
 * 어떤 기준으로 정렬할 건지, 정렬하였을 때 정렬된 결과에 드러나는 의미가 무엇인지.
*/

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    // 내림차순 소트
    sort(citations.begin(), citations.end(), greater<int>());
    
    // n-1부터 순서대로 체크
    for (int i = citations.size() ; i > 0 ; --i) {
        // list[k - 1] >= k 이면, h-index는 k
        if (citations[i - 1] >= i) {
            answer = i;
            // 최대값이므로, 나오는 즉시 break
            break;
        }
        
    }
    
    return answer;
}
