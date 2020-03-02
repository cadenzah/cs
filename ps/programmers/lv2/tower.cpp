#include <string>
#include <vector>
#include <stack>

using namespace std;

// k번째 수의 크기를 봤을 때
// 내부 while: k-1번째 수보다 크면 => top으로 가져온다
// => k-1번째 값을 빼고, 그 앞에 것과 비교
// 스택이 빌 때까지 반복 => stack이 비어버리면, 0으로 입력
// 
// if: k-1번째 수보다 작으면, k-1번째 값이 송신한 것
// => 해당 k번째 answer로 top값을 입력하고, break(whlie 탈출)

// 답 입력시 인덱스는 1부터 시작함에 유의

vector<int> solution(vector<int> heights) {
    
    vector<int> result;
    stack<pair<int, int>> temp;
    
    // first: 높이, second: 위치
    temp.push(pair<int, int>(heights[0], 1));
    result.push_back(0);
    
    for (int i = 1 ; i < heights.size() ; i++) {
        while(!temp.empty()) {
            if (temp.top().first <= heights[i]) {
                temp.pop();
            } else {
                pair<int, int> answer = temp.top();
                temp.push(pair<int, int>(heights[i], i + 1));
                result.push_back(answer.second);
                break;
            }
        }
        if (temp.empty()) {
            // 제일 높은 탑 새로 등장
            temp.push(pair<int, int>(heights[i], i + 1));
            result.push_back(0);
        }
    }
    
    return result;
}
